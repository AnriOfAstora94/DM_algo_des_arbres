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
    if(!*G)                           //Greffon null
        return 0;
    if(!(*G)->fg){                    //Pas de fils gauche
        if(!copie(&(*G)->fg, n->fg)){
            printf("Echec de la copie\n");
            return 0;
        }
        
    }else{
        greffeG(&(*G)->fg, n);      //On greffe le sous-arbre gauche au fg
        greffeD(&(*G)->fg, n);      //On greffe le sous-arbre gauche au fd
    }
    return 1;
}

int greffeD(Arbre *G, Noeud * n){
    if(!*G)
        return 0;
    if(!(*G)->fd){                 //Pas de fils droit
        if(!copie(&(*G)->fd, n->fd)){
            printf("Echec de la copie\n");
            return 0;
        }
    }else{
        greffeD(&(*G)->fd, n);      //On greffe le sous-arbre droit au fd
        greffeG(&(*G)->fd, n);      //On greffe le sous-arbre droit au fg
    }
    return 1;
}


int expansion(Arbre * A, Arbre B){
    if(!*A)                         //Arbre null
        return 0;
    if(strcmp((*A)->val, B->val) == 0 ){        //La valeur est égal, il faut faire une greffe
        expansion(&(*A)->fg, B);                //On fait le sous-arbre gauche
        expansion(&(*A)->fd, B);                //On fait le sous-arbre droit
        Arbre G = NULL;
        if(!copie(&G, B)){                      //Cas d'échec de copie
            printf("Echec de la copie\n");
            return 0;
        }       
        if(!greffeG(&G, *A) ||!greffeD(&G, *A)){    //Test si les greffes du sous-agre gauche et droit se sont bien passés
            free(&G);
            return 0;
        }  
        liberer(A);
        (*A) = G;        
        return 1;
    }
    expansion(&(*A)->fg, B);        //On fait le sous-arbre gauche
    expansion(&(*A)->fd, B);        //On fait le sous-arbre droit
    return 1;                       //Tout s'est bien passé
}
