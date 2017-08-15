#define OUT_OF_MEMORY   -102

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"
#include "stack.h"

int create_cpu(cpu** new_cpu) 
{
	*new_cpu = malloc(sizeof(cpu));
	if (*new_cpu == NULL) 
	{	
		free(*new_cpu);
		return(OUT_OF_MEMORY);
	}
	(*new_cpu)->address = 0;
	create_stack(&((*new_cpu)->stack));
	return 0;
}

int delete_cpu(cpu** cpu) 
{
	delete_stack(&((*cpu)->stack));
	free(*cpu);
	*cpu = NULL;
	return 0;
}

int and(int dest, int first, int second, cpu* cpu)
{
	cpu->reg[dest] = cpu->reg[first] & cpu->reg[second];
	cpu->address += 0x4;	
	return 0;
}

int eor(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[first] ^ cpu->reg[second];
	cpu->address += 0x4;
        return 0;
}

int sub(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[first] - cpu->reg[second];
	cpu->address += 0x4;
        return 0;
}

int rsb(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[second] - cpu->reg[first];
	cpu->address += 0x4;
        return 0;
}

int add(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[first] + cpu->reg[second];
	cpu->address += 0x4;
        return 0;
}

int xchg(int first, int second, cpu* cpu)
{
        cpu->r = cpu->reg[first];
	cpu->reg[first] = cpu->reg[second];
	cpu->reg[second] = cpu->r;
	cpu->address += 0x4;
        return 0;
}

int mov(int immediate, int dest, int second, cpu* cpu)
{
        if (immediate == 0)
		cpu->reg[dest] = cpu->reg[second];
	else 
		cpu->reg[dest] = second; 
	cpu->address += 0x4;
        return 0;
}

int mvn(int immediate, int dest, int second, cpu* cpu)
{
        if (immediate == 0)
                cpu->reg[dest] = ~(cpu->reg[second]);
        else
                cpu->reg[dest] = ~(second);
	cpu->address += 0x4;
        return 0;
}

int mull(int dest, int first, int second, cpu* cpu)
{
        cpu->reg[dest] = cpu->reg[first] * cpu->reg[second];
	cpu->address += 0x4;
        return 0;
}

int end(cpu* cpu)
{
	cpu->work = 0;
	cpu->address += 0x4;
	return 0;
}

int jmp(int address, cpu* cpu)
{
	cpu->address = address;
	return 0;
}

int cmp(int first, int second, cpu* cpu)
{
	if (cpu->reg[first] == cpu->reg[second])
		cpu->cmp_reg = 1;
	else
		cpu->cmp_reg = 0;
	cpu->address += 0x4;
	return 0;	
}

int je(int address, cpu* cpu)
{
	if (cpu->cmp_reg)
		cpu->address = address;
	else
		cpu->address += 0x4;
	return 0;
}

int jne(int address, cpu* cpu)
{
        if (!cpu->cmp_reg)
                cpu->address = address;
        else
                cpu->address += 0x4;
        return 0;
}

int call(int address, cpu* cpu)
{
	cpu->address += 0x4;
	push(cpu->stack, &(cpu->address));
        cpu->address = address;
        return 0;
}

int ret(cpu* cpu)
{
	int address;
	
	pop(cpu->stack, &address);
	cpu->address = address;
	return 0;
}
