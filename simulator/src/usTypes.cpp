/*
 * usTypes.cpp
 *
 *  Created on: 26. nov. 2018
 *      Author: psz
 */

#include "usTypes.h"
#include "processes.h"
#include "fields.h"

void sb(line &instr, uint32_t * reg_ptr){
	uint32_t *r1, *r2;
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	int32_t imm = ((instr.instr & EXTRACT_S_IMM_11_5) >> 25) | ((instr.instr & EXTRACT_S_IMM_4_0) >> 7);
	// TODO: check for the sign in the total 32-bit word.

	uint8_t * sp = (uint8_t*) *r1; // stack pointer

	*(sp + imm) = (uint8_t)*r2; //save the byte
}
void sh(line &instr, uint32_t * reg_ptr){
	uint32_t *r1, *r2;
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	int32_t imm = ((instr.instr & EXTRACT_S_IMM_11_5) >> 25) | ((instr.instr & EXTRACT_S_IMM_4_0) >> 7);

	uint8_t * sp = (uint8_t*) *r1; // stack pointer

	*(sp + imm) = (uint8_t)(*r2 & 0xFF00); //save the upper byte

	*(sp + imm + 1) = (uint8_t)(*r2 & 0xFF);; //save the lower byte
}
void sw(line &instr, uint32_t * reg_ptr){
	uint32_t *r1, *r2;
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	int32_t imm = ((instr.instr & EXTRACT_S_IMM_11_5) >> 25) | ((instr.instr & EXTRACT_S_IMM_4_0) >> 7);

	uint8_t * sp = (uint8_t*) *r1; // stack pointer

	*(sp + imm) = (uint8_t)(*r2 & 0xFF000000); //save the upper byte

	*(sp + imm + 1) = (uint8_t)(*r2 & 0xFF0000); //save the upper mid byte

	*(sp + imm + 2) = (uint8_t)(*r2 & 0xFF00); //save the lower mid byte

	*(sp + imm + 3) = (uint8_t)(*r2 & 0xFF); //save the lower byte
}
void lui(line &instr, uint32_t * reg_ptr){
	uint32_t * rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	int32_t upprimm = (instr.instr & EXTRACT_U_IMM_31_12);

	*rd = upprimm;
	printf("lui R[%d]: %.x \n",(instr.instr & EXTRACT_R_RD)>>7,*rd);
}
void auipc(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter){
	uint32_t * rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	int32_t upprimm = (instr.instr & EXTRACT_U_IMM_31_12);
	*rd = (uint32_t)(prgm_counter + upprimm);
}
