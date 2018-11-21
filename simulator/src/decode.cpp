/*
 * decode.cpp
 *
 *  Created on: 21. nov. 2018
 *      Author: psz
 */

#include "decode.h"
#include "typenames.h"
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
    case 19: //I
      a.type = 'i';
      a.name = i19TypeFunc3(a.instr);
      break;
    case 115: //SPECIAL CASE: Ecall of I-type
      a.type = 'i';
      a.name = I_ECALL;
      break;
    case 35: //S
      a.type = 's';
      a.name = sTypeFunc3(a.instr);
      break;
    case 55: //SPECIAL CASE: LUI of U-type
      a.type = 'u';
      a.name = U_LUI;
      break;
    case 23: //SPECIAL CASE: AUIPC of U-type
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
