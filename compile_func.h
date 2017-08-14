#ifndef FUNC
#define FUNC

#include "hash.h"
#include <stdint.h>

#define FULL_STR_LENGTH 30
#define COMMAND_LENGTH 20
#define MAX_LOOP_NAME_LENGTH 30
#define MAX_LENGTH_OF_STR 30

#define AND     0b00000000000000000000000000000000
#define EOR     0b00001000000000000000000000000000
#define SUB     0b00010000000000000000000000000000
#define RSB     0b00011000000000000000000000000000
#define ADD     0b00100000000000000000000000000000
#define XCHG    0b00101000000000000000000000000000
#define MOV_OP  0b00110000000000000000000000000000
#define MOV_IMM 0b10110000000000000000000000000000
#define MVN_OP  0b00111000000000000000000000000000
#define MVN_IMM 0b10111000000000000000000000000000
#define MULL    0b01000000000000000000000000000000
#define JMP 	0b01001000000000000000000000000000
#define CMP  	0b01010000000000000000000000000000
#define JE	0b01011000000000000000000000000000
#define CALL	0b01100000000000000000000000000000
#define RET	0b01101000000000000000000000000000
#define JNE	0b01110000000000000000000000000000
#define END     0b01111000000000000000000000000000

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

int loop(char* str, int start, uint32_t* result, HashTableType* hashTable);

#endif
