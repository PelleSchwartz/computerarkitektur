#define EXTRACT_OPCODE 0x3F         //31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 [6 5 4 3 2 1 0]
#define EXTRACT_R_RD 0xF80          //31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 [11 10 9 8 7] 6 5 4 3 2 1 0
#define EXTRACT_RBS_R1 0xF8000        //31 30 29 28 27 26 25 24 23 22 21 20 [19 18 17 16 15] 14 13 12 11 10 9 8 7 [6 5 4 3 2 1 0]
#define EXTRACT_RBS_R2 0x1F00000      //31 30 29 28 27 26 25 [24 23 22 21 20] 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
#define EXTRACT_IMM_11_0 0xFFF00000 //[31 30 29 28 27 26 25 24 23 22 21 20] 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0

#define EXTRACT_B_IMM_12 0x80000000   //[31] 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
#define EXTRACT_B_IMM_11 0x80         //31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 [7] 6 5 4 3 2 1 0
#define EXTRACT_B_IMM_10_5 0x7E000000 //31 [30 29 28 27 26 25] 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
#define EXTRACT_B_IMM_4_1 0xF00       //31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 [11 10 9 8] 7 6 5 4 3 2 1 0
