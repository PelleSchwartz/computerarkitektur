/*
 * rTypes.h
 *
 *  Created on: 23. nov. 2018
 *      Author: psz
 */

#ifndef RTYPES_H_
#define RTYPES_H_

#include "processes.h"

void add(line &instr, uint32_t * reg_ptr);
void sub(line &instr, uint32_t * reg_ptr);
void sll(line &instr, uint32_t * reg_ptr);
void sltu(line &instr, uint32_t * reg_ptr);
void xorr(line &instr, uint32_t * reg_ptr);
void srl(line &instr, uint32_t * reg_ptr);
void sra(line &instr, uint32_t * reg_ptr);
void slt(line &instr, uint32_t * reg_ptr);
void orr(line &instr, uint32_t * reg_ptr);
void andd(line &instr, uint32_t * reg_ptr);




#endif /* RTYPES_H_ */
