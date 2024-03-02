#ifndef __SAAGE__
#define __SAAGE__
#include <stdlib.h>
#include <stdio.h>
#include "arbres_binaires.h"


/**
 * La fonction serialise_aux fait le récursivité
 * @param f le fichier saage recevant la sérialisation
 * @param A l'arbre à sérialiser
 * @param i un entier pour gérer l'indentation
*/
void serialise_aux(FILE * f, Arbre A, int i);


/**
 * La fonction serialise produit le fichier saage associé à un arbre en mémoire
 * @param nom_de_fichier le nom du fichier stockant la sérialisation
 * @param A l'arbre à sérialiser
*/
int serialise(char * nom_de_fichier, Arbre A);

/**
 * La fonction deserialise_aux produit un arbre en mémoire à partir d'un fichier saage
 * @param f le fichier à déserialiser
 * @param A l'adresse de l'arbre recevant la déserialisation
 * @param i un entier pour gérer l'indentation
*/
void deserialisation(FILE * f, Arbre *a, int i);

/**
 * La fonction deserialise produit un Arbre à partir d'un fichier saage
 * @param nom_de_fichier le nom du fichier stockant la sérialisation
 * @param A l'aresse de l'arbre recevant la desérialisation
*/
int deserialise(char * nom_de_fichier, Arbre * A);

#endif

