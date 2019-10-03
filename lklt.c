#include <stdio.h>
#include <stdlib.h>
#include "lklt.h"

Lklt* lkltinit() {
	Lklt* lklt = NULL; 
	lklt = malloc(sizeof(lklt));
	if (lklt == NULL)
		exit(EXIT_FAILURE);

	lklt->firstElt = NULL;
	lklt->length = 0;
	return lklt;
}

Lklt* lkltappend(Lklt* lklt, TYPE value) {
	LkltElt* newElt = NULL;
	newElt = malloc(sizeof(newElt));
	if (newElt == NULL)
		exit(EXIT_FAILURE);

	newElt->value = value;
	newElt->nextElt = NULL;

	if (lklt->firstElt == NULL)
		lklt->firstElt = newElt;
	else {
		LkltElt *lastElt = lklt->firstElt;
		for (int i=0; i<lklt->length-1; i++)
			lastElt = lastElt->nextElt;
		lastElt->nextElt = newElt;
	}

	lklt->length++;
	return lklt;
}

int lkltlength(Lklt* lklt) {
	return lklt->length;
}

Lklt* lkltinsert(Lklt* lklt, TYPE value, int index){
	if (index > lklt->length-1) {
		printf("Error: index out of range\n");
		exit(EXIT_FAILURE);
	}

	LkltElt* newElt = NULL;
	newElt = malloc(sizeof(newElt));
	if (newElt == NULL)
		exit(EXIT_FAILURE);

	LkltElt *previousElt = lklt->firstElt;
	for (int i=1; i<index; i++)
		previousElt = previousElt->nextElt;

	newElt->value = value;
	newElt->nextElt = previousElt->nextElt;
	previousElt->nextElt = newElt;

	lklt->length++;
}

void lkltprint(Lklt* lklt){
	if (lklt->length == 0)
		exit(EXIT_FAILURE);

	LkltElt *elt = lklt->firstElt;
	printf("[");
	while (elt != NULL) {
		printf(SPECIFIER, elt->value);
		elt = elt->nextElt;
		if (elt != NULL)
			printf(", ");
	}
	printf("]\n");
}

TYPE lkltget(Lklt* lklt, int index) {
	if (index > lklt->length-1) {
		printf("Error: index out of range\n");
		exit(EXIT_FAILURE);
	}

	LkltElt *elt = lklt->firstElt;
	for (int i=0; i<index; i++)
		elt = elt->nextElt;
	return elt->value;
}

TYPE lkltremove(Lklt* lklt, int index) {
	if (index > lklt->length-1) {
		printf("Error: index out of range\n");
		exit(EXIT_FAILURE);
	}

	LkltElt *eltToRemove = NULL;
	if (index == 0) {
		eltToRemove = lklt->firstElt;
		lklt->firstElt = eltToRemove->nextElt;
	}
	else {
		LkltElt *previousElt = lklt->firstElt;
		for (int i=1; i<index; i++)
			previousElt = previousElt->nextElt;
		eltToRemove = previousElt->nextElt;
		previousElt->nextElt = eltToRemove->nextElt;
	}

	TYPE value = eltToRemove->value;
	free(eltToRemove);
	lklt->length--;
	return value;
}

void lkltdel(Lklt* lklt) {
	while (lklt->length > 0)
		lkltremove(lklt, 0);
	free(lklt);
}
