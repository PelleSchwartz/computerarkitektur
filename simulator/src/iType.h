/*
 * iType.h
 *
 *  Created on: 23. nov. 2018
 *      Author: psz
 */

#ifndef ITYPE_H_
#define ITYPE_H_

#include "processes.h"
void jalr(line &instr, uint32_t * reg_ptr);
void lb(line &instr, uint32_t * reg_ptr);
void lh(line &instr, uint32_t * reg_ptr);
void lw(line &instr, uint32_t * reg_ptr);
void lbu(line &instr, uint32_t * reg_ptr);
void addi(line &instr, uint32_t * reg_ptr);
void slti(line &instr, uint32_t * reg_ptr);
void sltiu(line &instr, uint32_t * reg_ptr);
void xori(line &instr, uint32_t * reg_ptr);
void ori(line &instr, uint32_t * reg_ptr);
void andi(line &instr, uint32_t * reg_ptr);
void ecall(line &instr, uint32_t * reg_ptr);

#endif /* ITYPE_H_ */
