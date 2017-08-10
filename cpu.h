#ifndef CPU
#define CPU

#define AND 	0b00000
#define EOR 	0b00001
#define SUB 	0b00010
#define RSB 	0b00011
#define ADD 	0b00100
#define XCHG 	0b00101
#define MOV_OP	0b00110
#define MOV_IMM	0b10110
#define MVN_OP	0b00111
#define MVN_IMM	0b10111
#define MULL	0b01000
#define END	0b01111

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
