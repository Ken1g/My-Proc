#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "compile_func.h"

int dec_to_bin(int dec, char* bin, int pos, int length)
{
	int max = 1;
	int i;
	int k;
	for  (i = 1; i < length; i++)
		max = max * 2;
	i = pos;
	while (max != 0)
	{
		k = dec / max;
		if (k == 1) 
			bin[i] = '1';
		else
			bin[i] = '0';
		dec = dec - k * max;
		max /= 2;
		i++;
	}
	
	return 0;
}

int two_operands_ignore_first(char* str, int start, char* result)
{
 	char* op1;
        char* op3;
        char* bin;
        int iop1, iop2, iop3;
        int i, k;

        op1 = malloc(sizeof(char) * 5);
        op3 = malloc(sizeof(char) * 20);
        k = 0;
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
	iop2 = 0;
        iop3 = atoi(op3);
        free(op1);
        free(op3);
        dec_to_bin(iop1, result, 5, 4);
        dec_to_bin(iop2, result, 9, 4);
        dec_to_bin(iop3, result, 13, 19);

        return 0;
}

int two_operands_ignore_dest(char* str, int start, char* result)
{
        char* op2;
        char* op3;
        char* bin;
        int iop1, iop2, iop3;
        int i, k;

        op2 = malloc(sizeof(char) * 5);
        op3 = malloc(sizeof(char) * 20);
        k = 0;
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
        iop1 = 0;
        iop2 = atoi(op2);
        iop3 = atoi(op3);
        free(op2);
        free(op3);
        dec_to_bin(iop1, result, 5, 4);
        dec_to_bin(iop2, result, 9, 4);
        dec_to_bin(iop3, result, 13, 19);

        return 0;
}

int three_operands(char* str, int start, char* result)
{
	char* op1;
	char* op2;
	char* op3;
	char* bin;
	int iop1, iop2, iop3;
	int i, k;
	
	op1 = malloc(sizeof(char) * 5);
	op2 = malloc(sizeof(char) * 5);
	op3 = malloc(sizeof(char) * 20);
	k = 0;
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
	dec_to_bin(iop1, result, 5, 4);
	dec_to_bin(iop2, result, 9, 4);
	dec_to_bin(iop3, result, 13, 19);	
	
	return 0;
}

		
	
