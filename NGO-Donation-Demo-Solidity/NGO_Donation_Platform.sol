//SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;

contract NGO_DONATION_PLATFORM{
    uint private conversionRate = 0.00000381 * 1000000000000000000;
    
    struct Donor {
        string username;
        string password;
        address cryptoAccount;
        bool registered;
    }
    mapping(string => Donor) private donors;

    struct NGO {
        string name;
        string governmentID;
        address cryptoAccount;
        string bankAccount;
        string password;
        uint256 balance;
        bool isValid;
        uint256 totalIssues;
        bool registered;
        mapping(uint256 => string) issues;
    }
    struct NGOInfo {
        string name;
        string governmentID;
    }
    string[] private blacklist;
    string[] private ngos;
    mapping(string => NGO) private NGOs;

    struct Donation {
        string donor;
        string ngo;
        uint256 ethers;
        uint256 realWorldCurrency;
        uint256 transactionId;
        uint256 blockNumber;
        uint256 dateTime;
    }
    Donation[] private donations;
    mapping(string => Donation[]) private donorDonations;
    mapping(string => Donation[]) private ngoDonations;

    //money to crypto 
    function setConversionRate(uint _newRate) external {
        conversionRate = _newRate;
        //in real-world we can use data streams from oracles like chain link to get real time conversion rates
    }
    function convertToCrypto(string memory donorName, string memory donorPassword, uint _amountINR) external payable {
        require(_amountINR > 0, "Amount must be greater than zero");
        require(verifyCredentials(donorName, donorPassword),"Invalid credentials");
        uint equivalentWei = _amountINR * conversionRate;
        payable(donors[donorName].cryptoAccount).transfer(equivalentWei);
    }

    //donor
    function signUp(string memory _username, string memory _password, address _cryptoAccount) public {
        require(bytes(_username).length > 0, "Username cannot be empty");
        require(bytes(_password).length > 0, "Password cannot be empty");
        require(_cryptoAccount != address(0), "Invalid crypto account address");
        require(!donors[_username].registered, "Username registered");
        
        donors[_username] = Donor({
            username: _username,
            password: _password,
            cryptoAccount: _cryptoAccount,
            registered: true
        });
    }
    function verifyCredentials(string memory _username, string memory _password) private view returns (bool) {
        require(donors[_username].registered, "Username not registered");
        require(keccak256(bytes(donors[_username].password)) == keccak256(bytes(_password)), "Wrong password");
        return true;
    }
    function getDonorCryptoAccount(string memory _username) private view returns (address) {
        require(donors[_username].registered, "Invalid username ID");
        return donors[_username].cryptoAccount;
    }

    //ngo's
    function registerNGO(string memory _name, string memory _governmentID, address _cryptoAccount, string memory _bankAccount, string memory _password) external {
        require(!NGOs[_governmentID].registered, "NGO registered");
        require(verifyNGO(_governmentID), "NGO not valid");

        NGO storage ngo = NGOs[_governmentID];
        ngo.name = _name;
        ngo.governmentID = _governmentID;
        ngo.cryptoAccount = _cryptoAccount;
        ngo.bankAccount = _bankAccount;
        ngo.password = _password;
        ngo.isValid = true;
        ngo.totalIssues = 0;
        ngo.registered = true;
        ngos.push(NGOs[_governmentID].governmentID);
    }
    function checkBalance(string memory _governmentID) external view returns (uint256) {
        require(NGOs[_governmentID].isValid, "NGO not registered");
        return NGOs[_governmentID].cryptoAccount.balance;
    }
    function fileIssue(string memory _governmentID, string memory _issue) external  {
        NGOs[_governmentID].totalIssues++;
        NGOs[_governmentID].issues[NGOs[_governmentID].totalIssues] = _issue;
        if(NGOs[_governmentID].totalIssues > 0){
            blacklist.push(_governmentID);
            NGOs[_governmentID].isValid = false;
        }
    }
    function getNGOIssues(string memory _governmentID) external view returns (string[] memory) {
        string[] memory ngoIssues = new string[](NGOs[_governmentID].totalIssues);
        for (uint256 i = 1; i <= NGOs[_governmentID].totalIssues; i++) {
            ngoIssues[i - 1] = NGOs[_governmentID].issues[i];
        }
        return ngoIssues;
    }
    function verifyNGO(string memory _governmentID) private pure returns (bool) {
        return true;
        // in real world we can make use of a custom api to scrape data from government website and fetch info related to ngo's in realtime and then verify and confirm their authenticity
    }
    function check_status_NGO(string memory _governmentID) private view returns (bool) {
        return NGOs[_governmentID].isValid;
    }
    function resolveIssue(string memory _governmentID, uint256 _issueIndex, string memory _reason) external {
        require(_issueIndex >= 0 && _issueIndex <= NGOs[_governmentID].totalIssues, "Invalid issue index");
        NGOs[_governmentID].issues[_issueIndex] = _reason;
        NGOs[_governmentID].totalIssues -= 1;
        // blacklist[_issueIndex] = blacklist[blacklist.length - 1];
        blacklist.pop();
        if(NGOs[_governmentID].totalIssues == 0){
            NGOs[_governmentID].isValid = true;
        }
    }
    function getAllNGOs() external view returns (NGOInfo[] memory) {
        uint256 ngoCount = 0;
        for (uint256 i = 0; i < ngos.length; i++) {
            if (NGOs[ngos[i]].isValid) {
                ngoCount++;
            }
        }
        NGOInfo[] memory allNGOs = new NGOInfo[](ngoCount);
        uint256 index = 0;
        for (uint256 i = 0; i < ngos.length; i++) {
            string memory govID = ngos[i];
            if (NGOs[govID].isValid) {
                allNGOs[index] = NGOInfo({
                    name: NGOs[govID].name,
                    governmentID: NGOs[govID].governmentID
                });
                index++;
            }
        }
        return allNGOs;
    }

    //transactions
    function getContractBalance() external view returns (uint256) {
        return address(this).balance;
    }
    function getDonorDonations(string memory _donor) external view returns (Donation[] memory) {
        return donorDonations[_donor];
    }
    function getNGODonations(string memory _ngo) external view returns (Donation[] memory) {
        return ngoDonations[_ngo];
    }
    function donateToNGO(string memory _ngoGovernmentID, string memory _donorUsername, string memory _donorPassword, uint256 _amountINR) external payable {
        require(check_status_NGO(_ngoGovernmentID), "NGO not valid");
        require(verifyCredentials(_donorUsername, _donorPassword),"Invalid Credentials");
        uint256 equivalentETH = _amountINR * conversionRate;
        payable(NGOs[_ngoGovernmentID].cryptoAccount).transfer(equivalentETH);
        Donation memory newDonation = Donation(_donorUsername, _ngoGovernmentID, equivalentETH, _amountINR, 0, block.number, block.timestamp);
        donations.push(newDonation);
        donorDonations[_donorUsername].push(newDonation);
        ngoDonations[_ngoGovernmentID].push(newDonation);
        // in real world code we can access the real transaction id of the ether transfer and then store it for future reference
    }
}

//donor1,donor1,0x5B38Da6a701c568545dCfcB03FcB875f56beddC4
//ngo1,ngo1,0x17F6AD8Ef982297579C203069C1DbfFE4348c372,acc1,ngo1
//donor1,donor1,100