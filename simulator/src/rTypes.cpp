/*
 * rTypes.cpp
 *
 *  Created on: 23. nov. 2018
 *      Author: psz
 */

#include "rTypes.h"
#include "processes.h"

void add(line &instr, uint32_t * reg_ptr){
	printf("adding");
}

void sub(line &instr, uint32_t * reg_ptr){
	printf("substracting");
}

void sll(line &instr, uint32_t * reg_ptr){
	printf("sll'ing");
}
void sltu(line &instr, uint32_t * reg_ptr){
	printf("sltu");
}
void xorr(line &instr, uint32_t * reg_ptr){
	printf("xoring");
}
void srl(line &instr, uint32_t * reg_ptr){
	printf("srl");
}
void sra(line &instr, uint32_t * reg_ptr){
	printf("sra");
}
void slt(line &instr, uint32_t * reg_ptr){
	printf("slt");
}
void orr(line &instr, uint32_t * reg_ptr){
	printf("orr");
}
void andd(line &instr, uint32_t * reg_ptr){
	printf("andd");
}

