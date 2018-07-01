#include <malloc.h>
#include "stackInArray.h"

void pushElem(struct stackInArray** stack, int num) { //можно сделать bool, чтобы проверять переполнение стека
	if (*stack == NULL) {
		*stack = (struct stackInArray*)malloc(sizeof(struct stackInArray));
		(*stack)->sizeOfStack = SIZE_STACK;
		(*stack)->arr = (int*)malloc(sizeof(int)*SIZE_STACK);
		(*stack)->indexOfTop = -1;
	}
	(*stack)->arr[(*stack)->indexOfTop + 1] = num;
	(*stack)->indexOfTop++;
}

int* popElem(struct stackInArray** stack) {
	
	if ((*stack)->indexOfTop == -1) return NULL;

	(*stack)->indexOfTop--;
	return &(*stack)->arr[(*stack)->indexOfTop + 1];
}