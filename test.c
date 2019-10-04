#include <stdio.h>
#include "lklt.h"
#include "stack.h"
#include "queue.h"

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
	printf("Elément supprimé: %d, Normalement: 35\n", stapop(pile));
	printf("Elément supprimé: %d, Normalement: 33\n", stapop(pile));
	printf("Taille de la pile: %d, Normalement: 4\n", stasize(pile));
	printf("[2, 12, 46, 25] (normalement)\n");
	staprint(pile);
	printf("Elément de tête non dépilé: %d, Normalement: 2\n", stapeek(pile));
	for (int i=0; i<4; i++)
		stapop(pile);
	printf("Taille de la pile: %d, Normalement: 0\n", stasize(pile));
	printf("Pile normalement vide, vaut: %d\n", staisempty(pile));
	staclear(pile);

	//*** Files ***
	printf("\n***** Files *****\n");
	Queue *file = queueInit();
	printf("File normalement vide, vaut: %d\n", queisempty(file));
	for (int i=0; i<6; i++)
		queunshift(file, entiers[i]);
	printf("File normalement remplie, vaut: %d\n", queisempty(file));
	printf("Taille de la file: %d, Normalement: 6\n", quesize(file));
	printf("[35, 33, 2, 12, 46, 25] (normalement)\n");
	queprint(file);
	printf("Elément supprimé: %d, Normalement: 25\n", queshift(file));
	printf("Elément supprimé: %d, Normalement: 46\n", queshift(file));
	printf("Taille de la file: %d, Normalement: 4\n", quesize(file));
	queunshift(file, 88);
	printf("[88, 35, 33, 2, 12] (normalement)\n");
	queprint(file);
	for (int i=0; i<5; i++)
		queshift(file);
	printf("Taille de la file: %d, Normalement: 0\n", quesize(file));
	printf("File normalement vide, vaut: %d\n", queisempty(file));
	queclear(file);
	printf("Normalement rien\n");
	queprint(file);

	return 0;
}

