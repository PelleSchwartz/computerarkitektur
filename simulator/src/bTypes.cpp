#include "bTypes.h"
#include "processes.h"
#include "fields.h"
using namespace std;

uint32_r * beq(line &instr, uint32_t * reg_ptr){
	uint32_t * imm, *r1,*r2;
	imm = ((instr.instr & EXTRACT_B_IMM_12)>>19);
  imm += ((instr.instr & EXTRACT_B_IMM_11)<<4);
  imm += ((instr.instr & EXTRACT_B_IMM_10_5)>>20);
  imm += ((instr.instr & EXTRACT_B_IMM_4_1)>>7);

	r1 = reg_ptr+((instr.instr & EXTRACT_R_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_R_R2)>>20);
  printf("add x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_R_R1)>>15) , ((instr.instr & EXTRACT_R_R2)>>20));
	if(*r1 == *r2){
    return imm+reg_prt;
  }
  else return reg_prt;
}
