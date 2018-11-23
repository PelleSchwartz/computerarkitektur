//============================================================================
// Name        : simulator.cpp
// Author      : Pelle Schwartz, Ramus Menzer
// Version     :
// Copyright   : Please dont copy all of it
// Description : Risc-V Simulator
//============================================================================
#include "typenames.h"
#include "decode.h"
#include "func3.h"
#include "processes.h"
#include <iostream>
using namespace std;

#define MEMORY_SIZE (2^20) //size of memory array , can be increased if needed.


//function prototypes:
static int readBin2Mem(FILE *ptr_myfile, uint8_t * mem_ptr);


int main()
{
	printf("Testrun: \n");
	FILE *ptr_myfile; //file pointer
	ptr_myfile = fopen("addneg.bin","rb");

	uint8_t mem[MEMORY_SIZE] = {0}; // Memory array
	uint32_t reg[32] = {0}; // registers array

	uint8_t * prgm_counter = &mem[0];
	uint32_t * reg_ptr = &reg[0];
	reg[2] = (uint32_t)&mem[MEMORY_SIZE-1];

	int num_ins = readBin2Mem(ptr_myfile,prgm_counter); //Reads binary file and returns the number of instructions.

	//TODO: implement stackpointer aswell, should go into doInstruction.
	prgm_counter = &mem[0];

	while (prgm_counter - &mem[0] < num_ins*4){
		// TODO go through each instruction set.
		printf("cnt-mem : %d \n",prgm_counter - &mem[0] );
		printf("%.2X ", *prgm_counter);
		printf("%.2X ", *(prgm_counter+1));
		printf("%.2X ", *(prgm_counter+2));
		printf("%.2X \n", *(prgm_counter+3));

		uint16_t upper = (uint16_t(*(prgm_counter+0)) << 8) | uint16_t(*(prgm_counter+1));
		uint16_t lower = (uint16_t(*(prgm_counter+2)) << 8) | uint16_t(*(prgm_counter+3));
		uint32_t ins = (uint32_t(upper) << 16) | lower;


		line instruction;
		instruction.instr = ins;
		instruction.name = 0;
		instruction.type = '\0';

		decoder(instruction);
		if (instruction.name == I_ECALL){break;}
		prgm_counter = doInstruction(instruction, prgm_counter, reg_ptr);
	}
	return 0;
}


static int readBin2Mem(FILE *ptr_myfile, uint8_t * mem_ptr){
	unsigned int read = 0;
	int counter = 0;
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
		return 0;
	}
	fseek(ptr_myfile, 0, SEEK_END);
	int size = ftell(ptr_myfile); // get current file pointer
	size = size/4;

	rewind(ptr_myfile);
	printf("size: %d \n",size);

	uint32_t instr32[size];
	for ( counter=0; counter < size; counter++)
	{
		fread(&read,sizeof(int32_t),1,ptr_myfile);
		instr32[counter] = read;
		printf("%.8X at %d \n", instr32[counter],counter);
	}
	fclose(ptr_myfile);

	for(counter = 0; counter < size; counter++){
		*mem_ptr = (instr32[counter] & 0xFF000000) >> 24;
		mem_ptr++;
		*mem_ptr = (instr32[counter] & 0x00FF0000) >> 16;
		mem_ptr++;
		*mem_ptr = (instr32[counter] & 0x0000FF00) >> 8;
		mem_ptr++;
		*mem_ptr = (instr32[counter] & 0x000000FF);
		mem_ptr++;
	}

	return size; //number of instructions
}

