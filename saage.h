#ifndef __SAAGE__
#define __SAAGE__
#include <stdlib.h>
#include <stdio.h>
#include "arbres_binaires.h"


/**
 * @brief La fonction indente gère l'indentation lors de l'écriture d'un fichier saage
 * 
 * @param f le fichier sûr lequel on écrit l'indentation
 * @param i le nombre d'indentation
 * 
 * @return int
*/
void indente(FILE * f, int  i);

/**
 * @brief La fonction serialise_aux fait le récursivité
 * 
 * @param f le fichier saage recevant la sérialisation
 * @param A l'arbre à sérialiser
 * @param i un entier pour gérer l'indentation
 * 
 * @return int
*/
int serialise_aux(FILE * f, Arbre A, int i);


/**
 * @brief La fonction serialise produit le fichier saage associé à un arbre en mémoire
 * 
 * @param nom_de_fichier le nom du fichier stockant la sérialisation
 * @param A l'arbre à sérialiser
 * 
 * @return int
*/
int serialise(char * nom_de_fichier, Arbre A);

/**
 * @brief La fonction suppr_Espaces_Debut supprime les espaces au début d'une chaîne de caractère
 * 
 * @param chaine la chaîne dont on supprime les espaces
 * 
 * @return void
*/
void suppr_Espaces_Debut(char *chaine);

/**
 * @brief La fonction recherche_val extrait la valeur dans une ligne de fichier saage contenant une valeur
 * 
 * @param chaine la chaîne où l'on effectue la recherche
 * @param resultat la chaîne où l'on stocke le résultat
 * 
 * @return int
*/
int recherche_val(const char *chaine, char *resultat);

/**
 * @brief La fonction deserialise_aux produit un arbre en mémoire à partir d'un fichier saage
 * 
 * @param f le fichier à déserialiser
 * @param A l'adresse de l'arbre recevant la déserialisation
 * 
 * @return int
*/
int deserialise_aux(FILE * f, Arbre *a);

/**
 * @brief La fonction deserialise produit un Arbre à partir d'un fichier saage
 * 
 * @param nom_de_fichier le nom du fichier stockant la sérialisation
 * @param A l'aresse de l'arbre recevant la desérialisation
 * 
 * @return int
*/
int deserialise(char * nom_de_fichier, Arbre * A);

#endif

