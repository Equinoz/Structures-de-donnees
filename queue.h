#ifndef QUEUE
#define QUEUE

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

typedef struct QueElt QueElt;
struct QueElt{
	TYPE value;
	QueElt* nextElt;
};

typedef struct Queue Queue;
struct Queue {
	QueElt* firstElt;
	int length;
};

// Initialise une nouvelle file
Queue* queueInit();

// Retourne 0 si la file est vide, 1 sinon
int queisempty(Queue*);

// Enfile un nouvel élément
Queue* queunshift(Queue*, TYPE);

// Retourne le nombre d'éléments contenus dans la file
int quesize(Queue*);

// Affiche le contenu de la file
void queprint(Queue*);

// Défile le dernier élément
TYPE queshift(Queue*);

// Supprime la file
void queclear(Queue*);
