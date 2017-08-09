#define FILE_READ_ERROR -100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include "compile_func.h"

int main()
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	char* fullstr; 
	char* command;
	uint32_t code;
	int i;
	
	fullstr = malloc(sizeof(char) * 30);
	command = malloc(sizeof(char) * 5);
	if (input == NULL)
		return(FILE_READ_ERROR);
	else
	{
		fullstr = fgets(fullstr, 30, input);
		while(strcmp(fullstr, "end\n") != 0)
		{
			i = 0;
			memset(command, '\000', 4); /* clean the string */
			while (fullstr[i] != ' ') 
			{
				command[i] = fullstr[i];				
				i++;
			} 
			if (strcmp(command, "and") == 0)
                        {
                                code = 0;
                                three_operands(fullstr, 5, &code);
                        }
			else if (strcmp(command, "eor") == 0)
                        {
                                code = 0b00001 << 27;
                                three_operands(fullstr, 5, &code);
                        }
			else if (strcmp(command, "sub") == 0)
			{
				code = 0b00010 << 27;
				three_operands(fullstr, 5, &code);				
			}
			else if (strcmp(command, "rsb") == 0)
                        {
                                code = 0b00011 << 27;
                                three_operands(fullstr, 5, &code);
                        }
			else if (strcmp(command, "add") == 0)
			{
                                code = 0b00100 << 27;
				three_operands(fullstr, 5, &code);
                        }
			else if (strcmp(command, "xchg") == 0)
                        {
                                code = 0b00101 << 27;
                                two_operands_ignore_dest(fullstr, 6, &code);
                        }
			else if (strcmp(command, "mov") == 0)
                        {
				if (fullstr[8] == 'r')
                                	code = 0b00110 << 27;
				else 
					code = 0b10110 << 27;
				two_operands_ignore_first(fullstr, 5, &code);
                        }
			else if (strcmp(command, "mvn") == 0)
                        {
                                if (fullstr[8] == 'r')
					code = 0b00111 << 27;
                                else 
					code = 0b10111 << 27;
				two_operands_ignore_first(fullstr, 5, &code);
			}
			else if (strcmp(command, "mull") == 0)
                        {
                                code = 0b01000 << 27;
                                three_operands(fullstr, 6, &code);
                        }
			fprintf(output, "%u\n", code);
			fullstr = fgets(fullstr, 50, input);
		}	
		code = 0b01111 << 27;
		fprintf(output, "%u\n", code);
	}
	free(fullstr);
	free(command);
	fclose(input);
	fclose(output);
	
	return 0;
}

