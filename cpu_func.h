#ifndef CPU_FUNC
#define CPU_FUNC

int bin_to_dec(char* bin, int length, int* result);
int three_op(char* code, int* decode);
int two_op_dest(char* code, int* decode);
int two_op_reg(char* code, int* decode);

#endif
