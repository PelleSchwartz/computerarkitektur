/*
 * func3.cpp
 *
 *  Created on: 21. nov. 2018
 *      Author: psz
 */

#include "func3.h"
#include "typenames.h"
#include <iostream>
using namespace std;

unsigned char rTypeFunc3(uint32_t inst){
	char func3 = (inst >> 12) & 0x07;

	switch(func3){
	case 0x00:
		if ((inst >> 30) & 1) return R_SUB;
		return R_ADD;
	case 0x01:
		return R_SLL;
	case 0x02:
		return R_SLT;
	case 0x03:
		return R_SLTU;
	case 0x04:
		return R_XOR;
	case 0x05:
		if ((inst >> 30) & 1) return R_SRA;
		return R_SRL;
	case 0x06:
		return R_OR;
	case 0x07:
		return R_AND;
	default:
		return 0;
	}
}

unsigned char i3TypeFunc3(uint32_t inst){
	char func3 = (inst >> 12) & 0x07;
	switch(func3){
	case 0x00:
		return I_LB;
	case 0x01:
		return I_LH;
	case 0x02:
		return I_LW;
	case 0x04:
		return I_LBU;
	case 0x05:
		return I_LHU;
	default:
		return 0;
	}
}

unsigned char i19TypeFunc3(uint32_t inst){
	char func3 = (inst >> 12) & 0x07;
	switch(func3){
	case 0x00:
		return I_ADDI;
	case 0x02:
		return I_SLTI;
	case 0x03:
		return I_SLTIU;
	case 0x04:
		return I_XORI;
	case 0x06:
		return I_ORI;
	case 0x07:
		return I_ANDI;
	case 0x01:
		return IR_SLLI;
	case 0x05:
		if ((inst >> 30) & 1) return IR_SRAI;
		return IR_SRLI;
	default:
		return 0;
	}
}

unsigned char sTypeFunc3(uint32_t inst){
	char func3 = (inst >> 12) & 0x07;
	switch(func3){
	case 0x00:
		return S_SB;
	case 0x01:
		return S_SH;
	case 0x02:
		return S_SW;
	default:
		return 0;
	}
}

unsigned char bTypeFunc3(uint32_t inst){
	char func3 = (inst >> 12) & 0x07;
	switch(func3){
	case 0x00:
		return B_BEQ;
	case 0x01:
		return B_BNE;
	case 0x04:
		return B_BLT;
	case 0x05:
		return B_BGE;
	case 0x06:
		return B_BLTU;
	case 0x07:
		return B_BGEU;
	default:
		return 0;
	}
}



