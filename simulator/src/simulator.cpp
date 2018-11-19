//============================================================================
// Name        : simulator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




#include <iostream>
using namespace std;







static int readBin2Mem(FILE *ptr_myfile, uint32_t * mem_ptr){
	unsigned int read = 0;
	int counter = 0;
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
		return 0;
	}
	fseek(ptr_myfile, 0, SEEK_END);
	int size = ftell(ptr_myfile); // get current file pointer
	rewind(ptr_myfile);
	printf("size: %d \n",size);
	for ( counter=1; counter <= size/4; counter++)
	{
		fread(&read,sizeof(int32_t),1,ptr_myfile);

		printf("\n %.8X ", read);
		*mem_ptr = read;
		mem_ptr++;
	}
	fclose(ptr_myfile);
	return counter;
}



int main()
{
	printf("Testrun: \n");
	FILE *ptr_myfile; //file pointer
	uint32_t mem[2^12]; // Memory array, can be increased if needed.
	uint32_t reg[32]; // registers array
	uint32_t * mem_ptr = &mem[0];
	ptr_myfile = fopen("shift.bin","rb");

	int instructions = readBin2Mem(ptr_myfile,mem_ptr);

	printf(" \n %X" , *mem_ptr);
	for (int i = 0; i < instructions; i++){

		// TODO go through each instruction set.

		break;
	}



	return 0;
}
