/*
 * iType.cpp
 *
 *  Created on: 23. nov. 2018
 *      Author: psz
 */


#include "iTypes.h"
#include "processes.h"
#include "fields.h"
using namespace std;


uint8_t * jalr(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter,uint8_t * mem_ptr){
	uint32_t *rd, *r1;
	int32_t imm = 0;

	imm = imm | (((int32_t)instr.instr & EXTRACT_I_IMM_11_0)>>20);

	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);

	*rd = (uint32_t)(prgm_counter - mem_ptr +8);
	//assuming that r1 contains the instr.address of the wanted next instruction, with some offsett imm.
	//the content of r1-reg is a uint32_t, so it needs a cast to a pointer to the memory (which is a uint8_t-pointer)
	return (uint8_t*)(*r1 + imm);
}

uint8_t * jal(line &instr, uint32_t * reg_ptr, uint8_t * prgm_counter,uint8_t * mem_ptr){
//Jump and link
	uint32_t *rd, *r1;
	int32_t imm = 0;

	imm = imm | (((int32_t)instr.instr & EXTRACT_J_IMM_20)>>11);
	imm = imm | ((int32_t)instr.instr & EXTRACT_J_IMM_19_12);
	imm = imm | (((int32_t)instr.instr & EXTRACT_J_IMM_11)>>9);
	imm = imm | (((int32_t)instr.instr & EXTRACT_J_IMM_10_1)>>20);

	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	if (rd != reg_ptr){
		*rd = (uint32_t)((uint32_t)prgm_counter+8 - (uint32_t)mem_ptr);
	}
	return prgm_counter + imm; //the prgm_counter is already a uint8_t-pointer, so NO cast needed.
}

void lb(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr){
		uint32_t *rd, *r1;
		int32_t imm = 0;

		imm = (int32_t)((instr.instr & EXTRACT_IMM_11_0) >> 20);

		rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
		r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);

		uint8_t * sp = mem_ptr + *r1 + imm ;


		uint32_t data = (int32_t)*sp; //sp is a uint8_t-pointer to a place i memory + offset imm.
		//this address-value is then cast to uint32_t value so that it can be put in the reg file.
		if (data & 0x80){
			data |= 0xFFFFFF00;//if msb of original byte is 1, then zeropad to the left
		}
		*rd = data;
}

void lh(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	int32_t imm = (int32_t)((instr.instr & EXTRACT_IMM_11_0) >> 20); // TODO: is IMM interpreted as int32?

	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}

	uint8_t * sp = mem_ptr + *rd;
	uint32_t data = (int32_t)((uint16_t)*(sp + imm + 1) << 8) & ((uint16_t)*(sp + imm));

	if (data & 0x8000){
		data |= 0xFFFF0000;//if msb of original halfword is 1, then zeropad to the left
	}

	*rd = data;
}
void lw(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((int32_t)(instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((int32_t)(instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)


	int32_t imm = (int32_t)((instr.instr & EXTRACT_IMM_11_0) >> 20);
	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}

	uint8_t * sp = mem_ptr + *r1 + imm;
	uint32_t data = ((uint32_t)*(sp));
	sp++;
	data |= ((uint32_t)*(sp) << 8) ;
	printf(" ");
	sp++;
	data |= ((uint32_t)*(sp) << 16);
	printf(" ");
	sp++;
	data |= ((uint32_t)*(sp) << 24);

	*rd = data;


}
void lbu(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((int32_t)(instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	int8_t imm = (int8_t)((instr.instr & EXTRACT_IMM_11_0) >> 20); // TODO: is IMM interpreted as int32?

	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}

	uint8_t * sp = mem_ptr + *r1;
	uint32_t data = (uint32_t)*(sp + imm);

	data |= *(mem_ptr + *rd - (*rd % 4)) & 0x80;

	*rd = data;
}
void lhu(line &instr, uint32_t * reg_ptr, uint8_t * mem_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15); // Stack pointer (could be any pointer though)
	int8_t imm = (int8_t)((instr.instr & EXTRACT_IMM_11_0) >> 20); // TODO: is IMM interpreted as int32?

	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}

	uint8_t * sp = mem_ptr + *r1;
	uint32_t data = ((uint32_t)*(sp + imm)) & ((uint32_t)*(sp + imm + 1) << 8);

	data |= *(mem_ptr + *rd - (*rd % 4)) & 0x80;

	*rd = data;
}
void addi(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	int32_t imm = ((int32_t)(instr.instr & EXTRACT_IMM_11_0) >> 20); // TODO: is IMM interpreted as int32?

	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}
	*rd = *r1 + imm;
	printf("addi x%d, x%d, %d \n", (instr.instr & EXTRACT_R_RD)>>7,(instr.instr & EXTRACT_RBS_R1)>>15,imm);

}
void slti(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	int32_t imm = ((int32_t)instr.instr & EXTRACT_IMM_11_0) >> 20; // TODO: is IMM interpreted as int32?

	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}

	*rd = ((int32_t)*r1 < imm) ? 1 : 0;

}
void sltiu(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	uint32_t imm = ((int32_t)instr.instr & EXTRACT_IMM_11_0) >> 20; // TODO: is IMM interpreted as int32?
	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}
	*rd = ((uint32_t)*r1 < imm) ? 1 : 0;

}
void xori(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	int32_t imm = ((int32_t)instr.instr & EXTRACT_IMM_11_0) >> 20; // TODO: is IMM interpreted as int32?

	*rd = *r1 ^ imm;

}
void ori(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	int32_t imm = ((int32_t)instr.instr & EXTRACT_IMM_11_0) >> 20; // TODO: is IMM interpreted as int32?
	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}
	*rd = *r1 | imm;
}
void andi(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	int32_t imm = ((int32_t)instr.instr & EXTRACT_IMM_11_0) >> 20; // TODO: is IMM interpreted as int32?
	if(imm & 0x800){
		imm |= 0xFFFFF000;
	}
	*rd = *r1 & imm;
}
void ecall(line &instr, uint32_t * reg_ptr){
	//TODO anything here?
}
