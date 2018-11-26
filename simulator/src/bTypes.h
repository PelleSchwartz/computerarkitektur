#ifndef BTYPES_H_
#define BTYPES_H_

#include "processes.h"

uint8_t * beq(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter);
uint8_t * bne(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter);
uint8_t * blt(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter);
uint8_t * bge(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter);
uint8_t * bltu(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter);
uint8_t * bgeu(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter);

#endif /* BTYPES_H_ */
