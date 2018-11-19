#include <iostream>

using namespace std;

char opcode(uint32_t a){
  char val=0;
  switch (a & 0x7F) {
    case 51: //R
      return 'r';
      break;
    case 67: //I JAL
      return 'i';
      break;
    case 3: //I

      break;
    case 19: //<ambiguous>
      //if funct3 is 1 or 5, it's a S-type
      if(((a & 7000)>>12) == 1 || ((a & 7000)>>12) == 5){
        return 's';
      }
      //else it's a I-type
      else return 'i';
      break;
    case 115: //I Ecall

      break;
    case 35: //S

      break;
    case 99: //B

      break;
    case 111: //J

      break;
    case 55: //U

      break;
    case 23: //U

      break;
  }
  return ;
}
