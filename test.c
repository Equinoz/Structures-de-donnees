#include <stdio.h>
#include "lklt.h"
#include "stack.h"

int main(int argc , char* argv[]) {
	int entiers[6] = {25, 46, 12, 2, 33, 35};

	//*** Listes chaînées ***
	printf("***** Listes chaînées *****\n");
	Lklt *liste = lkltinit();
	for (int i=0; i<6; i++)
		lkltappend(liste, entiers[i]);
	lkltinsert(liste, 88, 3);
	printf("[25, 46, 12, 88, 2, 33, 35] (normalement)\n");
	lkltprint(liste);
	printf("Indice 4: %d, Normalement: 2\n", lkltget(liste, 4));
	printf("Taille de la liste: %d, Normalement: 7\n", lkltlength(liste));
	lkltappend(liste, 45);
	printf("Suppression de l'index 3: %d, Normalement: 88\n", lkltremove(liste, 3));
	lkltremove(liste, 4);
	printf("[25, 46, 12, 2, 35, 45] (normalement)\n");
	lkltprint(liste);
	printf("Taille de la liste: %d, Normalement: 6\n", lkltlength(liste));
	lkltdel(liste);

	//*** Piles ***
	printf("\n***** Piles *****\n");
	Stack *pile = stackInit();
	printf("Pile normalement vide, vaut: %d\n", staisempty(pile));
	for (int i=0; i<6; i++)
		stapush(pile, entiers[i]);
	printf("Pile normalement remplie, vaut: %d\n", staisempty(pile));
	printf("Taille de la pile: %d, Normalement: 6\n", stasize(pile));
	printf("[35, 33, 2, 12, 46, 25] (normalement)\n");
	staprint(pile);
	printf("Element supprimé: %d, Normalement: 35\n", stapop(pile));
	printf("Element supprimé: %d, Normalement: 33\n", stapop(pile));
	printf("Taille de la pile: %d, Normalement: 4\n", stasize(pile));
	printf("[2, 12, 46, 25] (normalement)\n");
	staprint(pile);
	printf("Element de tête non dépilé: %d, Normalement: 2\n", stapeek(pile));
	for (int i=0; i<4; i++)
		stapop(pile);
	printf("Taille de la pile: %d, Normalement: 0\n", stasize(pile));
	printf("Pile normalement vide, vaut: %d\n", staisempty(pile));
	staclear(pile);
	printf("Normalement rien\n");
	staprint(pile);

	return 0;
}

