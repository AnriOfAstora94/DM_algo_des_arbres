/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#ifndef _GREF_
#define _GREF_

#include "arbres_binaires.h"

int copie(Arbre * dest, Arbre source);

/*
Fonction qui greffe sur G le sous arbre gauche de N
*/
void greffeG(Arbre * G, Noeud * n);

/*
Fonction qui greffe sur G le sous arbre droit de N
*/
void greffeD(Arbre * G, Noeud * n);


int expansion(Arbre * A, Arbre B);


#endif

