/*
 * iType.h
 *
 *  Created on: 23. nov. 2018
 *      Author: psz
 */

#ifndef ITYPES_H_
#define ITYPES_H_

#include "processes.h"
uint8_t* jalr(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter,uint8_t * mem_ptr);
uint8_t* jal(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter,uint8_t * mem_ptr);
void lb(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr);
void lh(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr);
void lw(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr);
void lbu(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr);
void lhu(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr);
void addi(line &instr, uint32_t * reg_ptr);
void slti(line &instr, uint32_t * reg_ptr);
void sltiu(line &instr, uint32_t * reg_ptr);
void xori(line &instr, uint32_t * reg_ptr);
void ori(line &instr, uint32_t * reg_ptr);
void andi(line &instr, uint32_t * reg_ptr);
void ecall(line &instr, uint32_t * reg_ptr);

#endif /* ITYPES_H_ */
