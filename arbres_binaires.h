/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#ifndef _ABR_
#define _ABR_


typedef struct _noeud{
    char * val;
    int ind;
    struct _noeud *fg, *fd;
} Noeud, *Arbre;


void affiche(Arbre a);

void affiche_aux(Arbre a);

/*
Fonction qui renvoie l'adresse du noeud le plus profond ayant comme val la chaine de caractère contenu
dans * s 
*/
Noeud * recherche_plus_profond(Arbre a, char *s);

Noeud * alloue_noeud(char *s);

void liberer(Arbre * A);

Arbre cree_A_1();

Arbre cree_A_2();

Arbre cree_A_3();


#endif

