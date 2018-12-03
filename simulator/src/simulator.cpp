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
using namespace std;



//function prototypes:
void readBin2Mem(FILE *ptr_myfile, uint8_t * mem_ptr, int * size_ptr);
void printReg(uint32_t* reg_ptr, int size);
void printMem(uint8_t* mem_ptr, int size);
void writeMem2Bin(FILE *ptr_myfile, uint32_t * reg);
int main()
{
	printf("Testrun: \n");
	FILE *ptr_myfile; //file pointer
	ptr_myfile = fopen("addpos.bin","rb");

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

//		printf("\n NEXT LINE \n \n");
//
//		printf("memory step : %d \n",(prgm_counter - &mem[0])/4);
//		printf("%.2X ", *prgm_counter);
//		printf("%.2X ", *(prgm_counter+1));
//		printf("%.2X ", *(prgm_counter+2));
//		printf("%.2X \n", *(prgm_counter+3));

		uint16_t upper = (uint16_t(*(prgm_counter+3)) << 8) | uint16_t(*(prgm_counter+2));
		uint16_t lower = (uint16_t(*(prgm_counter+1)) << 8) | uint16_t(*(prgm_counter+0));
		uint32_t ins = (uint32_t(upper) << 16) | lower;

		printf("%.8X \n" , ins);


		line instruction;
		instruction.instr = ins;
		instruction.name = 0;
		instruction.type = '\0';


		if(mem[1]==0x164){

			printf("breaK!");

		}



		decoder(instruction);
		//printf("Instr name : %d \n" , instruction.name);
		if (instruction.name == I_ECALL){
			printf("ECALL\n \n");
			printReg(reg_ptr,32);
			break;
		}
		prgm_counter = doInstruction(instruction, prgm_counter, reg_ptr, &mem[0]);
		instructionsrunsofar++;
		mem[0] = 0; //x0 should always be 0
//		printf("Instructions run so far : %d ", instructionsrunsofar);
//		if(reg[1] == 0x0160){
//			printf("Warning x0 reassigned!");
//		}

	}

	ptr_myfile = fopen("result.res","w+");

	writeMem2Bin(ptr_myfile, reg_ptr);
	printReg(reg_ptr,32);

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
	fclose(ptr_myfile);
	*numins = size;
//
//	string filename = "loop.bin";
//	int i = 0;
//	streampos fileSize;
//
//	char * temporaryMemory;
//	temporaryMemory = new char [2];
//
//	ifstream file (filename, ios::in|ios::binary|ios::ate);//open file and set pointer at end of file
//	if (file.is_open())
//	{
//		cout << "file is open" << endl;
//		fileSize = file.tellg(); //use pointer to get file size
//		file.seekg (0, ios::beg); //set pointer to beginning of file
//		while(file.tellg() <= fileSize-(streampos)2){
//			file.read (temporaryMemory, 2*sizeof(char)); //should also update file pointer
//			*mem_ptr = (uint8_t)temporaryMemory[0];
//			mem_ptr++;
//			i++;
//			*mem_ptr = (uint8_t)temporaryMemory[1];
//			mem_ptr++;
//			i++;
//		}
//		cout << "done reading in data" << endl;
//	}else {
//		cout << "Unable to open file" << endl;
//		return;
//	}
//	*numins = i/4;
	return;
}

void writeMem2Bin(FILE *ptr_myfile, uint32_t * reg){
	uint32_t * reg_ptr = &reg[0];

	rewind(ptr_myfile);
		fwrite(reg, 32*sizeof(uint32_t)-1, 1, ptr_myfile);
		reg_ptr ++;

	//	for(int i =0; i < 32;i++){
//		fwrite(reg_ptr,sizeof(int32_t),1,ptr_myfile);
//		reg_ptr++;
//	}
	fclose(ptr_myfile);

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
