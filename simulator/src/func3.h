/*
 * func3.h
 *
 *  Created on: 19. nov. 2018
 *      Author: psz
 */

#include "typenames.h"

#ifndef FUNC3_H_
#define FUNC3_H_




unsigned char rTypeFunc3(uint32_t inst){
	char type = 0;
	char func3 = (inst >> 12) & 0x07;

	switch(func3){
	case 0x00:
		if ((inst >> 30) & 1) return R_SUB;
		return R_ADD;
	case 0x01:
		return R_SLL;
	case 0x02:
		return R_SLT;
	case 0x03:
		return R_SLTU;
	case 0x04:
		return R_XOR;
	case 0x05:
	}

	return type;
}


#endif /* FUNC3_H_ */
