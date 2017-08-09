#ifndef CPU
#define CPU

typedef struct cpu
{
	int reg[16];
	int r;
	int work;
} cpu;

int create_cpu(cpu** new_cpu);

int delete_cpu(cpu** cpu);

int and(int dest, int first, int second, cpu* cpu);

int eor(int dest, int first, int second, cpu* cpu);

int sub(int dest, int first, int second, cpu* cpu);

int rsb(int dest, int first, int second, cpu* cpu);

int add(int dest, int first, int second, cpu* cpu);

int xchg(int first, int second, cpu* cpu);

int mov(int immediate, int dest, int second, cpu* cpu);

int mvn(int immediate, int dest, int second, cpu* cpu);

int mull(int dest, int first, int second, cpu* cpu);

int end(cpu* cpu);

#endif
