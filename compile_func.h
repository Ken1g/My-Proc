#ifndef FUNC
#define FUNC

#include "hash.h"
#include <stdint.h>

#define FULL_STR_LENGTH 30
#define COMMAND_LENGTH 20
#define MAX_LOOP_NAME_LENGTH 30
#define MAX_LENGTH_OF_STR 30

#define AND     0b00000 << 27
#define EOR     0b00001 << 27
#define SUB     0b00010 << 27
#define RSB     0b00011 << 27
#define ADD     0b00100 << 27
#define XCHG    0b00101 << 27
#define MOV_OP  0b00110 << 27
#define MOV_IMM 0b10110 << 27
#define MVN_OP  0b00111 << 27
#define MVN_IMM 0b10111 << 27
#define MULL    0b01000 << 27
#define JMP 	0b01001 << 27
#define CMP  	0b01010 << 27
#define JE	0b01011 << 27
#define CALL	0b01100 << 27
#define RET	0b01101 << 27
#define JNE	0b01110 << 27
#define END     0b01111 << 27

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
