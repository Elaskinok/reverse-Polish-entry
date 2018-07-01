#include <stdlib.h>
#include "stackInArray.h"


int foo(struct stackInArray* stack,char symbol) {
	
	int num1, num2;

	int* buff = popElem(&stack);
	if (buff != NULL) num1 = *buff;
	else return 0;


	buff = popElem(&stack);
	if (buff != NULL) num2 = *buff;
	else return 0;

	switch (symbol) {
	case '*':
		pushElem(&stack, num1*num2);
		break;
	case '/':
		pushElem(&stack, num2 / num1);
		break;
	case '+':
		pushElem(&stack, num2 + num1);
		break;
	case '-':
		pushElem(&stack, num2 - num1);
		break;
	}

	return 1;
}