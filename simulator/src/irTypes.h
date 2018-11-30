#ifndef IRTYPES_H_
#define IRTYPES_H_

#include "processes.h"
using namespace std;

void slli(line &instr, uint32_t * reg_ptr);

void srai(line &instr, uint32_t * reg_ptr);

void srli(line &instr, uint32_t * reg_ptr);

#endif
