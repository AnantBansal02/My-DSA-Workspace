`include "pipe2.v"
module pipe2tb();
reg clk1,clk2;
reg [3:0] rs1,rs2,rd,func;
reg [7:0] addr;
wire [15:0] zout;
integer k,i;
pipeline obj(zout,rs1,rs2,rd,func,addr,clk1,clk2);
initial clk1=0;
initial clk2=0;
always #10 clk1=~clk1;
always #10 clk2=~clk2;
initial
for(k=0;k<15;k++)
begin
obj.regbank[k]=k;
end
initial begin
$dumpfile("abc.vcd");
$dumpvars;
#20 rs1=6; rs2=1; rd=10; addr= 125; k=addr; func = 2;
for(i=0;i<17;i++)
begin
$display(obj.regbank[i]);
end
#20 rs1=9; rs2=8; rd=12; addr= 126;k=addr; func = 3;
#20 rs1=2; rs2=4; rd=13; addr= 125;k=addr; func = 4;
#60 $finish ;
end
endmodule