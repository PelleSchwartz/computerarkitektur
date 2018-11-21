#ifndef DECODE_H
#define DECODE_H
#include "typenames.h"
#include "func3.h"
#include <iostream>

using namespace std;

struct line{
  uint32_t instr;
  char type;
  unsigned char name;
};

void decoder(line &a);

#endif
