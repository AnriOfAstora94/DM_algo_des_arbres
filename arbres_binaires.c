/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "arbres_binaires.h"



Noeud * alloue_noeud(char *s){
    Noeud * new = (Noeud *)malloc(sizeof(Noeud));
    if(!new){                                       //Teste si l'allocation est un succès
        fprintf(stderr, "Erreur d'allocation");
        return NULL;
    }
    new->val = (char *)malloc(strlen(s) + 1);
    if(!new->val){                                  //Teste le malloc
        fprintf(stderr, "Erreur d'allocation");
        free(new);
        return NULL;
    }
    strcpy(new->val, s);
    new->fg = NULL;
    new->fd = NULL;
    return new;         //On renvoie la valeure créée
}

void liberer(Arbre *A){
    if(*A){                 //Si l'arbre existe on libère le fg puis fd puis le noeud
        liberer(&(*A)->fg);
        liberer(&(*A)->fd);
        free((*A)->val);
        free(*A);
        *A = NULL;
    }
}



Arbre cree_A_1(){
    Arbre a = alloue_noeud("arbre");
    if(!a)                              //Test des allocations
        return NULL;
    a->fg = alloue_noeud("binaire");
    if(!a->fg){
        liberer(&a);
        return NULL;
    }
    a->fd = alloue_noeud("ternaire");
    if(!a->fd){
        liberer(&a);
        return NULL;
    }
    return a;       //On renvoie l'arbre construit
}

Arbre cree_A_2(){
    Arbre a = alloue_noeud("Anémone");
    if(!a)
        return NULL;
    a->fg = alloue_noeud("Camomille");
    if(!a->fg){
        liberer(&a);
        return NULL;
    }
    a->fd = alloue_noeud("Camomille");
    if(!a->fd){
        liberer(&a);
        return NULL;
    }
    a->fd->fg = alloue_noeud("Dahlia");
    if(!a->fd->fg){
        liberer(&a);
        return NULL;
    }
    a->fd->fg->fd = alloue_noeud("Camomille");
    if(!a->fd->fg->fd){
        liberer(&a);
        return NULL;
    }
    a->fd->fg->fd->fg = alloue_noeud("Iris");
    if(!a->fd->fg->fd){
        liberer(&a);
        return NULL;
    }
    a->fd->fg->fd->fd = alloue_noeud("Jasmin");
    if(!a->fd->fg->fd->fd){
        liberer(&a);
        return NULL;
    }
    return a;       //On renvoie l'arbre construit
}

Arbre cree_A_3(){
    Arbre a = alloue_noeud("Intel Core i9");
    if(!a)
        return NULL;
    a->fg = alloue_noeud("Apple M3 Max");
    if(!a->fg){
        liberer(&a);
        return NULL;
    }
    a->fg->fd = alloue_noeud("AMD Ryzen 9");
    if(!a->fg->fd){
        liberer(&a);
        return NULL;
    }
    a->fg->fd->fg = alloue_noeud("Intel Core i9");
    if(!a->fg->fd->fg){
        liberer(&a);
        return NULL;
    }
    a->fd = alloue_noeud("Intel Core i9");
    if(!a->fd){
        liberer(&a);
        return NULL;
    }
    a->fd->fg = alloue_noeud("Intel Core i9");
    if(!a->fd->fg){
        liberer(&a);
        return NULL;
    }
    return a;       //On renvoie l'arbre construit
}


void suppr_Espaces_Debut(char *chaine) {
    size_t longueur = strlen(chaine);   //Stock la longeur de la chaîne
    size_t i = 0;

    while (i < longueur && isspace(chaine[i])) {    //Tant qu'on trouve un espace ou qu'on est pas sorti de la chaîne on supprime et on passe au suivant
        i++;
    }

    if (i > 0) {
        memmove(chaine, chaine + i, longueur - i + 1);  //On remet le début de la chaîne au début de la chaîne
    }
}


int construit_arbre(Arbre *a){
    int vide_ou_non;
    printf("Entrez 1 + la chaine de caractère ou 0 (ex : 1 arbre || 0 ) : \n");
    scanf("%d", &vide_ou_non);

    if(vide_ou_non)                     //On fait un parcours préfixe
        return construit_arbre_aux(a);

    return 0;   // On fait rien
}

int construit_arbre_aux(Arbre *a){
    int sous_arbre_gauche;
    int sous_arbre_droit;
    char donnee[50];    
    fgets(donnee, 50, stdin);
    suppr_Espaces_Debut(donnee);
    donnee[strcspn(donnee, "\n")] = '\0'; //Remplace le \n à la fin de la ligne par un fin de chaîne
    *a = alloue_noeud(donnee); //Attribue la valeur du noeud
    if(!*a){
        printf("Erreur d'allocation\n");
        return -1;
    }     
    printf("Y-a t'il un sous-arbre gauche ? (ex : 1 binaire || 0 ) \n");   //Sous-arbre gauche
    scanf("%d", &sous_arbre_gauche);
    if(sous_arbre_gauche)   //Test s'il y a un sous-arbre gauche
        construit_arbre_aux(&(*a)->fg);
    
    printf("Y-a t'il un sous-arbre droit ? (ex : 1 ternaire || 0) \n");   //Sous-arbre droit
    scanf("%d", &sous_arbre_droit);
    if(sous_arbre_droit)   //Test s'il y a un sous-arbre droit
        construit_arbre_aux(&(*a)->fd);

    return 1;   //On a fini tout s'est bien passé (pas d'erreur de malloc dans alloue_noeud)

}




