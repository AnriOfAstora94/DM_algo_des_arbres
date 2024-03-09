/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#ifndef _ABR_
#define _ABR_

//Structure des arbres
typedef struct _noeud{
    char * val;
    struct _noeud *fg, *fd;
} Noeud, *Arbre;


/**
 * @brief La fonction affiche affiche un Arbre en faisant appel à affiche_aux et passe à la ligne une fois l'affichage terminé
 * 
 * @param a Arbre à afficher
 * 
 * @return void
*/
void affiche(Arbre a);

/**
 * @brief La fonction affiche_aux affiche les valeurs d'un arbre comme un parcours préfixe
 * 
 * @param a Arbre à afficher
 * 
 * @return void
*/
void affiche_aux(Arbre a);

/**
 * @brief La fonction alloue_noeud renvoie le noeud après l'avoir alloué en mémoire et initialisé sa valeur à s, renvoie NULL si l'allocation échoue
 * 
 * @param s La chaîne de caractère représentant la valeur à initialiser
 * 
 * @return Noeud
*/
Noeud * alloue_noeud(char *s);

/**
 * @brief La fonction liberer libère l'espace mémoire utilisé par un Arbre
 * 
 * @param A l'Arbre dont on libère la mémoire
 * 
 * @return void
*/
void liberer(Arbre * A);

/**
 * @brief La fonction cree_A_1 crée l'arbre A_1 donné dans les exemples du sujets
 * 
 * @return Arbre
*/
Arbre cree_A_1();

/**
 * La fonction cree_A_1 crée l'arbre A_1 donné dans les exemples du sujets
 * 
 * @return Arbre
*/
Arbre cree_A_2();

/**
 * @brief La fonction cree_A_1 crée l'arbre A_1 donné dans les exemples du sujets
 * 
 * @return Arbre
*/
Arbre cree_A_3();

/**
 * @brief La fonction construit_arbre permet de construire un arbre avec un parcours préfixe
 * 
 * @param a adresse de l'arbre qui sera construit
 * 
 * @return int
*/
int construit_arbre(Arbre *a);

/**
 * @brief La fonction construit_arbre_aux s'occupe du travail récursif de construit_arbre
 * 
 * @param a adresse de l'arbre qui sera construit
 * 
 * @return int
*/
int construit_arbre_aux(Arbre *a);

void ecrireDebut(FILE *f);
void ecrireFin(FILE *f);
void ecrireArbre(FILE *f, Arbre a);
void dessine(FILE *f, Arbre a);
void creePDF(char *dot, char *pdf, Arbre a);
#endif

