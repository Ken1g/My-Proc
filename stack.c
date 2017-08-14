#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102
#define INIT_SIZE 2 /* starting stack size */
#define ADD_SPACE 1 /* shows by how many elements the stack is increasing after resize function */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int create_stack(my_stack** new_stack) 
{
	*new_stack = malloc(sizeof(my_stack));
	if (*new_stack == NULL) 
		return(OUT_OF_MEMORY);
	(*new_stack)->size = INIT_SIZE;
	(*new_stack)->data = malloc((*new_stack)->size * sizeof(data_type)); 
	if ((*new_stack)->data == NULL) 
	{
		free(*new_stack);
		return(OUT_OF_MEMORY);
	}
	(*new_stack)->top = 0;
	return 0;
}

int delete_stack(my_stack** stack) 
{
	free((*stack)->data);
	free(*stack);
	*stack = NULL;
	return 0;
}

int resize(my_stack* stack)
{
	void* t;

	stack->size += ADD_SPACE;
	t = realloc(stack->data, stack->size * sizeof(data_type));
	if (t == NULL) 
		return(STACK_OVERFLOW);
	else
		stack->data = t;
	return 0;
}

int push(my_stack* stack, data_type* value) 
{
	int code = 0;
	
	if (stack->top >= stack->size) /* checks is it necessary to resize a stack */
		code = resize(stack);	       	
	if (code != 0)	      	
		return(code); /* if function "resize" failed,  return the error code */
	memcpy(stack->data + stack->top * sizeof(data_type), value, sizeof(data_type));
	stack->top++;
	return 0;
}

int pop(my_stack* stack, data_type* value) 
{
	if (stack->top <= 0) 
		return(STACK_UNDERFLOW);
	stack->top--;
	memcpy(value, stack->data + stack->top * sizeof(data_type), sizeof(data_type));
	return 0;
}

int peek(const my_stack* stack, data_type* value) 
{
	if (stack->top <= 0) 
		return(STACK_UNDERFLOW);
	memcpy(value, stack->data + (stack->top - 1) * sizeof(data_type), sizeof(data_type));
	return 0;
}





