using namespace std;

void slli(line &instr, uint32_t * reg_ptr){
	uuint32_t *rd, *r1;
	int32_t imm = 0;

	imm = imm | ((instr.instr & EXTRACT_I_IMM_11_0)>>20);
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);

	*rd = *r1<<imm;
	printf("slli x%.2d, x%.2d, x%.2d\n", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}

void srai(line &instr, uint32_t * reg_ptr){
	uuint32_t *rd, *r1;
	int32_t imm = 0;

	imm = imm | ((instr.instr & EXTRACT_I_IMM_11_0)>>20);
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);

	*rd = (int32_t)(*r1)>>imm;
	printf("srai x%.2d, x%.2d, x%.2d\n", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}

void srli(line &instr, uint32_t * reg_ptr){
	uuint32_t *rd, *r1;
	int32_t imm = 0;

	imm = imm | ((instr.instr & EXTRACT_I_IMM_11_0)>>20);
	rd = reg_ptr+((instr.instr & EXTRACT_R_RD)>>7);
	r1 = reg_ptr+((instr.instr & EXTRACT_RBS_R1)>>15);

	*rd = *r1>>imm;
	printf("srli x%.2d, x%.2d, x%.2d\n", ((instr.instr & EXTRACT_R_RD)>>7) , ((instr.instr & EXTRACT_RBS_R1)>>15) , ((instr.instr & EXTRACT_RBS_R2)>>20));
}
