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

#define MEMORY_SIZE (4096) //size of memory array , can be increased if needed.


//function prototypes:
uint8_t * readBin2Mem(FILE *ptr_myfile, uint8_t * mem_ptr, int * size_ptr);
void printReg(uint32_t* reg_ptr, int size);
void printMem(uint8_t* mem_ptr, int size);
void writeMem2Bin(FILE *ptr_myfile, uint32_t reg[], string name);
int main()
{
	printf("Testrun: \n");
	FILE *ptr_myfile; //file pointer
	ptr_myfile = fopen("t2.bin","rb");

	uint8_t mem[MEMORY_SIZE] = {0}; // Memory array
	uint32_t reg[32] = {0}; // registers array

	uint8_t * prgm_counter = &mem[0];
	uint32_t * reg_ptr = &reg[0];
	reg[2] = (uint32_t)&mem[MEMORY_SIZE-5];
	prgm_counter = &mem[0];
	int num_ins = 0;
	prgm_counter = readBin2Mem(ptr_myfile,prgm_counter,&num_ins); //Reads binary file and returns the number of instructions.

	//TODO: implement stackpointer aswell, should go into doInstruction.

	while (prgm_counter - &mem[0] < num_ins*4){
		// TODO go through each instruction set.
		//printMem(&mem[0], num_ins);

		printf("\n NEXT LINE \n \n");

		printf("memory step : %d \n",prgm_counter - &mem[0]);
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
		printf("Instr name : %d \n" , instruction.name);
		if (instruction.name == I_ECALL){
			printf("ECALL\n \n");
			printReg(reg_ptr,32);
			return 0;
		}
		prgm_counter = doInstruction(instruction, prgm_counter, reg_ptr);
	}

	printReg(reg_ptr,32);

	return 0;
}


uint8_t * readBin2Mem(FILE *ptr_myfile, uint8_t * mem_ptr, int * size_ptr){
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
		*mem_ptr = (((uint32_t)instr32[counter] & 0xFF000000) >> 24);
		printf("%.2x",*mem_ptr);
		mem_ptr++;

		*mem_ptr = (uint8_t)(((uint32_t)instr32[counter] & 0x00FF0000) >> 16);
		printf("%.2x",*mem_ptr);
		mem_ptr++;

		*mem_ptr = (uint8_t)(((uint32_t)instr32[counter] & 0x0000FF00) >> 8);
		printf("%.2x",*mem_ptr);
		mem_ptr++;

		*mem_ptr = (uint8_t)(((uint32_t)instr32[counter] & 0x000000FF));
		printf("%.2x\n",*mem_ptr);
		mem_ptr++;

	}
	*size_ptr = size;
	return mem_ptr-size*4; //number of instructions
}

void writeMem2Bin(FILE *ptr_myfile, uint32_t reg[], string name){
	name = name + "res.res";
//	ofstream myFile (name, ios::out | ios::binary);
//	myFile.write(reg, 100);
}
void printReg(uint32_t* reg_ptr, int size){
	for (int i = 0; i < size; i++){
		printf("x%.2d: 0x%.8X \n", i, *reg_ptr);
		reg_ptr++;
	}
}

void printMem(uint8_t* mem_ptr, int size){
	for(int i = 0; i < size*4; i++){
		if(!(i%4)) {
				printf("\n");
			}
		printf("%.2x ", *mem_ptr);

		mem_ptr++;
	}
}
