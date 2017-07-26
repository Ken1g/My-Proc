#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "cpu_func.h"

int bin_to_dec(char* bin, int length, int* result)
{
	int i, deg;

	*result = 0;
	deg = 1;
	for (i = (length - 1); i >= 0; i--)
	{
		if (bin[i] == '1')
		*result  += deg;
		deg *= 2;
	}

	return 0;
}

int three_op(char* code, int* decode)
{
	int i;
	char* op;

	op = malloc(sizeof(char) * 19);
	for (i = 5; i <= 8; i++)
		op[i - 5] = code[i];
	bin_to_dec(op, 4, &decode[0]);
	for (i = 9; i <= 12; i++)
		op[i - 9] = code[i];
	bin_to_dec(op, 4, &decode[1]);
	for (i = 13; i <= 31; i++)
		op[i - 13] = code[i];
	bin_to_dec(op, 19, &decode[2]);
	free(op);
	
	return 0;
}

int two_op_dest(char* code, int* decode)
{	
	int i;
        char* op;

        op = malloc(sizeof(char) * 19);
        for (i = 5; i <= 8; i++)
                op[i - 5] = code[i];
        bin_to_dec(op, 4, &decode[0]);
        for (i = 13; i <= 31; i++)
                op[i - 13] = code[i];
        bin_to_dec(op, 19, &decode[1]);
        free(op);

        return 0;
}

int two_op_reg(char* code, int* decode)
{ 
        int i;
        char* op;

        op = malloc(sizeof(char) * 19);
        for (i = 9; i <= 12; i++)
                op[i - 9] = code[i];
        bin_to_dec(op, 4, &decode[0]);
        for (i = 13; i <= 31; i++)
                op[i - 13] = code[i];
        bin_to_dec(op, 19, &decode[1]);
        free(op);

        return 0;
}

