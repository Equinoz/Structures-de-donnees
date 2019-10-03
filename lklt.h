#ifndef LKLT
#define LKLT

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

typedef struct LkltElt LkltElt;
struct LkltElt{
	TYPE value;
	LkltElt* nextElt;
};

typedef struct Lklt Lklt;
struct Lklt {
	LkltElt* firstElt;
	int length;
};

// Initialise une nouvelle liste chaînée
Lklt* lkltinit();

// Ajoute un élément à la fin de la liste
Lklt* lkltappend(Lklt*, TYPE);

// Retourne la longueur de la liste chaînée
int lkltlength(Lklt*);

// Ajoute un nouvel élément à l'index passé en paramètre
Lklt* lkltinsert(Lklt*, TYPE, int);

// Affiche la liste chaînée
void lkltprint(Lklt*);

// Récupère la valeur à l'index donné
TYPE lkltget(Lklt*, int);

// Supprime un élément de la liste à l'index donné
TYPE lkltremove(Lklt*, int);

// Supprime la liste chaînée
void lkltdel(Lklt*);
