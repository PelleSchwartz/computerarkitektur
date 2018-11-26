/*
 * rTypes.cpp
 *
 *  Created on: 23. nov. 2018
 *      Author: psz
 */

#include "rTypes.h"
#include "processes.h"
#include "fields.h"
using namespace std;

void add(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1,*r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = *r1 + *r2;
	printf("add x%.2d, x%.2d, x%.2d\n", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}

void sub(line &instr, uint32_t * reg_ptr){
	uint32_t * rd,* r1,* r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = *r1 - *r2;
	printf("sub x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}

void sll(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1, *r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = (int32_t)*r1<<((int32_t)*r2);
	printf("sll x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}

void sltu(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1, *r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = (*r1 < *r2) ? 1 : 0;
	printf("sltu x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}

void xorr(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1, *r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = *r1 ^ *r2;
	printf("xor x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}
void srl(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1, *r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = *r1>>(*r2);
	printf("srl x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}
void sra(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1, *r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = *r1>>(*r2);
	printf("sra x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}
void slt(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1, *r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = (*r1 < *r2) ? 1 : 0;
	printf("slt x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}
void orr(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1, *r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = *r1 | *r2;
	printf("or x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}
void andd(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1, *r2;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = *r1 & *r2;
	printf("xor x%.2d, x%.2d, x%.2d", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}
