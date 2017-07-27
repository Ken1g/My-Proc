#ifndef FUNC
#define FUNC

/*	
/	Function translate (int dec) decimal number to (char* bin) binary number
/  where: (int pos) - place of the bit, where the binary number starts
/  	  (int length) - the length of translated binary number in string (char* bin)
*/
int dec_to_bin(int dec, char* bin, int pos, int length);


/*
/	Function translate instruction with 2 operands in (char* str) to binary code (char* result) and 4 bits of 1st operand fill with '0'
/  where: (int start) - the position in (char* str), where the first operand starts
*/
int two_operands_ignore_first(char* str, int start, char* result);


/*
/	Function translate instruction with 2 operands in (char* str) to binary code (char* result) and 4 bits of dest. operand fill with '0'
/  where: (int start) - the position in (char* str), where the first operand starts
*/
int two_operands_ignore_dest(char* str, int start, char* result);


/*
/       Function translate instruction with 3 operands in (char* str) to binary code (char* result) 
/  where: (int start) - the position in (char* str), where the first operand starts
*/
int three_operands(char* str, int start, char* result);

#endif
