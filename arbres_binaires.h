/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#ifndef _ABR_
#define _ABR_


typedef struct _noeud{
    char * val;
    struct _noeud *fg, *fd;
} Noeud, *Arbre;


void affiche(Arbre a);

void affiche_aux(Arbre a);

/**
 * Fonction qui renvoie l'adresse du noeud le plus profond ayant comme val la chaine de caractère contenu dans * s
 * @param a Arbre a dont on recherche un élément
 * @param s La chaîne de caractère recherché
*/
Noeud * recherche_plus_profond(Arbre a, char *s);

/**
 * La fonction alloue_noeud renvoie le noeud après l'avoir alloué en mémoire et initialisé sa valeur à s, renvoie NULL si l'allocation échoue
 * @param s La chaîne de caractère représentant la valeur à initialiser
*/
Noeud * alloue_noeud(char *s);

/**
 * La fonction liberer libère l'espace mémoire utilisé par un Arbre
 * @param A l'Arbre dont on libère la mémoire
*/
void liberer(Arbre * A);

/**
 * La fonction cree_A_1 crée l'arbre A_1 donné dans les exemples du sujets
*/
Arbre cree_A_1();

/**
 * La fonction cree_A_1 crée l'arbre A_1 donné dans les exemples du sujets
*/
Arbre cree_A_2();

/**
 * La fonction cree_A_1 crée l'arbre A_1 donné dans les exemples du sujets
*/
Arbre cree_A_3();


#endif

