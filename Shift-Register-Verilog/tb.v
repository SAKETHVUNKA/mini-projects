`timescale 1 ns / 100 ps
`define TESTVECS 5

module tb;
    reg clk;
    reg [7:0] input1;
    reg [1:0] select;
    integer i=0;
    reg [9:0] test_vecs [(`TESTVECS-1):0];
    wire [7:0] output1=0;
    initial begin 
        $dumpfile("project.vcd");
        $dumpvars(0,tb); 
    end
    initial clk = 1'b0; always #5 clk =~ clk;
    initial begin
        test_vecs[0][9:8] = 2'b01;test_vecs[0][7:0] = 8'b00110011;
        test_vecs[1][9:8] = 2'b11;test_vecs[1][7:0] = 8'b00110011;
        test_vecs[2][9:8] = 2'b01;test_vecs[2][7:0] = 8'b00110011;
        test_vecs[3][9:8] = 2'b00;test_vecs[3][7:0] = 8'b00110011;
        test_vecs[4][9:8] = 2'b10;test_vecs[4][7:0] = 8'b00110011;
    end
    initial {clk,select,input1} = 0;
    shiftregister shiftregister1 (clk,select,input1,output1);
    initial begin
        #6 for(i=0;i<`TESTVECS;i=i+1)
            begin #10 {select,input1}=test_vecs[i]; end
        #100 $finish;
    end
endmodule