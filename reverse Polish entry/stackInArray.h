#ifndef STACK_IN_ARR

#define STACK_IN_ARR

#define SIZE_STACK 100

struct stackInArray {
	int sizeOfStack;
	int* arr;
	int indexOfTop;
};

void pushElem(struct stackInArray** stack, int num);
int* popElem(struct stackInArray** stack);

#endif // !STACK_IN_ARR