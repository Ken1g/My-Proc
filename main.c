#define FILE_READ_ERROR -100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdint.h>
#include "cpu.h"
#include "stack.h"

int main()
{
	FILE* input = fopen("output.bin", "rb");
	uint32_t code, opcode;
	uint32_t dest, first, second;
	uint32_t* binary;
	int size, i;
	cpu* mycpu;

	if (input == NULL)
                return(FILE_READ_ERROR);
        else
        {
		fseek(input, 0, SEEK_END);     
    		size = ftell(input);  
		rewind(input);
		binary = (uint32_t*) calloc(size / 4, sizeof(uint32_t));
		for (i = 0; i < size / 4; i++)
		fread(&binary[i], sizeof(int32_t), 1, input);
		fclose(input);		
		create_cpu(&mycpu);		
		mycpu->work = 1;
		while (mycpu->work == 1)
		{
			code = binary[mycpu->adress / 32];
			opcode = code >> 27;
			dest = (code << 5) >> 28;
			first = (code << 9) >> 28;
			second = (code << 13) >> 13;
			switch(opcode)
			{
				case AND:
					and(dest, first, second, mycpu);
					break;
				case EOR:
					eor(dest, first, second, mycpu);
					break;
				case SUB:
					sub(dest, first, second, mycpu);
					break;
				case RSB: 
					rsb(dest, first, second, mycpu);
					break;
				case ADD:
					add(dest, first, second, mycpu);
					break;
				case XCHG:
					xchg(first, second, mycpu);
					break;
				case MOV_OP:
					mov(0, dest, second, mycpu);
					break;
				case MOV_IMM:
					mov(1, dest, second, mycpu);
					break;
				case MVN_OP:
					mvn(0, dest, second, mycpu);
					break;
				case MVN_IMM:
					mvn(1, dest, second, mycpu);
					break;
				case MULL:
					mull(dest, first, second, mycpu);
					break;
				case JMP:
					jmp(second, mycpu);
					break;
				case JE:
					je(second, mycpu);
					break;
				case CMP:
					cmp(first, second, mycpu);
					break;
				case JNE:
					jne(second, mycpu);
					break;
				case CALL:
					call(second, mycpu);
					break;
				case RET:
					ret(mycpu);
					break;
				case END:
					end(mycpu);
					break;
			}
		}
		printf("r1 = %d r2 = %d r3 = %d r4 = %d\n", mycpu->reg[1], mycpu->reg[2], mycpu->reg[3], mycpu->reg[4]);
		delete_cpu(&mycpu);
		free(binary);
	}
	
	return 0;
}	
