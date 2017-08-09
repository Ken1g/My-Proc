#ifndef FUNC
#define FUNC

/*
/	Function translate instruction with 2 operands in (char* str) to binary code (int* result) and 4 bits of 1st operand fill with '0'
/  where: (int start) - the position in (char* str), where the first operand starts
*/
int two_operands_ignore_first(char* str, int start, unsigned int* result);


/*
/	Function translate instruction with 2 operands in (char* str) to binary code (int* result) and 4 bits of dest. operand fill with '0'
/  where: (int start) - the position in (char* str), where the first operand starts
*/
int two_operands_ignore_dest(char* str, int start, unsigned int* result);


/*
/       Function translate instruction with 3 operands in (char* str) to binary code (int* result) 
/  where: (int start) - the position in (char* str), where the first operand starts
*/
int three_operands(char* str, int start, unsigned int* result);

#endif
