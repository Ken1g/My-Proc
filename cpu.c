#define OUT_OF_MEMORY   -102

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"

int create_cpu(cpu** new_cpu) 
{
	*new_cpu = malloc(sizeof(cpu));
	if (*new_cpu == NULL) 
	{	
		free(*new_cpu);
		return(OUT_OF_MEMORY);
	}
	
	return 0;
}

int delete_cpu(cpu** cpu) 
{
	free(*cpu);
	*cpu = NULL;
	
	return 0;
}

int and(int dest, int first, int second, cpu* cpu)
{
	cpu->reg[dest] = cpu->reg[first] & cpu->reg[second];

	return 0;
}

int eor(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[first] ^ cpu->reg[second];

        return 0;
}

int sub(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[first] - cpu->reg[second];

        return 0;
}

int rsb(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[second] - cpu->reg[first];

        return 0;
}

int add(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[first] + cpu->reg[second];

        return 0;
}

int xchg(int first, int second, cpu* cpu)
{
        cpu->r = cpu->reg[first];
	cpu->reg[first] = cpu->reg[second];
	cpu->reg[second] = cpu->r;
	
        return 0;
}

int mov(int immediate, int dest, int second, cpu* cpu)
{
        if (immediate == 0)
		cpu->reg[dest] = cpu->reg[second];
	else 
		cpu->reg[dest] = second; 

        return 0;
}

int mvn(int immediate, int dest, int second, cpu* cpu)
{
        if (immediate == 0)
                cpu->reg[dest] = ~(cpu->reg[second]);
        else
                cpu->reg[dest] = ~(second);

        return 0;
}

int mull(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[first] * cpu->reg[second];

        return 0;
}

int end(cpu* cpu)
{
	cpu->work = 0;
	
	return 0;
}
