/*
DIBUAT OLEH : OCTARA PRIBADI
UNTUK MATA KULIAH KEAMANAN KOMPUTER
KRIPTOGRAFI SIMETRIS DES(DATA ENCRYPTION STANDARD)
STMIK TIME MEDAN
JLN MERBABU NO 32AA-BB
WWW.STMIK-TIME.AC.ID
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<bitset>
#include<cstdlib>
#define clrscr() system("cls")

using namespace std;

string hex2bin(string hex){
char i;
string biner;
for(i=0;i<=hex.length()-1;i++){
 switch(hex[i]){
  case '0' : biner=biner+"0000";break;
  case '1' : biner=biner+"0001";break;
  case '2' : biner=biner+"0010";break;
  case '3' : biner=biner+"0011";break;
  case '4' : biner=biner+"0100";break;
  case '5' : biner=biner+"0101";break;
  case '6' : biner=biner+"0110";break;
  case '7' : biner=biner+"0111";break;
  case '8' : biner=biner+"1000";break;
  case '9' : biner=biner+"1001";break;
  case 'A' : biner=biner+"1010";break;
  case 'B' : biner=biner+"1011";break;
  case 'C' : biner=biner+"1100";break;
  case 'D' : biner=biner+"1101";break;
  case 'E' : biner=biner+"1110";break;
  case 'F' : biner=biner+"1111";break;
 }
}
return biner;
}

string dec2bin(unsigned char desimal){
 if(desimal==0)return "0";
 if(desimal==1)return "1";
 if(desimal%2==0)
  return dec2bin(desimal/2)+"0";
 else
  return dec2bin(desimal/2)+"1"; 
}

unsigned char bin2dec(string input){
 char i,panjang,x;
 unsigned char hasil=0;
 string bantu;
 panjang=input.length();
 for(i=panjang-1;i>=0;i--){
  bantu=bantu+input[i];
 }
 for(i=0;i<=panjang-1;i++){
  x=bantu[i];
  if(x=='1')
  hasil=hasil+(1<<i);
  //printf("%i\n",hasil);
 }
 return hasil;
}

string format_digit(string biner,unsigned char digit){
 char i,a;
 a=biner.size();
 for(i=0;i<digit-a;i++) biner="0"+biner;
return biner;
}

string plain2bin(string plain){
 string biner;
 char i;
 for(i=0;i<=plain.length()-1;i++){
  biner=biner+format_digit(dec2bin(plain[i]),8);
 }
 return biner;
}

string ip(string biner){
 unsigned char tbl_ip[] =	{
						58,	50,	42,	34,	26,	18,	10,	2,
						60,	52,	44,	36,	28,	20,	12,	4,
						62,	54,	46,	38,	30,	22,	14,	6,
						64,	56,	48,	40,	32,	24,	16,	8,
						57,	49,	41,	33,	25,	17,	9,	1,
						59,	51,	43,	35,	27,	19,	11,	3,
						61,	53,	45,	37,	29,	21,	13,	5,
						63,	55,	47,	39,	31,	23,	15,	7
						};
 string biner2;
 char i=0;
 for(i;i<=63;i++){
  biner2=biner2+biner[tbl_ip[i]-1];
 }
 return biner2;
}

string pc1(string biner){
 unsigned char tbl_pc1[]=	{
							57,	49,	41,	33,	25,	17,	9,
							1,	58,	50,	42,	34,	26,	18,
							10,	2,	59,	51,	43,	35,	27,
							19,	11,	3,	60,	52,	44,	36,
							63,	55,	47,	39,	31,	23,	15,
							7,	62,	54,	46,	38,	30,	22,
							14,	6,	61,	53,	45,	37,	29,
							21,	13,	5,	28,	20,	12,	4
						};
 string biner2;
 char i=0;
 for(i;i<=55;i++){
  biner2=biner2+biner[tbl_pc1[i]-1];
 }
 return biner2;			
}						

string pc2(string biner){
 unsigned char tbl_pc2[]=	{
							14,	17,	11,	24,	1,	5,
							3,	28,	15,	6,	21,	10,
							23,	19,	12,	4,	26,	8,
							16,	7,	27,	20,	13,	2,
							41,	52,	31,	37,	47,	55,
							30,	40,	51,	45,	33,	48,
							44,	49,	39,	56,	34,	53,
							46,	42,	50,	36,	29,	32
							};
 string biner2;
 char i=0;
 for(i;i<=47;i++){
  biner2=biner2+biner[tbl_pc2[i]-1];
 }
  return biner2;
 }

char leftshift(string *data){
 char i,tbl_shift[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
 for(i=1;i<=16;i++){
  if(tbl_shift[i-1]==1){
   data[i]=data[i-1].substr(1,27)+data[i-1].substr(0,1);
   }
  else{
   data[i]=data[i-1].substr(2,26)+data[i-1].substr(0,2);
   }
  }
 return 0;
}

string buang_spasi(string input){
 unsigned char panjang=input.length(),i;
 string tampung("");
 for(i=0;i<panjang;i++){
  if(input[i]!=' '&&input[i]!='\t'&&input[i]!='\n')
  tampung=tampung+input[i];
 }
 return tampung;
}

unsigned char cek_hexa(string input){
 unsigned char i,panjang=input.length();
 
 for(i=0;i<panjang;i++){
  if(isxdigit(input[i])==0) return 0;
 }
 return 1;
}

string format_hexa(string input){
 unsigned char i,panjang=input.length();
 for(i=0;i<panjang;i++){
  input[i]=toupper(input[i]); 
 }
 return input;
}

string pe(string biner){
 unsigned char tbl_pe[]=	{
							32,	1,	2,	3,	4,	5,
							4,	5,	6,	7,	8,	9,
							8,	9,	10,	11,	12,	13,
							12,	13,	14,	15,	16,	17,
							16,	17,	18,	19,	20,	21,
							20,	21,	22,	23,	24,	25,
							24,	25,	26,	27,	28,	29,
							28,	29,	30,	31,	32,	1
							};
 string biner2;
 char i=0;
 for(i;i<=47;i++){
  biner2=biner2+biner[tbl_pe[i]-1];
 }
  return biner2;							
}

string ex_or(string r,string k){
 char i,x;
 string output;
 for(i=0;i<=r.length()-1;i++){
  x=r[i]^k[i];
  if(x==1)
   output=output+"1";
  else
   output=output+"0";         
 }
 return output;
}

string sbox(string input){
 char i,j=0,position,nilai;
 string b,s[8],output,left,up;
 unsigned char tbl_sbox[][64]=
 { 
  {
  14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
  0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
  4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
  15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
  },
  { 
  15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
  3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
  0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
  13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
  },
  {
  10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
  13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
  13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
  1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12                                     
  },
  {
  7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
  13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
  10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
  3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14                                
  },
  {
  2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
  14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
  4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
  11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3                                     
  },
  {
  12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
  10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
  9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
  4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13                                    
  },
  {
  4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
  13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
  1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
  6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12                                     
  },
  {
  13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
  1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
  7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
  2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11                                    
  }
 };
 for(i=0;i<=7;i++){
  s[i]=input.substr(j,6);
  j=j+6;
 }

 for(i=0;i<=7;i++){
  left=s[i].substr(0,1)+s[i].substr(5,1);
  up=s[i].substr(1,4);
  position=16*bin2dec(left)+bin2dec(up);
  nilai=tbl_sbox[i][position];
  output=output+ format_digit(dec2bin(nilai),4);
 }
 return output;
}

string pbox(string biner){
 unsigned char tbl_pbox[]=	{
							16,7,20,21,29,12,28,17,
							1,15,23,26,5,18,31,10,
							2,8,24,14,32,27,3,9,
							19,13,30,6,22,11,4,25
							};
 string biner2;
 char i=0;
 for(i;i<=31;i++){
  biner2=biner2+biner[tbl_pbox[i]-1];
 }
  return biner2;							
}

string invers_ip(string biner){
 unsigned char tbl_invers[]=	{
40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25
							};
 string biner2;
 char i=0;
 for(i;i<=biner.length()-1;i++){
  biner2=biner2+biner[tbl_invers[i]-1];
 }
  return biner2;							
}

int main(){


string l[17],r[17],c[17],d[17],e[16],plain,key,plain_biner,key_biner,k[17],a[16],b[16],pb[16],RL;
int i;

do{
clrscr();
cin.sync();//bersihkan buffering dari cin
cout<<"Masukan Plaintext (8 DIGIT)\t=";getline(cin,plain);
cout<<"Masukan Kunci (16  hexa DIGIT)\t=";getline(cin,key);
key=buang_spasi(key);
key=format_hexa(key);
}while(plain.length()!=8 || key.length()!=16||cek_hexa(key)!=1);
cout<<endl;

//plain="KINGKONG";
//key="133457799BBCDFF1";

clrscr();
cout<<"plain\t= "<<plain<<endl<<"key\t= "<<key<<endl<<endl;

//ubah plaintext ke biner
plain_biner=plain2bin(plain);
cout<<"plain=\t"<<plain_biner<<endl;

//ubah key hexa ke biner
key_biner=hex2bin(key);
cout<<"key=\t"<<key_biner<<endl;

//lakukan initial permutation pada plaintext kemudian pecah menjadi l0 dan r0
l[0]=ip(plain_biner).substr(0,32);
r[0]=ip(plain_biner).substr(32,32);
cout<<"L0=\t"<<l[0]<<endl<<"R0=\t"<<r[0]<<endl;

//lakukan permutation-compression 1 pada key kemudian pecah menjadi c0 dan d0
c[0]=pc1(key_biner).substr(0,28);
d[0]=pc1(key_biner).substr(28,28);
cout<<"C0=\t"<<c[0]<<endl<<"D0=\t"<<d[0]<<endl;

//leftshift pada c0 dan d0
leftshift(c);
leftshift(d);

for(i=1;i<=16;i++) cout	<<"c["<<i<<"]=\t"<<c[i]<<endl
						<<"d["<<i<<"]=\t"<<d[i]<<endl<<endl;
						
//permutation compression-2 pada CiDi menghasilkan Ki
for(i=1;i<=16;i++) {
k[i]=pc2(c[i]+d[i]);
e[i-1]=pe(r[i-1]);
a[i-1]=ex_or(e[i-1],k[i]);
b[i-1]=sbox(a[i-1]);
pb[i-1]=pbox(b[i-1]);
l[i]=r[i-1];
r[i]=ex_or(l[i-1],pb[i-1]);


cout<<"Putaran ke -"<<i<<endl;
cout<<"K["<<i<<"]=\t"<<k[i]<<endl;
cout<<"e["<<i<<"]=\t"<<e[i-1]<<endl;
cout<<"----------------------------------------------------------XOR"<<endl;
cout<<"a["<<i<<"]=\t"<<a[i-1]<<endl<<endl;
cout<<"b["<<i<<"]=\t"<<b[i-1]<<endl;
cout<<"pb["<<i<<"]=\t"<<pb[i-1]<<endl;
cout<<"l["<<i-1<<"]=\t"<<l[i-1]<<endl;
cout<<"----------------------------------------------------------XOR"<<endl;
cout<<"r["<<i<<"]=\t"<<r[i]<<endl<<endl;
}

cout<<"l["<<16<<"]=\t"<<r[15]<<endl<<endl;

RL=r[16]+l[16];
cout<<"RL[16] = "<<RL<<endl<<endl;

RL=invers_ip(RL);
cout<<"IP^-1(RL[16]) = "<<RL<<endl;

//ubah biner ke hexa

cout<<"Ciphertext = ";
for(i=0;i<=63;i+=4){

    string binary_str(RL.substr(i,4));
    bitset<8> set(binary_str);  
    cout << hex << set.to_ulong();
}
cout<<endl;

cin.get();
return 0;
}
