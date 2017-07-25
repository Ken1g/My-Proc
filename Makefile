all: compilator

compilator: compilator.o compile_func.o 
	gcc compilator.o compile_func.o -o compilator

compile_func.o: compile_func.c
	gcc -c compile_func.c

compilator.o: compilator.c
	gcc -c compilator.c

clean:
	rm -rf *.o compilator
