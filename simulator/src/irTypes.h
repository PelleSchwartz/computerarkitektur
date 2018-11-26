
using namespace std;

void slli(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);

	*rd = *r1<<(*r2);
	printf("slli x%.2d, x%.2d, x%.2d\n", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}

void srai(line &instr, uint32_t * reg_ptr){
	uint32_t * rd, *r1;
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);
	r2 = reg_ptr+((instr.instr & EXTRACT_RBS_R2)>>20);
	*rd = (int32_t)*r1>>((int32_t)*r2);
	printf("srai x%.2d, x%.2d, x%.2d\n", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}
