#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* queueInit() {
	Queue* queue = NULL;
	queue = malloc(sizeof(queue));
	if (queue == NULL)
		exit(EXIT_FAILURE);

	queue->firstElt = NULL;
	queue->length = 0;
	return queue;
}

int queisempty(Queue* queue) {
	if (queue->length == 0)
		return 0;
	else
		return 1;
}

Queue* queunshift(Queue* queue, TYPE value) {
	QueElt* newElt = NULL;
	newElt = malloc(sizeof(newElt));
	if (newElt == NULL)
		exit(EXIT_FAILURE);

	newElt->value = value;
	newElt->nextElt = queue->firstElt;
	queue->firstElt = newElt;

	queue->length++;
	return queue;
}

int quesize(Queue* queue) {
	return queue->length;
}

void queprint(Queue* queue) {
	if (queue->length == 0)
		exit(EXIT_FAILURE);

	QueElt* elt = queue->firstElt;
	printf("[");
	while (elt != NULL) {
		printf(SPECIFIER, elt->value);
		elt = elt->nextElt;
		if (elt != NULL)
			printf(", ");
	}
	printf("]\n");
}

TYPE queshift(Queue* queue) {
	if (queue->length == 0) {
		printf("Error: queue is empty\n");
		exit(EXIT_FAILURE);
	}

	QueElt* eltToRemove = NULL;
	if (queue->length == 1) {
		eltToRemove = queue->firstElt;
		queue->firstElt = NULL;
	}

	else {
		QueElt* previousElt = queue->firstElt;
		while (previousElt->nextElt->nextElt != NULL)
			previousElt = previousElt->nextElt;
		eltToRemove = previousElt->nextElt;
		previousElt->nextElt = NULL;
	}

	TYPE value = eltToRemove->value;
	free(eltToRemove);
	queue->length--;
	return value;
}

void queclear(Queue* queue) {
	while (queue->firstElt > 0)
		queshift(queue);
	free(queue);
}
