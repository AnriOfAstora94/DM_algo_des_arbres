/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#ifndef _GREF_
#define _GREF_

#include "arbres_binaires.h"

/**
 * La fonction copie prends un Arbre en source et en produit une copie à l'adresse d'un autre Arbre également donné en paramètre, retourne 1 en cas de problème d'allocation, 0 sinon
 * @param dest L'adresse de l'arbre recevant la copie
 * @param source Arbre à copier
*/
int copie(Arbre * dest, Arbre source);

/**
 * Fonction qui greffe sur G le sous arbre gauche de n
 * @param G Arbre à greffer
 * @param n Noeud recevant la greffe
*/
int greffeG(Arbre * G, Noeud * n);

/**
 * Fonction qui greffe sur G le sous arbre droit de n
 * @param G Arbre à greffer
 * @param n Noeud recevant la greffe
*/
int greffeD(Arbre * G, Noeud * n);

/**
 * La fonction expansion effectue la greffe de B sûr l'arbre A donnés tout deux en paramètres
 * @param A Arbre recevant la greffe
 * @param B Arbre représentant le greffon
*/
int expansion(Arbre * A, Arbre B);


#endif

