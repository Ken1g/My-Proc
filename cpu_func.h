#ifndef CPU_FUNC
#define CPU_FUNC

/*
/  Function translate (char* bin) binary number to decimal number, where (int* result) is a pointer to it 
*/
int bin_to_dec(char* bin, int* result);


/*
/ Function parse binary instruction (char* code) and put into decode[0] - dest operand, into decode[1] - first op, int decode[2] - second op
*/
int three_op(char* code, int* decode);


/*
/ Function parse binary instruction (char* code) and put into decode[0] - dest operand, into decode[1] - second operand
/ and 4 bits of first operand are ignored
*/
int two_op_dest(char* code, int* decode);


/*
/ Function parse binary instruction (char* code) and put into decode[0] - first operand, into decode[1] - second operand
/ and 4 bits of destination operand are ignored
*/
int two_op_reg(char* code, int* decode);

#endif
