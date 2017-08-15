#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include "compile_func.h"
#include "hash.h"

int two_operands_ignore_first(char* str, int start, uint32_t* result)
{
 	char* op1;
        char* op3;
        int iop1, iop2, iop3;
        int i;

        op1 = malloc(sizeof(char) * 5);
        op3 = malloc(sizeof(char) * 20);
        i = start;
        while (str[i] != ',')
        {
                op1[i - start] = str[i];
                i++;
        }
        start = i + 3;
        i = start;
        while  (str[i] != '\n')
        {
                op3[i - start] = str[i];
                i++;
        }
        iop1 = atoi(op1);
        iop3 = atoi(op3);
        free(op1);
        free(op3);
	*result = *result | (iop1 << 23) | iop3;

        return 0;
}

int two_operands_ignore_dest(char* str, int start, uint32_t* result)
{
        char* op2;
        char* op3;
        int iop1, iop2, iop3;
        int i;

        op2 = malloc(sizeof(char) * 5);
        op3 = malloc(sizeof(char) * 20);
        i = start;
        while (str[i] != ',')
        {
                op2[i - start] = str[i];
                i++;
        }
        start = i + 3;
        i = start;
        while  (str[i] != '\n')
        {
                op3[i - start] = str[i];
                i++;
        }
        iop2 = atoi(op2);
        iop3 = atoi(op3);
        free(op2);
        free(op3);
        *result = *result | (iop2 << 19) | iop3;

        return 0;
}

int three_operands(char* str, int start, uint32_t* result)
{
	char* op1;
	char* op2;
	char* op3;
	int iop1, iop2, iop3;
	int i;
	
	op1 = malloc(sizeof(char) * 5);
	op2 = malloc(sizeof(char) * 5);
	op3 = malloc(sizeof(char) * 20);
	i = start;
	while (str[i] != ',')
	{
		op1[i - start] = str[i];
		i++;
	}
	start = i + 3;
	i = start;
	while  (str[i] != ',')
	{
                op2[i - start] = str[i];
                i++;
        }
	start = i + 3;
	i = start;
	while  (str[i] != '\n')
        {
                op3[i - start] = str[i];
                i++;
        }
	iop1 = atoi(op1);
	iop2 = atoi(op2);
	iop3 = atoi(op3);
	free(op1);
	free(op2);
	free(op3);
        *result = *result | (iop1 << 23) | (iop2 << 19) | iop3;

	return 0;
}

int loop(char* str, int start, uint32_t* result, HashTableType* hashTable)
{
	char* loopname;
	Node* node;
	int i, address;

	loopname = (char*) calloc(20, sizeof(char));
	i = start;
	while (str[i] != '\n')
        {
                loopname[i - start] = str[i];
                i++;
        }

	node = find_Node(loopname, hashTable);
	address = node->address;
	free(loopname);
	*result = *result | address;

	return 0;
}
