#ifndef STACK
#define STACK

#define INT

#ifdef INT
#define TYPE int
#define SPECIFIER "%d"
#endif

#ifdef DOUBLE
#define TYPE double
#define SPECIFIER "%f"
#endif

#ifdef CHAR
#define TYPE char
#define SPECIFIER "%c"
#endif

#endif

typedef struct StaElt StaElt;
struct StaElt{
	TYPE value;
	StaElt* nextElt;
};

typedef struct Stack Stack;
struct Stack {
	StaElt* eltHead;
	int length;
};

// Initialise une nouvelle pile
Stack* stackInit();

// Retourne 0 si la pile est vide, 1 sinon
int staisempty(Stack*);

// Empile un nouvel élément
Stack* stapush(Stack*, TYPE);

// Retourne le nombre d'élements contenus dans la pile
int stasize(Stack*);

// Affiche le contenu de la pile
void staprint(Stack*);

// Dépile et retourne l'élement dépilé
TYPE stapop(Stack*);

// Retourne l'élément de tête sans le dépiler
TYPE stapeek(Stack*);

// Supprime la pile
void staclear(Stack*);
