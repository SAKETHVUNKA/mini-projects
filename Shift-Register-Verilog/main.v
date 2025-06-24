module df_8(input wire clk,input wire [7:0] in,output wire [7:0] o);
// initial begin
//         $monitor(o[0],o[1],o[2],o[3],o[4],o[5],o[6],o[7]);
// end
df d1(clk,in[0],o[7]);
df d2(clk,in[1],o[6]);
df d3(clk,in[2],o[5]);
df d4(clk,in[3],o[4]);
df d5(clk,in[4],o[3]);
df d6(clk,in[5],o[2]);
df d7(clk,in[6],o[1]);
df d8(clk,in[7],o[0]);
endmodule

module mux4 (input wire [0:3] i, input wire j1, j0, output wire o);
  wire  t0, t1;
    // initial begin
    //     $display(j1,j0,i[0],i[1],i[2],i[3]);
    // end  
  mux2 mux2_0 (i[0], i[1], j1, t0);
  mux2 mux2_1 (i[2], i[3], j1, t1);
  mux2 mux2_2 (t0, t1, j0, o);
endmodule

module df (input wire clk, in, output wire out);
  reg df_out;
  always@(posedge clk) df_out <= in;
  assign out = df_out;
endmodule

module mux2 (input wire i0, i1, j, output wire o);
  assign o = (j==0)?i0:i1;
endmodule

module shiftregister (input wire clk,input wire [1:0] select,input wire [7:0] input1,output wire [7:0] output1);
    wire i=0;
    wire r1=0,r2=0,r3=0,r4=0,r5=0,r6=0,r7=0,r0=0;
    // initial begin
    //     $monitor(input1[0],input1[1],input1[2],input1[3],input1[4],input1[5],input1[6],input1[7]);
    // end
    mux4 m1({i,input1[1],input1[0],i},select[1],select[0],r0);
    mux4 m2({input1[0],input1[2],input1[1],i},select[1],select[0],r1);
    mux4 m3({input1[1],input1[3],input1[2],i},select[1],select[0],r2);
    mux4 m4({input1[2],input1[4],input1[3],i},select[1],select[0],r3);
    mux4 m5({input1[3],input1[5],input1[4],i},select[1],select[0],r4);
    mux4 m6({input1[4],input1[6],input1[5],i},select[1],select[0],r5);
    mux4 m7({input1[5],input1[7],input1[6],i},select[1],select[0],r6);
    mux4 m8({input1[6],i,input1[7],i},select[1],select[0],r7);

    df_8 df1(clk,{r0,r1,r2,r3,r4,r5,r6,r7},output1);
endmodule