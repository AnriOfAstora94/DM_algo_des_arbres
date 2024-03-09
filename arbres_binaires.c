/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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

void affiche_aux(Arbre a){      //affichage préfixe
    if(a){
        printf("%s ", a->val);
        affiche_aux(a->fg);
        affiche_aux(a->fd);
    }
}

void affiche(Arbre a){      //affichage préfixe
    if(a){
        affiche_aux(a);
        printf("\n");
    }
}

Arbre cree_A_1(){
    Arbre a = alloue_noeud("arbre");
    if(!a)                              //Test des allocations
        return NULL;
    a->fg = alloue_noeud("binaire");
    if(!a->fg){
        free(&a);
        return NULL;
    }
    a->fd = alloue_noeud("ternaire");
    if(!a->fd){
        free(&a);
        return NULL;
    }
    return a;       //On renvoie l'arbre construit
}

Arbre cree_A_2(){
    Arbre a = alloue_noeud("Anémone");
    a->fg = alloue_noeud("Camomille");
    a->fd = alloue_noeud("Camomille");
    a->fd->fg = alloue_noeud("Dahlia");
    a->fd->fg->fd = alloue_noeud("Camomille");
    a->fd->fg->fd->fg = alloue_noeud("Iris");
    a->fd->fg->fd->fd = alloue_noeud("Jasmin");
    return a;       //On renvoie l'arbre construit
}

Arbre cree_A_3(){
    Arbre a = alloue_noeud("Intel Core i9");
    a->fg = alloue_noeud("Apple M3 Max");
    a->fg->fd = alloue_noeud("AMD Ryzen 9");
    a->fg->fd->fg = alloue_noeud("Intel Core i9");
    a->fd = alloue_noeud("Intel Core i9");
    a->fd->fg = alloue_noeud("Intel Core i9");
    return a;       //On renvoie l'arbre construit
}

int construit_arbre(Arbre *a){
    int vide_ou_non;
    printf("Entrez 1 ou 0 (0 pour quitter, 1 pour entrez la racine) : \n");
    scanf("%d", &vide_ou_non);

    if(vide_ou_non)                     //On fait un parcours préfixe
        return construit_arbre_aux(a);

    return 0;   // On fait rien
}

int construit_arbre_aux(Arbre *a){
    int sous_arbre_gauche;
    int sous_arbre_droit;
    char donnee[50];

    printf("Entrez la valeur du noeud (50 caractères max) : \n");
    scanf("%s", donnee);
    *a = alloue_noeud(donnee);      //Attribue la valeur du noeud

    printf("Y-a t'il un sous-arbre gauche ? (1 = oui; 0 = non;) \n");   //Sous-arbre gauche
    scanf("%d", &sous_arbre_gauche);
    if(sous_arbre_gauche)   //Test s'il y a un sous-arbre gauche
        construit_arbre_aux(&(*a)->fg);
    
    printf("Y-a t'il un sous-arbre droit ? (1 = oui; 0 = non;) \n");   //Sous-arbre droit
    scanf("%d", &sous_arbre_droit);
    if(sous_arbre_droit)   //Test s'il y a un sous-arbre droit
        construit_arbre_aux(&(*a)->fd);

    return 1;   //On a fini tout s'est bien passé (pas d'erreur de malloc dans alloue_noeud)

}




