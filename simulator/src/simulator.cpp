//============================================================================
// Name        : simulator.cpp
// Author      : Pelle Schwartz, Ramus Menzer
// Version     :
// Copyright   : Please dont copy all of it
// Description : Risc-V Simulator
//============================================================================

#include "typenames.h"
#include <iostream>
using namespace std;


//function prototypes:
static int readBin2Mem(FILE *ptr_myfile, uint32_t * mem_ptr);




int main()
{
	printf("Testrun: \n");
	FILE *ptr_myfile; //file pointer
	uint32_t mem[2^12] = {0}; // Memory array, can be increased if needed.
	uint32_t reg[32] = {0}; // registers array
	uint32_t * mem_ptr = &mem[0];
	ptr_myfile = fopen("shift.bin","rb");

	int num_ins = readBin2Mem(ptr_myfile,mem_ptr);


	for (int i = 0; i < num_ins; i++){
		uint32_t instruction = *mem_ptr
		// TODO go through each instruction set.
				uint32_t val = 12;
		break;
	}



	return 0;
}


static int readBin2Mem(FILE *ptr_myfile, uint32_t * mem_ptr){
	unsigned int read = 0;
	int counter = 0;
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
		return 0;
	}
	fseek(ptr_myfile, 0, SEEK_END);
	int size = ftell(ptr_myfile)/4; // get current file pointer
	rewind(ptr_myfile);
	printf("size: %d \n",size);
	for ( counter=1; counter <= size; counter++)
	{
		fread(&read,sizeof(int32_t),1,ptr_myfile);

		printf("\n %.8X ", read);
		*mem_ptr = read;
		mem_ptr++;
	}
	fclose(ptr_myfile);
	return size;
}

