#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* stackInit() {
	Stack* stack = NULL;
	stack = malloc(sizeof(stack));
	if (stack == NULL)
		exit(EXIT_FAILURE);

	stack->eltHead = NULL;
	stack->length = 0;
	return stack;
}

int staisempty(Stack* stack) {
	if (stack->length == 0)
		return 0;
	else
		return 1;
}

Stack* stapush(Stack* stack, TYPE value) {
	StaElt* newElt = NULL;
	newElt = malloc(sizeof(newElt));
	if (newElt == NULL)
		exit(EXIT_FAILURE);

	newElt->value = value;
	newElt->nextElt = stack->eltHead;
	stack->eltHead = newElt;

	stack->length++;
	return stack;
}

int stasize(Stack* stack) {
	return stack->length;
}

void staprint(Stack* stack) {
	if (stack->length ==0)
		exit(EXIT_FAILURE);

	StaElt *elt = stack->eltHead;
	printf("[");
	while (elt != NULL) {
		printf(SPECIFIER, elt->value);
		elt = elt->nextElt;
		if (elt != NULL)
			printf(", ");
	}
	printf("]\n");
}

TYPE stapop(Stack* stack) {
	if (stack->length == 0) {
		printf("Error: stack is empty\n");
		exit(EXIT_FAILURE);
	}

	StaElt *eltToRemove = NULL;
	eltToRemove = stack->eltHead;
	stack->eltHead = eltToRemove->nextElt;

	TYPE value = eltToRemove->value;
	free(eltToRemove);
	stack->length--;
	return value;
}

TYPE stapeek(Stack* stack) {
	if (stack->length == 0) {
		printf("Error: stack is empty\n");
		exit(EXIT_FAILURE);
	}

	return stack->eltHead->value;
}

void staclear(Stack* stack) {
	while (stack->length > 0)
		stapop(stack);
	free(stack);
}
