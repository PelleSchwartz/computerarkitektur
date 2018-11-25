/*
 * processes.cpp
 *
 *  Created on: 21. nov. 2018
 *      Author: psz
 */


#include "processes.h"
#include "decode.h"
#include "typenames.h"
#include "rTypes.h"
#include "iTypes.h"
#include "bTypes.h"
#include <iostream>
using namespace std;





uint8_t * doInstruction(line &instr, uint8_t * prgm_counter, uint32_t * reg_ptr){
	switch(instr.name){
	case R_ADD:
		add(instr, reg_ptr);
		break;
	case R_SUB:
		sub(instr, reg_ptr);
		break;
	case R_SLL:
		sll(instr, reg_ptr);
		break;
	case R_SLTU:
		sltu(instr, reg_ptr);
		break;
	case R_XOR:
		xorr(instr, reg_ptr);
		break;
	case R_SRL:
		srl(instr, reg_ptr);
		break;
	case R_SRA:
		sra(instr, reg_ptr);
		break;
	case R_SLT:
		slt(instr, reg_ptr);
		break;
	case R_OR:
		orr(instr, reg_ptr);
		break;
	case R_AND:
		andd(instr, reg_ptr);
		break;

		//I-type

	case I_JALR:
		return jalr(instr, reg_ptr);
	case I_LB:
		lb(instr, reg_ptr);
		break;
	case I_LH:
		lh(instr, reg_ptr);
		break;
	case I_LW:
		lw(instr, reg_ptr);
		break;
	case I_LBU:
		lbu(instr, reg_ptr);
		break;
	case I_LHU:
		lhu(instr, reg_ptr);
		break;
	case I_ADDI:
		addi(instr, reg_ptr);
		break;
	case I_SLTI:
		slti(instr, reg_ptr);
		break;
	case I_SLTIU:
		sltiu(instr, reg_ptr);
		break;
	case I_XORI:
		xori(instr, reg_ptr);
		break;
	case I_ORI:
		ori(instr, reg_ptr);
		break;
	case I_ANDI:
		andi(instr, reg_ptr);
		break;
	case I_ECALL:
		break;

		// IR-type

	case IR_SLLI:
		break;
	case IR_SRLI:
		break;
	case IR_SRAI:
		break;

		// S-type

	case S_SB:
		break;
	case S_SH:
		break;
	case S_SW:
		break;

		//U-type

	case U_LUI:
		break;
	case U_AUIPC:
		break;

		//B-type


	case B_BEQ:
		return beq(instr, reg_ptr);
	case B_BNE:
		break;
	case B_BLT:
		break;
	case B_BGE:
		break;
	case B_BLTU:
		break;
	case B_BGEU:
		break;

		//J-type


	case J_JAL:
		break;

	default:
		printf("Unknown input.");
		break;
	}
	//TODO MANGE FLERE!!
	return prgm_counter + 4;
}
