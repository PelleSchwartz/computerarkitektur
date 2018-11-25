/*
 * iType.cpp
 *
 *  Created on: 23. nov. 2018
 *      Author: psz
 */


#include "iTypes.h"
#include "processes.h"
#include "fields.h"
using namespace std;


uint8_t* jalr(line &instr, uint32_t * reg_ptr){
//Jump and link
	uint8_t* ra = (uint8_t*)(*(reg_ptr + 1)); //Return address
	return ra;
}
void lb(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_R_R1)>>15); // Stack pointer (could be any pointer though)
	int32_t imm = (instr.instr & EXTRACT_IMM_11_0) >> 20;
	// TODO: check for the sign in the total 32-bit word.
	uint8_t * sp = (uint8_t*) *rd;
	uint32_t data = (uint32_t)*(sp + imm);

	*rd = data;
}
void lh(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_R_R1)>>15); // Stack pointer (could be any pointer though)
	int32_t imm = (instr.instr & EXTRACT_IMM_11_0) >> 20; // TODO: is IMM interpreted as int32?
	// TODO: check for the sign in the total 32-bit word.
	uint8_t * sp = (uint8_t*) *rd;
	uint32_t data = ((uint32_t)*(sp + imm) << 8) & ((uint32_t)*(sp + imm + 1));


	*rd = data;
}
void lw(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_R_R1)>>15); // Stack pointer (could be any pointer though)
	int32_t imm = (instr.instr & EXTRACT_IMM_11_0) >> 20; // TODO: is IMM interpreted as int32?

	uint8_t * sp = (uint8_t*) *rd;
	uint32_t data = ((uint32_t)*(sp + imm) << 24) & ((uint32_t)*(sp + imm + 1) << 16) & ((uint32_t)*(sp + imm + 2) << 8) & ((uint32_t)*(sp + imm + 3));

	*rd = data;
}
void lbu(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_R_R1)>>15); // Stack pointer (could be any pointer though)
	int32_t imm = (instr.instr & EXTRACT_IMM_11_0) >> 20;
	// TODO: check for the sign in the total 32-bit word.
	uint8_t * sp = (uint8_t*) *rd;
	uint32_t data = (uint32_t)*(sp + imm);

	*rd = data;
}
void lhu(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_R_R1)>>15); // Stack pointer (could be any pointer though)
	int32_t imm = (instr.instr & EXTRACT_IMM_11_0) >> 20; // TODO: is IMM interpreted as int32?
	// TODO: check for the sign in the total 32-bit word.
	uint8_t * sp = (uint8_t*) *rd;
	uint32_t data = ((uint32_t)*(sp + imm) << 8) & ((uint32_t)*(sp + imm + 1));


	*rd = data;
}
void addi(line &instr, uint32_t * reg_ptr){

}
void slti(line &instr, uint32_t * reg_ptr){

}
void sltiu(line &instr, uint32_t * reg_ptr){

}
void xori(line &instr, uint32_t * reg_ptr){

}
void ori(line &instr, uint32_t * reg_ptr){

}
void andi(line &instr, uint32_t * reg_ptr){

}
void ecall(line &instr, uint32_t * reg_ptr){

}
