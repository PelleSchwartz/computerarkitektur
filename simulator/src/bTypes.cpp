#include "bTypes.h"
#include "processes.h"
#include "fields.h"
using namespace std;

uint8_t * beq(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter){
	uint32_t *r1,*r2;
	int32_t imm = 0;
	imm = imm | ((instr.instr & EXTRACT_B_IMM_12)>>19);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_11)<<4);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_10_5)>>20);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_4_1)>>7);

	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
  printf("beq x%.2d, x%.2d, PC+%d", ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20) , imm);
	if((int32_t)*r1 == (int32_t)*r2){
    return imm + prgm_counter;
  }
  else return prgm_counter+4;
}

uint8_t * bne(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter){
	uint32_t *r1,*r2;
	int32_t imm = 0;
	imm = imm | ((instr.instr & EXTRACT_B_IMM_12)>>19);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_11)<<4);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_10_5)>>20);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_4_1)>>7);

	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
  printf("bne x%.2d, x%.2d, PC+%d", ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20) , imm);
	if((int32_t)*r1 != (int32_t)*r2){
    return imm + prgm_counter;
  }
  else return prgm_counter+4;
}

uint8_t * blt(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter){
	uint32_t *r1,*r2;
	int32_t imm = 0;
	imm = imm | ((instr.instr & EXTRACT_B_IMM_12)>>19);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_11)<<4);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_10_5)>>20);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_4_1)>>7);

	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
  printf("blt x%.2d, x%.2d, PC+%d", ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20) , imm);
	if((int32_t)*r1 < (int32_t)*r2){
    return imm + prgm_counter;
  }
  else return prgm_counter+4;
}

uint8_t * bge(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter){
	uint32_t *r1,*r2;
	int32_t imm = 0;
	imm = imm | ((instr.instr & EXTRACT_B_IMM_12)>>19);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_11)<<4);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_10_5)>>20);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_4_1)>>7);

	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
  printf("bge x%.2d, x%.2d, PC+%d", ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20) , imm);
	if((int32_t)*r1 >= (int32_t)*r2){
    return imm + prgm_counter;
  }
  else return prgm_counter+4;
}

uint8_t * bltu(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter){
	uint32_t *r1,*r2;
	int32_t imm = 0;
	imm = imm | ((instr.instr & EXTRACT_B_IMM_12)>>19);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_11)<<4);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_10_5)>>20);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_4_1)>>7);

	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
  printf("bltu x%.2d, x%.2d, PC+%d", ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20) , imm);
	if(*r1 < *r2){
    return imm + prgm_counter;
  }
  else return prgm_counter+4;
}

uint8_t * bgeu(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter){
	uint32_t *r1,*r2;
	int32_t imm = 0;
	imm = imm | ((instr.instr & EXTRACT_B_IMM_12)>>19);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_11)<<4);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_10_5)>>20);
	imm = imm | ((instr.instr & EXTRACT_B_IMM_4_1)>>7);

	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
  printf("bgeu x%.2d, x%.2d, PC+%d", ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20) , imm);
	if(*r1 >= *r2){
    return imm + prgm_counter;
  }
  else return prgm_counter+4;
}
