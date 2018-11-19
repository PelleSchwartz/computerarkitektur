//============================================================================
// Name        : simulator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




#include <iostream>
using namespace std;


struct rec
{
	int x,y,z;
};


unsigned int
reverse(register unsigned int x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));

}



int main()
{
	printf("Testrun: \n");
	int counter;
	FILE *ptr_myfile;
	uint32_t mem[2^12];
	uint32_t reg[32];
	uint32_t * stack_ptr = &mem[0];



	unsigned int read = 0;
	ptr_myfile = fopen("shift.bin","rb");
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
		return 1;
	}
	fseek(ptr_myfile, 0, SEEK_END);
	int size = ftell(ptr_myfile); // get current file pointer
	rewind(ptr_myfile);
	printf("size: %d \n",size);
	for ( counter=1; counter <= size/4; counter++)
	{
		fread(&read,sizeof(int32_t),1,ptr_myfile);

		uint32_t n = read;

		printf("\n %.8X ", read);


	}
	fclose(ptr_myfile);
	return 0;
}


