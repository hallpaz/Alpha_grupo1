//---------------------------------------------------------------------------

#include "Alpha.h"


/*static unsigned char  SBox(char x,  char y){
    register unsigned char SBoxRtn[16][16] = {
      {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
      {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
      {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
      {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
      {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
      {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
      {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
      {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
      {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
      {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
      {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
      {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
      {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
      {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
      {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
      {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}
   };

  return (SBoxRtn[x][y]);
}
*/
void  N_alpha(unsigned char* xy, unsigned char delta_linha){//byte xy e o que sera substituido por zw
 int lin,col;
 //unsigned char valor;
 register unsigned char BS_decimal[16][16] = {
{99,124,119,123,242,107,111,197,48,1,103,43,254,215,171,118},
{202,130,201,125,250,89,71,240,173,212,162,175,156,164,114,192},
{183,253,147,38,54,63,247,204,52,165,229,241,113,216,49,21},
{4,199,35,195,24,150,5,154,7,18,128,226,235,39,178,117},
{9,131,44,26,27,110,90,160,82,59,214,179,41,227,47,132},
{83,209,0,237,32,252,177,91,106,203,190,57,74,76,88,207},
{208,239,170,251,67,77,51,133,69,249,2,127,80,60,159,168},
{81,163,64,143,146,157,56,245,188,182,218,33,16,255,243,210},
{205,12,19,236,95,151,68,23,196,167,126,61,100,93,25,115},
{96,129,79,220,34,42,144,136,70,238,184,20,222,94,11,219},
{224,50,58,10,73,6,36,92,194,211,172,98,145,149,228,121},
{231,200,55,109,141,213,78,169,108,86,244,234,101,122,174,8},
{186,120,37,46,28,166,180,198,232,221,116,31,75,189,139,138},
{112,62,181,102,72,3,246,14,97,53,87,185,134,193,29,158},
{225,248,152,17,105,217,142,148,155,30,135,233,206,85,40,223},
{140,161,137,13,191,230,66,104,65,153,45,15,176,84,187,22},
};
lin =(((*xy)>>4) + (delta_linha))%16;
col=((*xy)&0xF);//calcula coluna de entrada na caixa  (caso hexa)
*xy = BS_decimal[lin][col];

}// ******************** fim do metodo SUBSTITUICAO *********************

/****************************************************
 **********      metodo L_alpha                ******
 **********   obs: foi implementado bit a bit        ******
 **********  argumento = int[64] binario             ******
 **********   retorna = int[64] binario              ******
 *********************************************************/
/*
//Ver o que eh mais rapido: transformar p/ matriz ou ficar dando shift
 void  L_alpha(unsigned char* e,unsigned char* s){//
 s[20] = ( e[62] ^ e[47] ^ e[11] ^ e[4] ^ e[30] ^ e[61] ^ e[52]) & 1;
 s[47] = ( e[20] ^ e[35] ^ e[45] ^ e[29] ^ e[18] ^ e[34] ^ e[53]) & 1;
 s[11] = ( e[20] ^ e[10] ^ e[59] ^ e[3] ^ e[16] ^ e[57] ^ e[51]) & 1;
 s[4] = ( e[20] ^ e[40] ^ e[7] ^ e[32] ^ e[24] ^ e[8] ^ e[31]) & 1;
 s[30] = ( e[20] ^ e[22] ^ e[37] ^ e[9] ^ e[54] ^ e[2] ^ e[44]) & 1;
 s[61] = ( e[20] ^ e[60] ^ e[1] ^ e[38] ^ e[46] ^ e[50] ^ e[63]) & 1;
 s[52] = ( e[20] ^ e[19] ^ e[25] ^ e[15] ^ e[5] ^ e[56] ^ e[43]) & 1;
 s[35] = ( e[47] ^ e[28] ^ e[36] ^ e[21] ^ e[14] ^ e[48] ^ e[41]) & 1;
 s[45] = ( e[47] ^ e[49] ^ e[27] ^ e[0] ^ e[33] ^ e[13] ^ e[17]) & 1;
 s[29] = ( e[47] ^ e[58] ^ e[39] ^ e[12] ^ e[23] ^ e[26] ^ e[6]) & 1;
 s[18] = ( e[47] ^ e[55] ^ e[42] ^ e[62] ^ e[37] ^ e[5] ^ e[53]) & 1;
 s[34] = ( e[47] ^ e[8] ^ e[14] ^ e[3] ^ e[63] ^ e[50] ^ e[32]) & 1;
 s[53] = ( e[47] ^ e[15] ^ e[48] ^ e[60] ^ e[2] ^ e[33] ^ e[22]) & 1;
 s[10] = ( e[11] ^ e[59] ^ e[12] ^ e[38] ^ e[55] ^ e[1] ^ e[23]) & 1;
 s[59] = ( e[11] ^ e[56] ^ e[0] ^ e[49] ^ e[9] ^ e[39] ^ e[19]) & 1;
 s[3] = ( e[11] ^ e[6] ^ e[57] ^ e[51] ^ e[13] ^ e[34] ^ e[43]) & 1;
 s[16] = ( e[11] ^ e[7] ^ e[36] ^ e[17] ^ e[24] ^ e[58] ^ e[54]) & 1;
 s[57] = ( e[11] ^ e[10] ^ e[31] ^ e[32] ^ e[42] ^ e[21] ^ e[63]) & 1;
 s[51] = ( e[11] ^ e[55] ^ e[12] ^ e[2] ^ e[40] ^ e[26] ^ e[9]) & 1;
 s[40] = ( e[4] ^ e[33] ^ e[49] ^ e[16] ^ e[60] ^ e[3] ^ e[62]) & 1;
 s[7] = ( e[4] ^ e[53] ^ e[25] ^ e[38] ^ e[23] ^ e[14] ^ e[1]) & 1;
 s[32] = ( e[4] ^ e[46] ^ e[56] ^ e[27] ^ e[6] ^ e[39] ^ e[51]) & 1;
 s[24] = ( e[4] ^ e[15] ^ e[21] ^ e[41] ^ e[28] ^ e[50] ^ e[44]) & 1;
 s[8] = ( e[4] ^ e[36] ^ e[5] ^ e[16] ^ e[59] ^ e[10] ^ e[17]) & 1;
 s[31] = ( e[4] ^ e[25] ^ e[58] ^ e[37] ^ e[48] ^ e[0] ^ e[13]) & 1;
 s[22] = ( e[30] ^ e[44] ^ e[19] ^ e[34] ^ e[7] ^ e[8] ^ e[57]) & 1;
 s[37] = ( e[30] ^ e[40] ^ e[54] ^ e[27] ^ e[41] ^ e[9] ^ e[60]) & 1;
 s[9] = ( e[30] ^ e[26] ^ e[5] ^ e[48] ^ e[38] ^ e[49] ^ e[12]) & 1;
 s[54] = ( e[30] ^ e[58] ^ e[1] ^ e[33] ^ e[17] ^ e[31] ^ e[46]) & 1;
 s[2] = ( e[30] ^ e[22] ^ e[28] ^ e[3] ^ e[13] ^ e[56] ^ e[42]) & 1;
 s[44] = ( e[30] ^ e[36] ^ e[53] ^ e[16] ^ e[63] ^ e[43] ^ e[14]) & 1;
 s[60] = ( e[61] ^ e[19] ^ e[55] ^ e[32] ^ e[24] ^ e[0] ^ e[62]) & 1;
 s[1] = ( e[61] ^ e[37] ^ e[21] ^ e[10] ^ e[54] ^ e[41] ^ e[25]) & 1;
 s[38] = ( e[61] ^ e[2] ^ e[57] ^ e[34] ^ e[7] ^ e[15] ^ e[51]) & 1;
 s[46] = ( e[61] ^ e[27] ^ e[44] ^ e[23] ^ e[39] ^ e[42] ^ e[22]) & 1;
 s[50] = ( e[61] ^ e[24] ^ e[6] ^ e[59] ^ e[8] ^ e[32] ^ e[14]) & 1;
 s[63] = ( e[61] ^ e[60] ^ e[40] ^ e[16] ^ e[25] ^ e[0] ^ e[54]) & 1;
 s[19] = ( e[52] ^ e[50] ^ e[2] ^ e[63] ^ e[37] ^ e[13] ^ e[43]) & 1;
 s[25] = ( e[52] ^ e[22] ^ e[28] ^ e[53] ^ e[9] ^ e[59] ^ e[31]) & 1;
 s[15] = ( e[52] ^ e[46] ^ e[39] ^ e[18] ^ e[55] ^ e[6] ^ e[8]) & 1;
 s[5] = ( e[52] ^ e[23] ^ e[33] ^ e[49] ^ e[58] ^ e[7] ^ e[26]) & 1;
 s[56] = ( e[52] ^ e[41] ^ e[1] ^ e[57] ^ e[27] ^ e[36] ^ e[19]) & 1;
 s[43] = ( e[52] ^ e[44] ^ e[51] ^ e[12] ^ e[42] ^ e[62] ^ e[21]) & 1;
 s[28] = ( e[35] ^ e[34] ^ e[31] ^ e[3] ^ e[48] ^ e[10] ^ e[46]) & 1;
 s[36] = ( e[35] ^ e[5] ^ e[50] ^ e[38] ^ e[15] ^ e[26] ^ e[17]) & 1;
 s[21] = ( e[35] ^ e[56] ^ e[18] ^ e[39] ^ e[57] ^ e[53] ^ e[24]) & 1;
 s[14] = ( e[35] ^ e[1] ^ e[12] ^ e[43] ^ e[8] ^ e[59] ^ e[40]) & 1;
 s[48] = ( e[35] ^ e[28] ^ e[7] ^ e[23] ^ e[49] ^ e[37] ^ e[42]) & 1;
 s[41] = ( e[35] ^ e[10] ^ e[0] ^ e[51] ^ e[25] ^ e[34] ^ e[16]) & 1;
 s[49] = ( e[45] ^ e[62] ^ e[17] ^ e[5] ^ e[50] ^ e[31] ^ e[58]) & 1;
 s[27] = ( e[45] ^ e[13] ^ e[44] ^ e[36] ^ e[22] ^ e[38] ^ e[60]) & 1;
 s[0] = ( e[45] ^ e[43] ^ e[9] ^ e[2] ^ e[48] ^ e[26] ^ e[33]) & 1;
 s[33] = ( e[45] ^ e[6] ^ e[55] ^ e[19] ^ e[28] ^ e[41] ^ e[63]) & 1;
 s[13] = ( e[45] ^ e[14] ^ e[24] ^ e[32] ^ e[40] ^ e[54] ^ e[21]) & 1;
 s[17] = ( e[45] ^ e[15] ^ e[3] ^ e[56] ^ e[18] ^ e[46] ^ e[5]) & 1;
 s[58] = ( e[29] ^ e[60] ^ e[27] ^ e[13] ^ e[34] ^ e[49] ^ e[15]) & 1;
 s[39] = ( e[29] ^ e[42] ^ e[17] ^ e[3] ^ e[59] ^ e[26] ^ e[33]) & 1;
 s[12] = ( e[29] ^ e[48] ^ e[0] ^ e[31] ^ e[46] ^ e[22] ^ e[56]) & 1;
 s[23] = ( e[29] ^ e[14] ^ e[55] ^ e[36] ^ e[53] ^ e[6] ^ e[9]) & 1;
 s[26] = ( e[29] ^ e[19] ^ e[37] ^ e[58] ^ e[24] ^ e[44] ^ e[25]) & 1;
 s[6] = ( e[29] ^ e[21] ^ e[41] ^ e[7] ^ e[57] ^ e[51] ^ e[32]) & 1;
 s[55] = ( e[18] ^ e[12] ^ e[62] ^ e[27] ^ e[38] ^ e[10] ^ e[2]) & 1;
 s[42] = ( e[18] ^ e[43] ^ e[16] ^ e[50] ^ e[23] ^ e[54] ^ e[1]) & 1;
 s[62] = ( e[18] ^ e[20] ^ e[40] ^ e[28] ^ e[63] ^ e[39] ^ e[8]) & 1;
 }// ************        fim do metodo Lalpha           *****************
*/
//Metodo Expande chave
void  ExpandeChave(unsigned char* KEY,unsigned char XK[12][16],int Nr){
//modificada para gerar ate 17 sub-chaves

register unsigned char RCON [17]={
               0x1,// este byte e o RCon[1] pela nota��o do FIPS 197 (Nk=4)
               0x2,// este byte e o RCon[2]
               0x4,// este byte e o RCon[3]
               0x8,// este byte e o RCon[4]
               16,// este byte e o RCon[5]
               32,// este byte e o RCon[6]
               64,// este byte e o RCon[7]
               128,// este byte e o RCon[8]
               27,// este byte e o RCon[9]
               54,// este byte e o RCon[10]
               108,// este byte e o RCon[11]
               216,// este byte e o RCon[12]
               171,// este byte e o RCon[13]
               77,// este byte e o RCon[14]
               182,// este byte e o RCon[15]
               119,// este byte e o RCon[16]
               238,// este byte e o RCon[17]
               };//foram cradas at� o r_con 17 para possibilitar 17 iteracoes do Alpha

//OBS: NAO PRECISA SER FEITO, EH SOH RECEBER DIRETO EM XK[0] DO EDITBOX
for (int j=0;j<16;j++)// atribui a chave aa primeira sub-chave
    XK[0][j]=KEY[j];
//XK[0][16]='\0';
for (int i=1;i<Nr;i++){// i do FIPS para chave do round i. no ARK inicial i=0.

    //ROTWORD
	XK[i][0]=XK[i-1][13];
    XK[i][1]=XK[i-1][14];
    XK[i][2]=XK[i-1][15];
    XK[i][3]=XK[i-1][12];

    //BYTESUB WORD
    N_alpha(&XK[i][0],0);
    N_alpha(&XK[i][1],0);
    N_alpha(&XK[i][2],0);
    N_alpha(&XK[i][3],0);

    //XOR com RCon e com W da iteracao anterior
    XK[i][0]^=RCON[i-1];

    XK[i][0]^=XK[i-1][0];
    XK[i][1]^=XK[i-1][1];
	XK[i][2]^=XK[i-1][2];
	XK[i][3]^=XK[i-1][3];

    //Geracao das WORDS W[i,1],W[i,2],W[i,3]
    for(int k=1;k<4;k++){
    XK[i][4*k] = XK[i-1][4*k]^XK[i][4*k-4];
    XK[i][4*k+1]=XK[i-1][4*k+1]^XK[i][4*k-3];
    XK[i][4*k+2]=XK[i-1][4*k+2]^XK[i][4*k-2];
    XK[i][4*k+3]=XK[i-1][4*k+3]^XK[i][4*k-1];
    }
}//fim do for int i

}//fim do ExpandeChave

//--------------------------------------------------------------------------

//Ver o que eh mais rapido: transformar p/ matriz ou ficar dando shift
void  L_alpha2(unsigned char* e,unsigned char* s){//
unsigned char t[64];
 t[0] = ( (e[5]>>2 ) ^ (e[5]>>4 ) ^ (e[1]>>6 ) ^ (e[0]>>5 ) ^ (e[6]>>7 ) ^ (e[3]>>5 ) ^ (e[4]>>6) )  & 1;
 t[1] = ( (e[7]>>2 ) ^ (e[4]>>2 ) ^ (e[2]>>2 ) ^ (e[1]>>5 ) ^ (e[6]>>1 ) ^ (e[5]>>6 ) ^ (e[3]>>6) )  & 1;
 t[2] = ( (e[3]>>1 ) ^ (e[2]>>1 ) ^ (e[3]>>3 ) ^ (e[0]>>4 ) ^ (e[1]>>2 ) ^ (e[7]>>7 ) ^ (e[5]>>5) )  & 1;
 t[3] = ( (e[1]>>4 ) ^ (e[0]>>1 ) ^ (e[7]>>6 ) ^ (e[6]>>4 ) ^ (e[1]>>2 ) ^ (e[4]>>5 ) ^ (e[5]>>4) )  & 1;
 t[4] = ( (e[2]>>3 ) ^ (e[5]>>7 ) ^ (e[0] ) ^ (e[4]>>7 ) ^ (e[3]>>7 ) ^ (e[1]>>7 ) ^ (e[3]) )  & 1;
 t[5] = ( (e[6]>>3 ) ^ (e[2] ) ^ (e[4]>>6 ) ^ (e[6]>>6 ) ^ (e[7]>>5 ) ^ (e[0] ) ^ (e[3]>>5) )  & 1;
 t[6] = ( (e[3]>>2 ) ^ (e[2]>>2 ) ^ (e[5]>>6 ) ^ (e[0] ) ^ (e[7]>>6 ) ^ (e[6]>>4 ) ^ (e[4]>>7) )  & 1;
 t[7] = ( (e[0]>>3 ) ^ (e[6]>>2 ) ^ (e[3]>>6 ) ^ (e[4]>>1 ) ^ (e[2] ) ^ (e[1]>>1 ) ^ (e[0]>>6) )  & 1;

 t[8] = ( (e[0]>>3 ) ^ (e[4]>>3 ) ^ (e[0]>>2 ) ^ (e[2]>>7 ) ^ (e[7]>>4 ) ^ (e[1]>>5 ) ^ (e[2]>>6) )  & 1;
 t[9] = ( (e[3]>>1 ) ^ (e[3]>>5 ) ^ (e[0]>>2 ) ^ (e[6]>>7 ) ^ (e[4]>>1 ) ^ (e[6]>>6 ) ^ (e[1]>>3) )  & 1;
 t[10] = ( (e[1]>>4 ) ^ (e[7]>>4 ) ^ (e[1]>>3 ) ^ (e[4]>>1 ) ^ (e[6] ) ^ (e[0]>>6 ) ^ (e[2]) )  & 1;
 t[11] = ( (e[2]>>3 ) ^ (e[1]>>5 ) ^ (e[7]>>4 ) ^ (e[0]>>4 ) ^ (e[2]>>7 ) ^ (e[7]>>6 ) ^ (e[6]>>4) )  & 1;
 t[12] = ( (e[3]>>2 ) ^ (e[6]>>7 ) ^ (e[0]>>7>>7 ) ^ (e[3] ) ^ (e[5]>>1 ) ^ (e[2]>>1 ) ^ (e[7]>>7) )  & 1;
 t[13] = ( (e[5]>>2 ) ^ (e[1]>>1 ) ^ (e[3]>>7 ) ^ (e[4]>>7 ) ^ (e[5]>>7 ) ^ (e[6]>>1 ) ^ (e[2]>>2) )  & 1;
 t[14] = ( (e[4]>>4 ) ^ (e[0]>>6 ) ^ (e[1]>>3 ) ^ (e[5]>>4 ) ^ (e[1]>>7 ) ^ (e[7]>>4 ) ^ (e[5]>>7) )  & 1;
 t[15] = ( (e[6]>>3 ) ^ (e[5]>>1 ) ^ (e[4] ) ^ (e[2]>>5 ) ^ (e[6] ) ^ (e[0]>>1 ) ^ (e[1]>>7) )  & 1;

 t[16] = ( (e[1]>>4 ) ^ (e[0] ) ^ (e[4]>>3 ) ^ (e[2]>>6 ) ^ (e[3]>>7 ) ^ (e[7]>>5 ) ^ (e[6]>>1) )  & 1;
 t[17] = ( (e[5]>>2 ) ^ (e[1] ) ^ (e[0]>>4 ) ^ (e[7]>>7 ) ^ (e[2]>>5 ) ^ (e[5]>>1 ) ^ (e[0]>>2) )  & 1;
 t[18] = ( (e[5] ) ^ (e[6] ) ^ (e[5]>>5 ) ^ (e[7]>>1 ) ^ (e[4]>>2 ) ^ (e[0]>>2 ) ^ (e[6]>>2) )  & 1;
 t[19] = ( (e[6]>>3 ) ^ (e[6]>>5 ) ^ (e[0]>>5 ) ^ (e[7] ) ^ (e[4]>>2 ) ^ (e[1]>>2 ) ^ (e[5]>>4) )  & 1;
 t[20] = ( (e[7]>>1 ) ^ (e[5] ) ^ (e[1]>>4 ) ^ (e[0]>>3 ) ^ (e[3]>>1 ) ^ (e[7]>>2 ) ^ (e[6]>>3) )  & 1;
 t[21] = ( (e[4]>>4 ) ^ (e[7]>>7 ) ^ (e[2]>>5 ) ^ (e[4] ) ^ (e[7]>>6 ) ^ (e[6]>>2 ) ^ (e[3]>>7) )  & 1;
 t[22] = ( (e[3]>>1 ) ^ (e[5]>>3 ) ^ (e[2]>>4 ) ^ (e[4]>>5 ) ^ (e[0] ) ^ (e[1]>>7 ) ^ (e[7]>>6) )  & 1;
 t[23] = ( (e[3]>>2 ) ^ (e[1]>>1 ) ^ (e[6] ) ^ (e[4]>>3 ) ^ (e[6]>>2 ) ^ (e[0]>>1 ) ^ (e[1]>>6) )  & 1;

 t[24] = ( (e[0]>>3 ) ^ (e[1] ) ^ (e[2]>>2 ) ^ (e[5]>>6 ) ^ (e[3]>>3 ) ^ (e[6]>>5 ) ^ (e[5]>>3) )  & 1;
 t[25] = ( (e[6]>>3 ) ^ (e[2]>>1 ) ^ (e[3]>>3 ) ^ (e[6]>>2 ) ^ (e[1]>>6 ) ^ (e[7]>>4 ) ^ (e[3]) )  & 1;
 t[26] = ( (e[3]>>2 ) ^ (e[2]>>4 ) ^ (e[4]>>2 ) ^ (e[7]>>5 ) ^ (e[3]>>7 ) ^ (e[5]>>3 ) ^ (e[3]>>6) )  & 1;
 t[27] = ( (e[5]>>2 ) ^ (e[1]>>2 ) ^ (e[5]>>3 ) ^ (e[4]>>3 ) ^ (e[2]>>1 ) ^ (e[4]>>1 ) ^ (e[7]>>3) )  & 1;
 t[28] = ( (e[4]>>4 ) ^ (e[4]>>5 ) ^ (e[3] ) ^ (e[0]>>4 ) ^ (e[6]>>7 ) ^ (e[1]>>5 ) ^ (e[5]>>1) )  & 1;
 t[29] = ( (e[5] ) ^ (e[7]>>5 ) ^ (e[4] ) ^ (e[1]>>3 ) ^ (e[2] ) ^ (e[3]>>5 ) ^ (e[0]>>1) )  & 1;
 t[30] = ( (e[2]>>3 ) ^ (e[2]>>1 ) ^ (e[4]>>2 ) ^ (e[1]>>6 ) ^ (e[6]>>1 ) ^ (e[0]>>5 ) ^ (e[5]>>3) )  & 1;
 t[31] = ( (e[0]>>3 ) ^ (e[3]>>6 ) ^ (e[7]>>5 ) ^ (e[4]>>2 ) ^ (e[6]>>7 ) ^ (e[0]>>7 ) ^ (e[1]>>2) )  & 1;

 t[32] = ( (e[0]>>3 ) ^ (e[5]>>1 ) ^ (e[7]>>7 ) ^ (e[3]>>4 ) ^ (e[0]>>1 ) ^ (e[4] ) ^ (e[6]>>4) )  & 1;
 t[33] = ( (e[5]>>2 ) ^ (e[0]>>1 ) ^ (e[6] ) ^ (e[2]>>4 ) ^ (e[3]>>3 ) ^ (e[5]>>6 ) ^ (e[7]) )  & 1;
 t[34] = ( (e[5] ) ^ (e[1]>>7 ) ^ (e[1]>>1 ) ^ (e[0]>>4 ) ^ (e[7] ) ^ (e[6]>>5 ) ^ (e[4]>>7) )  & 1;
 t[35] = ( (e[5] ) ^ (e[3]>>3 ) ^ (e[4]>>3 ) ^ (e[2]>>2 ) ^ (e[1]>>1 ) ^ (e[6]>>7 ) ^ (e[5]>>6) )  & 1;
 t[36] = ( (e[4]>>4 ) ^ (e[0]>>2 ) ^ (e[6]>>5 ) ^ (e[4]>>1 ) ^ (e[1] ) ^ (e[3]>>5 ) ^ (e[2]>>6) )  & 1;
 t[37] = ( (e[3]>>1 ) ^ (e[5]>>7 ) ^ (e[6]>>1 ) ^ (e[3]>>4 ) ^ (e[5]>>6 ) ^ (e[1]>>6 ) ^ (e[7]>>3) )  & 1;
 t[38] = ( (e[7]>>2 ) ^ (e[0]>>5 ) ^ (e[7]>>6 ) ^ (e[4]>>5 ) ^ (e[0] ) ^ (e[1] ) ^ (e[6]>>4) )  & 1;
 t[39] = ( (e[3]>>2 ) ^ (e[5]>>5 ) ^ (e[2]>>6 ) ^ (e[0]>>4 ) ^ (e[7]>>4 ) ^ (e[3]>>5 ) ^ (e[4]>>6) )  & 1;

 t[40] = ( (e[0]>>3 ) ^ (e[4]>>6 ) ^ (e[6]>>6 ) ^ (e[2]>>7 ) ^ (e[7]>>3 ) ^ (e[0]>>4 ) ^ (e[7]>>1) )  & 1;
 t[41] = ( (e[4]>>4 ) ^ (e[1]>>5 ) ^ (e[0]>>7 ) ^ (e[6]>>4 ) ^ (e[3]>>6 ) ^ (e[4]>>5 ) ^ (e[2]>>7) )  & 1;
 t[42] = ( (e[2]>>5 ) ^ (e[5]>>4 ) ^ (e[2]>>7 ) ^ (e[6]>>5 ) ^ (e[2] ) ^ (e[6]>>1 ) ^ (e[0]>>6) )  & 1;
 t[43] = ( (e[6]>>3 ) ^ (e[5]>>3 ) ^ (e[6]>>4 ) ^ (e[1]>>3 ) ^ (e[5]>>5 ) ^ (e[7]>>1 ) ^ (e[2]>>2) )  & 1;
 t[44] = ( (e[3]>>1 ) ^ (e[4]>>3 ) ^ (e[6]>>2 ) ^ (e[2]>>7 ) ^ (e[7] ) ^ (e[5]>>4 ) ^ (e[1]>>1) )  & 1;
 t[45] = ( (e[5] ) ^ (e[6]>>6 ) ^ (e[3]>>4 ) ^ (e[0]>>7 ) ^ (e[4]>>6 ) ^ (e[1]>>2 ) ^ (e[2]>>6) )  & 1;
 t[46] = ( (e[7]>>2 ) ^ (e[3]>>4 ) ^ (e[5]>>3 ) ^ (e[2] ) ^ (e[4] ) ^ (e[5]>>5 ) ^ (e[2]>>1) )  & 1;
 t[47] = ( (e[2]>>3 ) ^ (e[4]>>4 ) ^ (e[5]>>2 ) ^ (e[3]>>2 ) ^ (e[2]>>5 ) ^ (e[4]>>5 ) ^ (e[6]>>2) )  & 1;

 t[48] = ( (e[4]>>4 ) ^ (e[3]>>3 ) ^ (e[0] ) ^ (e[2] ) ^ (e[6]>>6 ) ^ (e[4]>>2 ) ^ (e[5]>>5) )  & 1;
 t[49] = ( (e[5]>>2 ) ^ (e[7]>>1 ) ^ (e[2]>>6 ) ^ (e[0]>>2 ) ^ (e[6]>>5 ) ^ (e[3] ) ^ (e[7]>>5) )  & 1;
 t[50] = ( (e[7]>>2 ) ^ (e[3]>>7 ) ^ (e[0]>>1 ) ^ (e[7]>>4 ) ^ (e[1]>>7 ) ^ (e[4]>>7 ) ^ (e[1]>>1) )  & 1;
 t[51] = ( (e[1]>>4 ) ^ (e[6] ) ^ (e[1]>>3 ) ^ (e[0]>>5 ) ^ (e[5]>>7 ) ^ (e[3]>>5 ) ^ (e[1]>>6) )  & 1;
 t[52] = ( (e[2]>>3 ) ^ (e[2]>>4 ) ^ (e[3]>>6 ) ^ (e[1] ) ^ (e[0]>>2 ) ^ (e[7]>>7 ) ^ (e[5]>>4) )  & 1;
 t[53] = ( (e[5] ) ^ (e[1] ) ^ (e[6]>>7 ) ^ (e[7]>>3 ) ^ (e[0]>>5 ) ^ (e[4]>>6 ) ^ (e[2]>>1) )  & 1;
 t[54] = ( (e[3]>>1 ) ^ (e[7]>>5 ) ^ (e[0]>>6 ) ^ (e[4]>>6 ) ^ (e[2]>>6 ) ^ (e[3] ) ^ (e[5]>>1) )  & 1;
 t[55] = ( (e[2]>>5 ) ^ (e[1]>>3 ) ^ (e[7]>>1 ) ^ (e[3]>>4 ) ^ (e[4]>>1 ) ^ (e[1]>>5 ) ^ (e[0]>>5) )  & 1;

 t[56] = ( (e[6]>>3 ) ^ (e[5]>>6 ) ^ (e[0]>>6 ) ^ (e[7]>>6 ) ^ (e[3]>>4 ) ^ (e[4]>>3 ) ^ (e[2]>>4) )  & 1;
 t[57] = ( (e[1]>>4 ) ^ (e[1]>>5 ) ^ (e[3] ) ^ (e[4]>>7 ) ^ (e[5]>>5 ) ^ (e[2]>>2 ) ^ (e[7]) )  & 1;
 t[58] = ( (e[3]>>2 ) ^ (e[7]>>3 ) ^ (e[3]>>4 ) ^ (e[1]>>2 ) ^ (e[4]>>5 ) ^ (e[6]>>6 ) ^ (e[1]) )  & 1;
 t[59] = ( (e[1]>>4 ) ^ (e[7]>>7 ) ^ (e[0]>>7 ) ^ (e[6]>>6 ) ^ (e[1]>>6 ) ^ (e[4] ) ^ (e[2]>>4) )  & 1;
 t[60] = ( (e[7]>>2 ) ^ (e[2]>>4 ) ^ (e[6] ) ^ (e[4]>>7 ) ^ (e[3]>>7 ) ^ (e[0]>>7 ) ^ (e[7]>>1) )  & 1;
 t[61] = ( (e[2]>>3 ) ^ (e[7]>>3 ) ^ (e[0]>>6 ) ^ (e[4]>>1 ) ^ (e[5]>>1 ) ^ (e[6]>>5 ) ^ (e[7]) )  & 1;
 t[62] = ( (e[2]>>5 ) ^ (e[2]>>3 ) ^ (e[5]>>7 ) ^ (e[3]>>3 ) ^ (e[7] ) ^ (e[4] ) ^ (e[1]>>7) )  & 1;
 t[63] = ( (e[7]>>2 ) ^ (e[7]>>3 ) ^ (e[5]>>7 ) ^ (e[2]>>7 ) ^ (e[3]>>6 ) ^ (e[0]>>7 ) ^ (e[6]>>1) ) & 1;

 s[0] = (t[0]<<7)|(t[1]<<6)|(t[2]<<5)|(t[3]<<4)|(t[4]<<3)|(t[5]<<2)|(t[6]<<1)|(t[7]);
 s[1] = (t[8]<<7)|(t[9]<<6)|(t[10]<<5)|(t[11]<<4)|(t[12]<<3)|(t[13]<<2)|(t[14]<<1)|(t[15]);
 s[2] = (t[16]<<7)|(t[17]<<6)|(t[18]<<5)|(t[19]<<4)|(t[20]<<3)|(t[21]<<2)|(t[22]<<1)|(t[23]);
 s[3] = (t[24]<<7)|(t[25]<<6)|(t[26]<<5)|(t[27]<<4)|(t[28]<<3)|(t[29]<<2)|(t[30]<<1)|(t[31]);
 s[4] = (t[32]<<7)|(t[33]<<6)|(t[34]<<5)|(t[35]<<4)|(t[36]<<3)|(t[37]<<2)|(t[38]<<1)|(t[39]);
 s[5] = (t[40]<<7)|(t[41]<<6)|(t[42]<<5)|(t[43]<<4)|(t[44]<<3)|(t[45]<<2)|(t[46]<<1)|(t[47]);
 s[6] = (t[48]<<7)|(t[49]<<6)|(t[50]<<5)|(t[51]<<4)|(t[52]<<3)|(t[53]<<2)|(t[54]<<1)|(t[55]);
 s[7] = (t[56]<<7)|(t[57]<<6)|(t[58]<<5)|(t[59]<<4)|(t[60]<<3)|(t[61]<<2)|(t[62]<<1)|(t[63]);


}// ************        fim do metodo Lalpha           *****************
