#define FILE_READ_ERROR -100
//#define
//#define

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "compile_func.c"

int main()
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	char* fullstr; 
	char* command;
	char* code;
	int i;
	
	fullstr = malloc(sizeof(char) * 50);
	command = malloc(sizeof(char) * 5);
	code = malloc(sizeof(char) * 35);
	if (input == NULL)
		return(FILE_READ_ERROR);
	else
	{
		fullstr = fgets(fullstr, 50, input);
		while(fullstr != NULL)
		{
			i = 0;
			memset(command, '\000', 4);
			while (fullstr[i] != ' ')
			{
				command[i] = fullstr[i];				
				i++;
			}
			memset(code, '\000', 35); /*"clean this string"*/
			if (strcmp(command, "and") == 0)
                        {
                                strcat(code, "00000");
                                three_operands(fullstr, 5, code);
                        }
			else if (strcmp(command, "eor") == 0)
                        {
                                strcat(code, "00001");
                                three_operands(fullstr, 5, code);
                        }
			else if (strcmp(command, "sub") == 0)
			{
				strcat(code, "00010");
				three_operands(fullstr, 5, code);				
			}
			else if (strcmp(command, "rsb") == 0)
                        {
                                strcat(code, "00011");
                                three_operands(fullstr, 5, code);
                        }
			else if (strcmp(command, "add") == 0)
			{
                                strcat(code, "00100");
				three_operands(fullstr, 5, code);
                        }
			else if (strcmp(command, "xchg") == 0)
                        {
                                strcat(code, "00101");
                                two_operands_ignore_dest(fullstr, 6, code);
                        }
			else if (strcmp(command, "mov") == 0)
                        {
				if (fullstr[8] == 'r')
                                	strcat(code, "00110");
				else 
					strcat(code, "10110");
				two_operands_ignore_first(fullstr, 5, code);
                        }
			else if (strcmp(command, "mvn") == 0)
                        {
                                if (fullstr[8] == 'r')
                                        strcat(code, "00111");
                                else
                                        strcat(code, "10111");
                                two_operands_ignore_first(fullstr, 5, code);
                        }
			else if (strcmp(command, "mull") == 0)
                        {
                                strcat(code, "01000");
                                three_operands(fullstr, 6, code);
                        }
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

