/*
 * typenames.h
 *
 *  Created on: 19. nov. 2018
 *      Author: psz
 */

#ifndef TYPENAMES_H_
#define TYPENAMES_H_

//R-type

#define R_ADD 1
#define R_SUB 2
#define R_SLL 3
#define R_SLT 4
#define R_SLTU 5
#define R_XOR 6
#define R_SRL 7
#define R_SRA 8
#define R_OR 9
#define R_AND 10

//I-type

#define I_JALR 11
#define I_LB 12
#define I_LH 13
#define I_LW 14
#define I_LBU 15
#define I_LHU 16
#define I_ADDI 17
#define I_SLTI 18
#define I_SLTIU 19
#define I_XORI 20
#define I_ORI 21
#define I_ANDI 22
#define I_ECALL 23

//IR-type

#define IR_SLLI 24
#define IR_SRLI 25
#define IR_SRAI 26

//S-type

#define S_SB 27
#define S_SH 28
#define S_SW 29

//U-type

#define U_LUI 30
#define U_AUIPC 31

//B-type

#define B_BEQ 32
#define B_BNE 33
#define B_BLT 34
#define B_BGE 35
#define B_BLTU 36
#define B_BGEU 37

//J-type

#define J_JAL 38


#endif /* TYPENAMES_H_ */
