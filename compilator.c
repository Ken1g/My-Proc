#define FILE_READ_ERROR -100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "compile_func.h"

int main()
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	char* fullstr; 
	char* command;
	char* code;
	int i, eno;
	
	fullstr = malloc(sizeof(char) * 30);
	command = malloc(sizeof(char) * 5);
	code = malloc(sizeof(char) * 35);
	if (input == NULL)
		return(FILE_READ_ERROR);
	else
	{
		fgets(fullstr, 30, input);
		while(fullstr != NULL)
		{
			i = 0;
			memset(command, '\000', 4); /*clean the string*/
			while (fullstr[i] != ' ')
			{
				command[i] = fullstr[i];				
				i++;
			}
			memset(code, '\000', 35); 
			if (strcmp(command, "and") == 0)
                        {
                                strcat(code, "00000");
                                eno = three_operands(fullstr, 5, code);
                        }
			else if (strcmp(command, "eor") == 0)
                        {
                                strcat(code, "00001");
                                eno = three_operands(fullstr, 5, code);
                        }
			else if (strcmp(command, "sub") == 0)
			{
				strcat(code, "00010");
				eno = three_operands(fullstr, 5, code);				
			}
			else if (strcmp(command, "rsb") == 0)
                        {
                                strcat(code, "00011");
                                eno = three_operands(fullstr, 5, code);
                        }
			else if (strcmp(command, "add") == 0)
			{
                                strcat(code, "00100");
				eno = three_operands(fullstr, 5, code);
                        }
			else if (strcmp(command, "xchg") == 0)
                        {
                                strcat(code, "00101");
                                eno = two_operands_ignore_dest(fullstr, 6, code);
                        }
			else if (strcmp(command, "mov") == 0)
                        {
				if (fullstr[8] == 'r')
                                	strcat(code, "00110");
				else 
					strcat(code, "10110");
				eno = two_operands_ignore_first(fullstr, 5, code);
                        }
			else if (strcmp(command, "mvn") == 0)
                        {
                                if (fullstr[8] == 'r')
                                        strcat(code, "00111");
                                else
                                        strcat(code, "10111");
                                eno = two_operands_ignore_first(fullstr, 5, code);
                        }
			else if (strcmp(command, "mull") == 0)
                        {
                                strcat(code, "01000");
                                eno = three_operands(fullstr, 6, code);
                        }
			if (eno != 0) 
				return(eno);
			printf("%s\n", code);
			fputs(code, output);
			fullstr = fgets(fullstr, 50, input);
		}	
	}
	free(code);
	free(fullstr);
	free(command);
	fclose(input);
	fclose(output);
	
	return 0;
}

