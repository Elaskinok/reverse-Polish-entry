#include <stdlib.h>
#include <stdio.h>

#include "stackInArray.h"
#include "processingStack.h"

#define INPUT_STRING_SIZE 1024
#define BUFF_STRING_SIZE 100

void printError() {
	printf("error");
	system("pause > NUL");
}

int main(int argc, char* argv[]) {

	struct stackInArray* stack = NULL;

	char* inputString = (char*)malloc(sizeof(char)*INPUT_STRING_SIZE);

	fgets(inputString, INPUT_STRING_SIZE - 1, stdin);

	if (inputString[0] == '\n') {
		printError();
		return 0;
	}

	int i = 0;

	do {
		char* buffString = (char*)calloc(BUFF_STRING_SIZE, sizeof(char));
		int q = 0;

		while (inputString[i] != ' ' && inputString[i] != '\0' && inputString[i] != '\n') {
			buffString[q] = inputString[i];
			i++;
			q++;
		}

		if ((buffString[0] >= '0' && buffString[0] <= '9') || (buffString[0] == '-' && buffString[1] >= '0' && buffString[1] <= '9')) {
			int n = atoi(buffString);
			pushElem(&stack, n);
		}
		else {
			if (!doOperation(stack, *buffString)) {
				printError();
				break;
			}
		}

		while (inputString[i] == ' ') i++;

	} while (inputString[i] != '\0' && inputString[i] != '\n');

	free(inputString);

	if (stack->indexOfTop == 0) {
		printf("%d", stack->arr[0]);
		system("pause > NUL");
	}
	else {
		printError();
	}

	return 0;
}