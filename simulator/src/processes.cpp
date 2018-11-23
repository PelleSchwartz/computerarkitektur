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
#include <iostream>
using namespace std;





void doInstruction(line &instr, uint32_t * mem_ptr, uint32_t * reg_ptr){
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
	}
	//TODO MANGE FLERE!!

}

//
////I-type
//
//#define I_JALR 11
//#define I_LB 12
//#define I_LH 13
//#define I_LW 14
//#define I_LBU 15
//#define I_LHU 16
//#define I_ADDI 17
//#define I_SLTI 18
//#define I_SLTIU 19
//#define I_XORI 20
//#define I_ORI 21
//#define I_ANDI 22
//#define I_ECALL 23
//
////IR-type
//
//#define IR_SLLI 24
//#define IR_SRLI 25
//#define IR_SRAI 26
//
////S-type
//
//#define S_SB 27
//#define S_SH 28
//#define S_SW 29
//
////U-type
//
//#define U_LUI 30
//#define U_AUIPC 31
//
////B-type
//
//#define B_BEQ 32
//#define B_BNE 33
//#define B_BLT 34
//#define B_BGE 35
//#define B_BLTU 36
//#define B_BGEU 37
//
////J-type
//
//#define J_JAL 38
