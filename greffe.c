/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "greffe.h"




int copie(Arbre * dest, Arbre source){
    if(!source)
        return 1;

    (*dest) = alloue_noeud(source->val);
    if(!(*dest)){
        fprintf(stderr, "Echec allocation");
        return 0;
    }

    if(!copie(&(*dest)->fg, source->fg) || !copie(&(*dest)->fd, source->fd)){// Si une copie échoue on s'arrête.
        liberer(dest); // on libère l'arbre
        return 0;
    }
    return 1;
}


int greffeG(Arbre * G, Noeud * n){
    if(!*G)
        return 0;
    if(!(*G)->fg){
        if(!copie(&(*G)->fg, n->fg)){
            printf("Echec de la copie\n");
            return 0;
        }
        
    }else{
        greffeG(&(*G)->fg, n);
        greffeD(&(*G)->fg, n);
    }
    return 1;
}

int greffeD(Arbre *G, Noeud * n){
    if(!*G)
        return 0;
    if(!(*G)->fd){
        if(!copie(&(*G)->fd, n->fd)){
            printf("Echec de la copie\n");
            return 0;
        }
    }else{
        greffeD(&(*G)->fd, n);
        greffeG(&(*G)->fd, n);
    }
    return 1;
}


int expansion(Arbre * A, Arbre B){
    if(!*A)
        return 0;
    if(strcmp((*A)->val, B->val) == 0 ){
        expansion(&(*A)->fg, B);
        expansion(&(*A)->fd, B);
        Arbre G = NULL;
        if(!copie(&G, B)){
            printf("Echec de la copie\n");
            return 0;
        }       
        if(!greffeG(&G, *A) ||!greffeD(&G, *A)){
            free(&G);
            return 0;
        }  
        liberer(A);
        (*A) = G;        
        return 1;
    }
    expansion(&(*A)->fg, B);
    expansion(&(*A)->fd, B);
    return 1;
}
