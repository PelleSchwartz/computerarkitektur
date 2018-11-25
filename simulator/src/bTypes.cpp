#include "bTypes.h"
#include "processes.h"
#include "fields.h"
using namespace std;

uint8_t * beq(line &instr, uint32_t * reg_ptr){
	uint32_t imm, *r1,*r2;
	imm = ((instr.instr & EXTRACT_B_IMM_12)>>19); // TODO: check mine hurtige ændringer
	imm += ((instr.instr & EXTRACT_B_IMM_11)<<4);
	imm += ((instr.instr & EXTRACT_B_IMM_10_5)>>20);
	imm += ((instr.instr & EXTRACT_B_IMM_4_1)>>7);

	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
  printf("add x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
	if(*r1 == *r2){
    return (uint8_t)(imm + reg_ptr); //cast til uint8t?
  }
  else return reg_ptr;
}
