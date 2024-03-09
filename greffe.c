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
        if(!copie(&(*G)->fg, n->fg)){  //Le fils gauche de G devient une copie du sous arbre gauche de n
            printf("Echec de la copie\n");
            return 0;
        }
        
    }else{
        greffeG(&(*G)->fg, n);      //Appelle recursive sur le fils gauche de G, pour faire une greffe sur tous les noeuds sans fils gauche
        greffeD(&(*G)->fg, n);      //Greffe sur tous les noeuds sans fils droit du sous arbre de gauche de G
    }
    return 1;
}

int greffeD(Arbre *G, Noeud * n){
    if(!*G)
        return 0;
    if(!(*G)->fd){                 // Pas de fils droit
        if(!copie(&(*G)->fd, n->fd)){ // Le fils droit de G devient une copie du sous arbre droit de n
            printf("Echec de la copie\n");
            return 0;
        }
    }else{
        greffeD(&(*G)->fd, n);      // Appelle recursive sur le fils droit de G, pour faire une greffe sur tous les noeuds sans fils droit
        greffeG(&(*G)->fd, n);      // Greffe sur tous les noeuds sans fils gauche du sous arbre de Droit de G
    }
    return 1;
}


int expansion(Arbre * A, Arbre B){
    if(!*A)                         //Arbre null
        return 0;
    if(strcmp((*A)->val, B->val) == 0 ){        //La valeur est égal, il faut faire une greffe
        expansion(&(*A)->fg, B);                //On verifie qu'il n'y ait pas de noeud dans le sous-arbre gauche 
        expansion(&(*A)->fd, B);                //et dans le sous_arbre droit ayant comme etiquette B->val
        Arbre G = NULL;
        if(!copie(&G, B)){                      //crée une copie de B
            printf("Echec de la copie\n");
            return 0;
        }       
        if(!greffeG(&G, *A) ||!greffeD(&G, *A)){    //Test si les greffes du sous-arbre gauche et droit se sont bien passées
            free(&G);
            return 0;
        }  
        liberer(A);
        (*A) = G; 
        return 1;
    }
    expansion(&(*A)->fg, B);        // Si la valeur est differente, on fait le sous-arbre gauche
    expansion(&(*A)->fd, B);        //On fait le sous-arbre droit
    return 1;                       //Tout s'est bien passé
}
