/*
 * usTypes.h
 *
 *  Created on: 26. nov. 2018
 *      Author: psz
 */

#ifndef USTYPES_H_
#define USTYPES_H_
#include "processes.h"

void sb(line &instr, uint32_t * reg_ptr);
void sh(line &instr, uint32_t * reg_ptr);
void sw(line &instr, uint32_t * reg_ptr);
void lui(line &instr, uint32_t * reg_ptr);
void auipc(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter);





#endif /* USTYPES_H_ */
