/*
 * processes.h
 *
 *  Created on: 21. nov. 2018
 *      Author: psz
 */

#ifndef PROCESSES_H_
#define PROCESSES_H_
#include "decode.h"
#include <iostream>

void add(line &instr, uint32_t reg_ptr);
void sub(line &instr, uint32_t reg_ptr);
void sll(line &instr, uint32_t reg_ptr);
void sltu(line &instr, uint32_t reg_ptr);
void xorr(line &instr, uint32_t reg_ptr);
void srl(line &instr, uint32_t reg_ptr);
void sra(line &instr, uint32_t reg_ptr);
void slt(line &instr, uint32_t reg_ptr);
void orr(line &instr, uint32_t reg_ptr);
void andd(line &instr, uint32_t reg_ptr);

uint8_t * doInstruction(line &instr, uint8_t * prgm_counter, uint32_t * reg_ptr, uint8_t * mem_ptr);

#endif /* PROCESSES_H_ */
