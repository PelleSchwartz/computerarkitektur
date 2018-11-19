#include "typenames.h"
#include <iostream>

using namespace std;

struct line{
  uint32_t instr;
  char type;
  unsigned char name;
};

char opcode(line &a){
  switch (a.instr & 0x7F) {
    case 51: //R
      return 'r';
      break;
    case 67: //JAL of I-type returns
      return 'i';
      break;
    case 3: //I
      return 'i';
      break;
    case 19: //I or IR
      return 'i';
      break;
    case 115: //I Ecall
      return 'i';
      break;
    case 35: //S
      return 's';
      break;
    case 55: //U
      return 'u';
      break;
    case 23: //U
      return 'u';
      break;
    case 99: //B
      return 'b';
      break;
    case 111: //J
      return 'b';
      break;
    default:
      return 0;
      break;
  }
}
