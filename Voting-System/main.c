#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int voterscounts=0,candidatecount=4;
struct voters
{
char prn[15];
char name[30];
char password[10];
int votecast;
char castparty[10];
}v[100];
struct candidates
{
char partyname[30];
char candidate[30];
int votes;
}c[10];
int viewlists()
{
    printf("\e[1;1H\e[2J");
    int k=0,m=0;
e : printf("If you want to view the list of Voters, press 1.\nIf you want to view the list of Candidates, press 2.\n");
    scanf("%d",&k); printf("\e[1;1H\e[2J");
    if(k==1)
    {
        if(voterscounts==0)
            printf("The Voters list is empty!\nPlease enter the details of Voters in order to view them.\n");
        else
        {
            for(int j=0;j<voterscounts;j++)
            {   
                printf("Name : %s\n PRN : %s\n",v[j].name,v[j].prn);
                printf("\n");
            }
        }
    }
    else if(k==2)
    {
        for(int j=0;j<candidatecount;j++)
        {   
            printf("%d)",j+1);
            printf("     Name    : %s\n",c[j].candidate);
            printf("    Party Name : %s\n",c[j].partyname);
            printf("\n");
        }
    }
    else
    {
        printf("Enter a valid choice.\n");
        goto e;
    }
f : printf("If you want to go back to the main menu, press 1.\n");
    scanf("%d",&m); printf("\e[1;1H\e[2J");
    if(m==1)
    return 1;
    else 
    printf("Enter a valid choice.\n");
    goto f;
}
int listedit()
{
    printf("\e[1;1H\e[2J");
    int k=0,m=0,n1,z1,z2,z3,z4,y;
a : printf("If you want to view the list of Voters before editing, press 1.\nIf you want to directly edit the list, press 2.\n");
    scanf("%d",&k); printf("\e[1;1H\e[2J");
    switch(k)
    {
        case 1:n1=viewlists() ;
        goto l;
        break;
        case 2:goto l;
        break;
        default:printf("Enter a valid choice.\n");
        goto a;
        break;
    }
    int candidateadd()
    {
        printf("\e[1;1H\e[2J");
       printf("Enter the Administrator's password: ");
       char up[20],up1[20];
       scanf("%s",up); printf("\e[1;1H\e[2J");
       FILE *add1;
       add1=fopen("up.txt","r");
       fgets(up1,20,add1);
       if(strcmp(up1,up)!=0)
       {
        printf("Wrong password!\n"); Sleep(3); printf("\e[1;1H\e[2J");
       }
       else if(strcmp(up1,up)==0)
       {
       char candidate[30],partyname[30];
       printf("Enter the Candidate's name: ");
       scanf("%s",candidate); printf("\e[1;1H\e[2J");
       strcpy(c[candidatecount].candidate,candidate);
       printf("Enter the Candidate's party name: ");
       scanf("%s",partyname); printf("\e[1;1H\e[2J");
       strcpy(c[candidatecount].partyname,partyname);
       printf("Candidate's details added successfully!\n"); Sleep(3); printf("\e[1;1H\e[2J");
       candidatecount++;
       c[candidatecount-1].votes=0;
       }
       fclose(add1);
       int readd=0;
       o3 : printf("If you want to go back to the main menu, press 1.\nIf you want to go back to the previous menu, press 2.\n");
       scanf("%d",&readd); printf("\e[1;1H\e[2J");
       switch(readd)
       {
           case 1:return 2;
           break;
           case 2:return 1;
           break;
           default:printf("Enter a valid choice.\n");
           goto o3;
           break;
       }
    }
    int candidatedel()
    {
        printf("\e[1;1H\e[2J");
       char candidate[30],partyname[30];
        int p=candidatecount,readd=0;
        printf("Enter the Administrator's password: ");
       char up[20],up1[20];
       scanf("%s",up); printf("\e[1;1H\e[2J");
       FILE *add1;
       add1=fopen("up.txt","r");
       fgets(up1,20,add1);
       if(strcmp(up1,up)!=0)
       {
        printf("Wrong password!\n"); Sleep(3); printf("\e[1;1H\e[2J");
       }
       else if(strcmp(up1,up)==0)
       {
        printf("Enter the Candidate's name: ");
        scanf("%s",candidate); printf("\e[1;1H\e[2J");
        printf("Enter the Candidate's party name : ");
        scanf("%s",partyname); printf("\e[1;1H\e[2J");
        for(int m=0;m<candidatecount;m++)
        {
            if (strcmp(c[m].candidate,candidate)==0)
            {
                if (strcmp(c[m].partyname,partyname)==0)
                {
                        strcpy(c[m].candidate,"NULL");
                        strcpy(c[m].partyname,"NULL");
                        printf("Candidate removed successfully!\n"); Sleep(3); printf("\e[1;1H\e[2J");
                        for(int i=m;i<candidatecount-1;i++)
                        {
                            c[i]=c[i+1];
                        }
                        candidatecount--;
                }
            }
        }
        if(p==candidatecount)
        {
            printf("Entered details are invalid or the Candidate doesn't exist!\n"); Sleep(3); printf("\e[1;1H\e[2J");
        }
       }
        o1 : printf("If you want to go back to the main menu, press 1.\nIf you want to go back to the previous menu, press 2.\n");
        scanf("%d",&readd); printf("\e[1;1H\e[2J");
        switch(readd)
        {
           case 1:return 2;
           break;
           case 2:return 1;
           break;
           default:printf("Enter a valid choice.\n");
           goto o1;
           break;
        }
    }
    int voteradd()
    {
        printf("\e[1;1H\e[2J");
       printf("Enter the Administrator's password: ");
       char up[20],up1[20];
       scanf("%s",up); printf("\e[1;1H\e[2J");
       FILE *add1;
       add1=fopen("up.txt","r");
       fgets(up1,20,add1);
       if(strcmp(up1,up)!=0)
       {
        printf("Wrong password!\n"); Sleep(3); printf("\e[1;1H\e[2J");
       }
       else if(strcmp(up1,up)==0)
       {
       FILE *p;
       char name[30],prn[15],password[10],add[6]=".txt";
       printf("Enter the Voter's name: ");
       scanf("%s",name); printf("\e[1;1H\e[2J");
       strcpy(v[voterscounts].name,name);
       printf("Enter the Voter's ID Number: ");
       scanf("%s",prn); printf("\e[1;1H\e[2J");
       strcpy(v[voterscounts].prn,prn);
       printf("Enter the Voter's password: ");
       scanf("%s",password); printf("\e[1;1H\e[2J");
       strcat(name,add);
       p=fopen(name,"w");
       fputs(password,p);
       fclose(p);
       printf("Voter's details added successfully!\n"); Sleep(3); printf("\e[1;1H\e[2J");
       voterscounts++;
       }
       fclose(add1);
       int readd=0;
       o : printf("If you want to go back to the main menu, press 1.\nIf you want to go back to the previous menu, press 2.\n");
       scanf("%d",&readd); printf("\e[1;1H\e[2J");
       switch(readd)
       {
           case 1:return 2;
           break;
           case 2:return 1;
           break;
           default:printf("Enter a valid choice.\n");
           goto o;
           break;
       } 
    }
    int voterdel()
    {
        printf("\e[1;1H\e[2J");
        char name[30],prn[15],password[10];
        int p=voterscounts,readd=0;
        printf("Enter the Administrator's password: ");
       char up[20],up1[20];
       scanf("%s",up); printf("\e[1;1H\e[2J");
       FILE *add1;
       add1=fopen("up.txt","r");
       fgets(up1,20,add1);
       if(strcmp(up1,up)!=0)
       {
        printf("Wrong password!\n"); Sleep(3); printf("\e[1;1H\e[2J");
       }
       else if(strcmp(up1,up)==0)
       {
        printf("Enter Voter's ID Number: ");
        scanf("%s",prn); printf("\e[1;1H\e[2J");
        printf("Enter Voter's Name: ");
        scanf("%s",name); printf("\e[1;1H\e[2J");
        printf("Enter Voter's Password: ");
        scanf("%s",password); printf("\e[1;1H\e[2J");
        for(int m=0;m<voterscounts;m++)
        {
            if (strcmp(v[m].prn,prn)==0)
            {
                if (strcmp(v[m].name,name)==0)
                {
                    FILE *f;
                    char pass[10],add[6]=".txt";
                    strcat(name,add);
                    f=fopen(name,"r");
                    fgets(pass,10,f);
                    if (strcmp(pass,password)==0)
                    {
                        strcpy(v[m].name,"NULL");
                        strcpy(v[m].password,"NULL");
                        strcpy(v[m].prn,"NULL");
                        printf("Voter deleted successfully!\n"); Sleep(3); printf("\e[1;1H\e[2J");
                        for(int i=m;i<voterscounts-1;i++)
                        {
                            v[i]=v[i+1];
                        }
                        voterscounts--;
                    }
                }
            }
        }
        if(p==voterscounts)
        {
            printf("Entered details are invalid or the Voter doesn't exist!\n"); Sleep(3); printf("\e[1;1H\e[2J");
        }
       }
        o1 : printf("If you want to go back to the main menu, press 1.\nIf you want to go back to the previous menu, press 2.\n");
        scanf("%d",&readd); printf("\e[1;1H\e[2J");
        switch(readd)
        {
           case 1:return 2;
           break;
           case 2:return 1;
           break;
           default:printf("Enter a valid choice.\n");
           goto o1;
           break;
        }            
    }
l : printf("If you want to add a Voter, press 1.\nIf you want to delete a Voter, press 2.\nIf you want to add a Candidate, press 3.\nIf you want to delete a Candidate, press 4.\n");
    scanf("%d",&m); printf("\e[1;1H\e[2J");
    switch(m)
    {
        case 1:if(voterscounts>99)
        {
            printf("Max limit of Voters reached!\n"); Sleep(3); printf("\e[1;1H\e[2J");
            goto ef;
        }
        z1=voteradd();
        if(z1==2)
        goto ef;
        else if(z1==1)
        goto l;
        break;
        case 2:if(voterscounts==0)
        {
            printf("The Voters' List is empty!\n"); Sleep(3); printf("\e[1;1H\e[2J");
            goto ef;
        }
        z2=voterdel();
        if(z2==2)
        goto ef;
        else if(z2==1)
        goto l;
        break;
        case 3:if(candidatecount>9)
        {
            printf("Max limit of Candidates reached!\n");  Sleep(3); printf("\e[1;1H\e[2J");
            goto ef;
        }
        z3=candidateadd();
        if(z3==2)
        goto ef;
        else if(z3==1)
        goto l;
        break;
        case 4:if(candidatecount==0)
        {
            printf("The Candidates' list is empty!\n"); Sleep(3); printf("\e[1;1H\e[2J");
            goto ef;
        }
        z4=candidatedel();
        if(z4==2)
        goto ef;
        else if(z4==1)
        goto l;
        break;
        default:printf("Enter a valid choice.\n");
        goto l;
        break;
    }
ef : return 1;
}
void results()
{
    int i,j=0,max=0;
    for(i=0;i<candidatecount;i++)
    {
        if(c[i].votes>max)
        {
        max=c[i].votes;
        j=i;
        }
    }
    printf("\e[1;1H\e[2J");
    printf("----------The voting results are as follows----------\n\n");
    printf("The winner of the election is: %s .\nThe winning party is: %s .\n",c[j].candidate,c[j].partyname);
    printf("\n\n\nThank You for using our program. :)\n");
    exit(0);
}
int votingsystem()
{
    printf("\e[1;1H\e[2J");
    printf("Enter the Administrator's password: ");
    char up[20],up1[20];
    scanf("%s",up); printf("\e[1;1H\e[2J");
    FILE *add1;
    add1=fopen("up.txt","r");
    fgets(up1,20,add1);
    if(strcmp(up1,up)!=0)
    {
    printf("Wrong password!\n"); Sleep(3); printf("\e[1;1H\e[2J");
    }
    else if(strcmp(up1,up)==0)
    {
    int k;
    if(voterscounts==0)
    {
        printf("The Voters list is empty! Before initiating the voting process, enter the details of voters.\n"); Sleep(3); printf("\e[1;1H\e[2J");
        return 0;
    }
    if(candidatecount==0)
    {
        printf("The Candidates list is empty! Before initiating the voting process, enter the details of Candidates.\n"); Sleep(3); printf("\e[1;1H\e[2J");
        return 0;
    }
    char prn[15],name[30],password[10],check;
    int votes=0,thevote=0;;
    int ocount,tcount,thcount,e,votedone;
j : printf("Enter your ID Number: ");
    thcount=votes;
    scanf("%s",prn); printf("\e[1;1H\e[2J");
    printf("Enter your Name: ");
    scanf("%s",name); printf("\e[1;1H\e[2J");
    printf("Enter your Password: ");
    scanf("%s",password); printf("\e[1;1H\e[2J");
    votes=0;
    thevote=0;
    for(int m=0;m<voterscounts;m++)
    {
        if (strcmp(v[m].prn,prn)==0)
        {
            if (strcmp(v[m].name,name)==0)
            {
                FILE *f;
                char pass[10],add[6]=".txt";
                strcat(name,add);
                f=fopen(name,"r");
                fgets(pass,10,f);
                if (strcmp(pass,password)==0)
                    {
                        if(v[m].votecast==1)
                        {
                            printf("You have already casted your vote!\n"); Sleep(3); printf("\e[1;1H\e[2J");
                            goto ll;
                        }
                        else
                        {
                        cc :printf("----------Candidates List----------\n");
                            for(int j=0;j<candidatecount;j++)
                            {
                                printf("%d)",j+1);
                                printf("     Name    : %s\n",c[j].candidate);
                                printf("    Party Name : %s\n",c[j].partyname);
                                printf("\n");
                            }
                        cb :printf("Enter your choice by typing the number corresponding to the party you want to vote for: ");
                            scanf("%d",&thevote); printf("\e[1;1H\e[2J");
                            if(thevote<=candidatecount+1)
                            {
                            printf("You have voted for the party : %s.\nTo confirm, press 'y'.\n If not, press 'n'.\n",c[thevote-1].partyname);
                            scanf("%s",&check); printf("\e[1;1H\e[2J");
                            if(check=='y')
                            {
                                printf("Vote casted!\n"); Sleep(3); printf("\e[1;1H\e[2J");    
                                v[m].votecast=1;               
                            }
                            else
                            {
                                goto cc;
                                thevote=0;
                            }
                            }
                            else
                            {
                                printf("Enter a valid choice.");
                                goto cb;
                            }
                            votes=1;
                            c[thevote-1].votes++;
                            printf("\n%d",thevote);
                            strcpy(v[m].castparty,c[thevote-1].partyname);
                            break;
                        }
                    }
            }
        }
    } 
    if (votes==1)
    goto ll;
    else
    {
        printf("Enter a valid choice.\n"); Sleep(3); printf("\e[1;1H\e[2J");
        goto j;
    }
ll: printf("\e[1;1H\e[2J");printf("If you want to cast a vote, press 1.\nIf you want to go back to the main menu, press 2.\nIf you want to end the election and get the results, press 3.\n"); 
    int eee=0;
    scanf("%d",&eee); printf("\e[1;1H\e[2J");
    switch(eee)
    {
        case 1:goto j;
        break;
        case 2:goto z;
        break;
        case 3:{
                    printf("Enter the Administrator's password: ");
                    char up[20],up1[20];
                    scanf("%s",up); printf("\e[1;1H\e[2J");
                    FILE *add1;
                    add1=fopen("up.txt","r");
                    fgets(up1,20,add1);
                    if(strcmp(up1,up)!=0)
                    {
                    printf("Wrong password!\n"); Sleep(3); printf("\e[1;1H\e[2J");
                    break;
                    }
                    else if(strcmp(up1,up)==0)
                    {
                    results();
                    break;
                    }
                }
        printf("Voting completed!\n"); Sleep(3); printf("\e[1;1H\e[2J");
        break;
        default:printf("Enter a valid choice.\n"); 
                goto ll;
                break;
    }
z :return 0;
    }
}
int main()
{
    printf("\e[1;1H\e[2J");
    FILE *up1;
    for(int i=0;i<candidatecount;i++)
    {
        c[i].votes=0;
    }
    strcpy(c[0].partyname,"Ruby");
    strcpy(c[1].partyname,"Emerald");
    strcpy(c[2].partyname,"Pearl");
    strcpy(c[3].partyname,"Sapphire");
    strcpy(c[0].candidate,"Srikhar");
    strcpy(c[1].candidate,"Naveen");
    strcpy(c[2].candidate,"Yasir");
    strcpy(c[3].candidate,"Nischith");
    int a,n=1,b1,b2,b3,j;
    int votercount=0;
    char up[20];
    printf("Enter the Administrator's password: ");
    scanf("%s",up); printf("\e[1;1H\e[2J");
    up1=fopen("up.txt","w");
    fputs(up,up1);
    fclose(up1);
    strcpy(up,"NULL");
    while(n)
    {
zz :printf("If you want to edit the list of Voters or list of Candidates, press 1.\nIf you want to view the Voters or Candidates list, press 2.\nIf you want to start the election, press 3.\n");
    scanf("%d",&a); printf("\e[1;1H\e[2J");
    if(a==1)
    b1=listedit();
    else if(a==2)
    b2=viewlists();
    else if(a==3)
    {
        b3=votingsystem();
        z : printf("If you want to exit, press 1.\nIf you want to continue, press 2.\nIf you want to go to the main menu, press 3.\n");
        scanf("%d",&j); printf("\e[1;1H\e[2J");
        if(j==1)
        break;
        else if(j==2)
        goto z;
        else if(j==3)
        goto zz;
        else
        {
        printf("Enter a valid choice.\n"); 
        goto z;
        }
    }
    else
    {
    printf("Enter a valid choice.\n");
    goto zz;
    }
    }
    return 0;
}