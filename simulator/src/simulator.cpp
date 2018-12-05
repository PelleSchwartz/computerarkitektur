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
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define savename "result.res"

//function prototypes:
void readBin2Mem(FILE *ptr_myfile, uint8_t * mem_ptr, int * size_ptr);
void printReg(uint32_t* reg_ptr, int size);
void printMem(uint8_t* mem_ptr, int size);
void writeMem2Bin(FILE *ptr_myfile, uint32_t * reg);
int main()
{
	cout << "Result will be made in file named result.res" << endl;
	cout << "Enter file name: " << endl;

	string input = "";
	cin >> input;
	char tab2[1024] = "\0";


	strcpy(&tab2[0], input.c_str());
	//char str[] = {input};
	printf("Testrun: \n");
	FILE *ptr_myfile; //file pointer
	ptr_myfile = fopen(tab2,"rb");

	uint8_t mem[1<<20] = {0}; // Memory array
	uint32_t reg[32] = {0}; // registers array

	uint8_t * prgm_counter = &mem[0];
	uint32_t * reg_ptr = &reg[0];



	prgm_counter = &mem[0];
	int num_ins = 0;
	readBin2Mem(ptr_myfile,prgm_counter,&num_ins); //Reads binary file and returns the number of instructions.

	printMem(&mem[0],num_ins);


	printf("\nPC-&mem = %d\n",prgm_counter - &mem[0]);
	printf("num_ins = %d", num_ins);
	prgm_counter = &mem[0];


	int instructionsrunsofar = 0;

	while (prgm_counter - &mem[0] < num_ins*4){
		uint16_t upper = (uint16_t(*(prgm_counter+3)) << 8) | uint16_t(*(prgm_counter+2));
		uint16_t lower = (uint16_t(*(prgm_counter+1)) << 8) | uint16_t(*(prgm_counter+0));
		uint32_t ins = (uint32_t(upper) << 16) | lower;

		printf("%.8X \n" , ins);

		line instruction;
		instruction.instr = ins;
		instruction.name = 0;
		instruction.type = '\0';

		decoder(instruction);

		if (instruction.name == I_ECALL){
			printf("ECALL\n \n");
			printReg(reg_ptr,32);
			break;
		}
		prgm_counter = doInstruction(instruction, prgm_counter, reg_ptr, &mem[0]);
		instructionsrunsofar++;
		mem[0] = 0; //x0 should always be 0

	}
	ptr_myfile = fopen(savename,"w+");

	writeMem2Bin(ptr_myfile, reg_ptr);
	printReg(reg_ptr,32);


	printf("Press ENTER key to Continue\n");
	cin >> input;
	return 0;
}


void readBin2Mem(FILE *ptr_myfile, uint8_t * mem_ptr, int * numins){

	int counter = 0;
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
	}
	fseek(ptr_myfile, 0, SEEK_END);
	int size = ftell(ptr_myfile); // get current file pointer
	size = size/4;

	rewind(ptr_myfile);
	printf("numins: %d \n",size);
	mem_ptr += 0;
	for ( counter=0; counter < size; counter++)
	{
		fread(mem_ptr,sizeof(int8_t),1,ptr_myfile);
		mem_ptr++;
		fread(mem_ptr,sizeof(int8_t),1,ptr_myfile);
		mem_ptr++;
		fread(mem_ptr,sizeof(int8_t),1,ptr_myfile);
		mem_ptr++;
		fread(mem_ptr,sizeof(int8_t),1,ptr_myfile);
		printf("%.2x %.2x %.2x %.2x at %d \n",*(mem_ptr), *(mem_ptr-1), *(mem_ptr-2), *(mem_ptr-3), counter);
		mem_ptr ++;

	}

	return;
}

void writeMem2Bin(FILE *ptr_myfile, uint32_t * reg){
	fclose(ptr_myfile);

	int k = 0;

	ofstream file(savename, ios::binary);
	while(k<32){
		file.write((char*)reg,sizeof(uint32_t));
		reg++;
		k++;
	}

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
				printf("\n %.3d " , i/4+1);
			}
		printf("%.2x ", *mem_ptr);

		mem_ptr++;
	}
}
