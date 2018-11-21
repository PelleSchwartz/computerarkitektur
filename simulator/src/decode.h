#include "typenames.h"
#include "func3.h"
#include <iostream>

using namespace std;

struct line{
  uint32_t instr;
  char type;
  unsigned char name;
};

void decoder(line &a){
  switch (a.instr & 0x7F) {
    case 51: //R
      a.type = 'r';
      a.name = rTypeFunc3(a.instr);
      break;
    case 67: //JAL of I-type returns
      a.type = 'i';
      a.name = I_JALR;
      break;
    case 3: //I
      a.type = 'i';
      a.name = i3TypeFunc3(a.instr);
      break;
    case 19: //I or IR
      a.type = 'i';
      a.name = i19TypeFunc3(a.instr);
      break;
    case 115: //I Ecall
      a.type = 'i';
      a.name = I_ECALL;
      break;
    case 35: //S
      a.type = 's';
      a.name = sTypeFunc3(a.instr);
      break;
    case 55: //LUI of U-type returns
      a.type = 'u';
      a.name = U_LUI;
      break;
    case 23: //AUIPC of U-type returns
      a.type = 'u';
      a.name = U_AUIPC;
      break;
    case 99: //B
      a.type = 'b';
      a.name = bTypeFunc3(a.instr);
      break;
    case 111: //J
      a.type = 'j';
      a.name = J_JAL;
      break;
    default:
      break;
  }
}
