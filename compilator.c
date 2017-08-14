#define FILE_READ_ERROR -100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include "compile_func.h"
#include "hash.h"

int main()
{
	FILE* input = fopen("call.txt", "r");
	FILE* output = fopen("output.bin", "wb");
	char* fullstr; 
	char* command;
	char* loopname;
	uint32_t code;
	int ILC = 0x0;
	int i;
	HashTableType* hashTable;
	
	fullstr = malloc(sizeof(char) * FULL_STR_LENGTH);
	command = malloc(sizeof(char) * COMMAND_LENGTH);
	loopname = malloc(sizeof(char) * MAX_LOOP_NAME_LENGTH);
	if (input == NULL)
		return(FILE_READ_ERROR);
	else
	{
//////////////////////////////// FIRST RUN ///////////////////////////////////////
		
		hashTable = create_HashTable(hashTable);
		fullstr = fgets(fullstr, MAX_LENGTH_OF_STR, input);
               	while(strcmp(fullstr, "\n") != 0)	// TODO: change the type of stop strcmp	
             	{
			if (fullstr[strlen(fullstr) - 2] == ':')
			{
				memset(loopname, '\000', MAX_LOOP_NAME_LENGTH);
				for (i = 0; i < strlen(fullstr) - 2; i++)
					loopname[i] = fullstr[i];
				create_Node(loopname, ILC, hashTable);
			}
			else
				ILC += 0x20;          
                        fullstr = fgets(fullstr, MAX_LENGTH_OF_STR, input);
		}
		rewind(input);
		
//////////////////////////////// SECOND RUN //////////////////////////////////////
		
		fullstr = fgets(fullstr, MAX_LENGTH_OF_STR, input);
		while(strcmp(fullstr, "\n") != 0)
		{
			i = 0;
			memset(command, '\000', COMMAND_LENGTH); 
			while (fullstr[i] != ' ' && fullstr[i] != ':' && fullstr[i] != '\n') 
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
                                code = EOR;
                                three_operands(fullstr, 5, &code);
                        }
			else if (strcmp(command, "sub") == 0)
			{
				code = SUB;
				three_operands(fullstr, 5, &code);				
			}
			else if (strcmp(command, "rsb") == 0)
                        {
                                code = RSB;
                                three_operands(fullstr, 5, &code);
                        }
			else if (strcmp(command, "add") == 0)
			{
                                code = ADD;
				three_operands(fullstr, 5, &code);
                        }
			else if (strcmp(command, "xchg") == 0)
                        {
                                code = XCHG;
                                two_operands_ignore_dest(fullstr, 6, &code);
                        }
			else if (strcmp(command, "mov") == 0)
                        {
				if (fullstr[8] == 'r')
                                	code = MOV_OP;
				else 
					code = MOV_IMM;
				two_operands_ignore_first(fullstr, 5, &code);
                        }
			else if (strcmp(command, "mvn") == 0)
                        {
                                if (fullstr[8] == 'r')
					code = MVN_OP;
                                else 
					code = MVN_IMM;
				two_operands_ignore_first(fullstr, 5, &code);
			}
			else if (strcmp(command, "mull") == 0)
                        {
                                code = MULL;
                                three_operands(fullstr, 6, &code);
                        }
			else if (strcmp(command, "jmp") == 0)
			{
				code = JMP;
				loop(fullstr, 4, &code, hashTable);
			}
			else if (strcmp(command, "je") == 0)
			{
				code = JE;
				loop(fullstr, 3, &code, hashTable);
			}
			else if (strcmp(command, "cmp") == 0)
			{
				code = CMP;
				two_operands_ignore_dest(fullstr, 5, &code);
			}
			else if (strcmp(command, "jne") == 0)
			{
				code = JNE;
				loop(fullstr, 4, &code, hashTable);
			}
			else if (strcmp(command, "call") == 0)
                        {
                                code = CALL;
                                loop(fullstr, 5, &code, hashTable);
                        }
			else if (strcmp(command, "ret") == 0)
                        {
                                code = RET;
                        }
			else if (strcmp(command, "end") == 0)
			{
				code = END;
			}
			else
			{
				fullstr = fgets(fullstr, MAX_LENGTH_OF_STR, input);
				continue;
			}
			fwrite(&code, sizeof(uint32_t), 1, output);
			fullstr = fgets(fullstr, MAX_LENGTH_OF_STR, input);
		}
	}
	
	delete_HashTable(hashTable);
	free(fullstr);
	free(command);
	free(loopname);
	fclose(input);
	fclose(output);

	return 0;
}

