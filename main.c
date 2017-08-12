#define FILE_READ_ERROR -100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdint.h>
#include "cpu.h"

int main()
{
	FILE* input = fopen("output.bin", "rb");
	uint32_t code, opcode;
	uint32_t dest, first, second;
	cpu* mycpu;

	if (input == NULL)
                return(FILE_READ_ERROR);
        else
        {
		create_cpu(&mycpu);		
		mycpu->work = 1;
		fread(&code, sizeof(uint32_t), 1, input);
		while (mycpu->work == 1)
		{
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
				case END:
					end(mycpu);
					break;
			}
			fseek(input, mycpu->adress / 8, SEEK_SET);
			fread(&code, sizeof(uint32_t), 1, input);
		}
		delete_cpu(&mycpu);
	}
	
	return 0;
}	
