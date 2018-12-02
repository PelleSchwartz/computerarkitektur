/*
 * usTypes.cpp
 *
 *  Created on: 26. nov. 2018
 *      Author: psz
 */

#include "usTypes.h"
#include "processes.h"
#include "fields.h"

void sb(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr){
	uint32_t *r1, *r2;
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	int32_t imm = (((int32_t)instr.instr & EXTRACT_S_IMM_11_5) >> 25) | ((instr.instr & EXTRACT_S_IMM_4_0) >> 7);
	// TODO: check for the sign in the total 32-bit word.

	uint8_t * sp = mem_ptr + *r1; // stack pointer

	*(sp + imm) = (uint8_t)(*r2 & 0xFF); //save the byte
}
void sh(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr){
	uint32_t *r1, *r2;
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	int32_t imm = (((int32_t)instr.instr & EXTRACT_S_IMM_11_5) >> 25) | ((instr.instr & EXTRACT_S_IMM_4_0) >> 7);

	uint8_t * sp = mem_ptr + *r1; // stack pointer

	*(sp + imm + 1) = (uint8_t)((*r2 & 0xFF00)>>8); //save the upper byte

	*(sp + imm) = (uint8_t)(*r2 & 0xFF);; //save the lower byte
}
void sw(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr){
	uint32_t *r1, *r2;
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	int32_t imm = (((int32_t)instr.instr & EXTRACT_S_IMM_11_5) >> 25) | ((instr.instr & EXTRACT_S_IMM_4_0) >> 7);



	uint8_t * sp = mem_ptr + *r1; // stack pointer
	;
	sp += imm;
	*sp = (uint8_t)(*r2 & 0xFF); //save the upper byte
	sp ++;
	*sp = (uint8_t)((*r2 & 0xFF00)>>8); //save the upper mid byte
	sp ++;
	*sp = (uint8_t)((*r2 & 0xFF0000)>>16); //save the lower mid byte
	sp ++;
	*sp = (uint8_t)((*r2 & 0xFF000000)>>24); //save the lower byte
}
void lui(line &instr, uint32_t * reg_ptr){
	uint32_t * rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	int32_t upprimm = (instr.instr & EXTRACT_U_IMM_31_12);

	*rd = upprimm;
	printf("lui R[%d]: %.x \n",(instr.instr & EXTRACT_R_RD)>>7,*rd);
}
void auipc(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter, uint8_t * mem_ptr){
	uint32_t * rd = reg_ptr+((uint32_t)(instr.instr & EXTRACT_R_RD)>>7);
	int32_t upprimm = (instr.instr & EXTRACT_U_IMM_31_12);
	*rd = (uint32_t)(prgm_counter - mem_ptr + upprimm);
}
