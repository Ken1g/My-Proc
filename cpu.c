#define FILE_READ_ERROR -100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "cpu_func.h"

int main()
{
	FILE* input = fopen("output.txt", "r");
	char* code;
	char* opcode;
	int r[16];
	int decode[3];
	int i, j;
	
	code = malloc(sizeof(char) * 33);
	opcode = malloc(sizeof(char) * 5);
	if (input == NULL)
		return(FILE_READ_ERROR);
	else
	{
		code = fgets(code, 33, input);
		while(code != NULL)
                {		
			for (i = 1; i <= 4; i++)
				opcode[i - 1] = code[i];			
			if (strcmp(opcode, "0000") == 0) /*AND*/
			{
				three_op(code, decode);
			}
			else if (strcmp(opcode, "0001") == 0) /*EOR*/
                        {
                                three_op(code, decode);
                        }
			else if (strcmp(opcode, "0010") == 0) /*SUB*/
                        {
                                three_op(code, decode);
				r[decode[0]] = r[decode[1]] - r[decode[2]];
                        }
			else if (strcmp(opcode, "0011") == 0) /*RSB*/
                        {
                                three_op(code, decode);
				r[decode[0]] = r[decode[2]] - r[decode[1]];
                        }
			else if (strcmp(opcode, "0100") == 0) /*ADD*/
                        {
                                three_op(code, decode);
				r[decode[0]] = r[decode[1]] + r[decode[2]];
                        }
			else if (strcmp(opcode, "0101") == 0) /*XCHG*/
                        {
                                
                        }
			else if (strcmp(opcode, "0110") == 0) /*MOV*/
                        {
				if (code[0] == '0')
				{
					two_op_dest(code, decode);
					r[decode[0]] = r[decode[1]];
				}
				else
				{
					two_op_dest(code, decode);
					r[decode[0]] = decode[1];
				}
			}
			else if (strcmp(opcode, "0111") == 0) /*MVN*/
                        {

                        }
			else if (strcmp(opcode, "1000") == 0) /*MULL*/
                        {
                                three_op(code, decode);
				r[decode[0]] = r[decode[1]] * r[decode[2]];
                        }
			code = fgets(code, 33, input);
			printf("%d\n", r[1]);
		}
	}
	free(code);
	fclose(input);
		
	return 0;
}

