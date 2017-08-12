all: compilator

compilator: compilator.o compile_func.o hash.o
	gcc compilator.o compile_func.o hash.o -o compilator

compile_func.o: compile_func.c
	gcc -c compile_func.c

compilator.o: compilator.c
	gcc -c compilator.c

hash.o: hash.c
	gcc -c hash.c

clean:
	rm -rf *.o compilator
