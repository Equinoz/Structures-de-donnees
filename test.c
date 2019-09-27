#include <stdio.h>
#include "lklt.h"

int main(int argc , char* argv[]) {
	int entiers[6] = {25, 46, 12, 2, 33, 35};
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
	printf("Normalement rien\n");
	lkltprint(liste);
	return 0;
}

