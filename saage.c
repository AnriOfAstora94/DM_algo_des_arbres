#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "saage.h"

void indente(FILE * f, int  i){
    if(i < 0)           //Pas d'indentations requises
        return;
    for(int j = 0; j < i; j++){
        fprintf(f, "    ");     //Une tabulation par i
    }
}
int serialise_aux(FILE * f, Arbre A, int i){
    if(!A)                                      //Arbre vide
        return 0;
    indente(f, i);
    fprintf(f, "Valeur : %s\n", A->val);        //On écrit la valeur
    if(!A->fg){                                 //Pas de fils gauche
        indente(f, i);
        fprintf(f, "Gauche : NULL\n");
    }
    else{                                       //On écrit le fils gauche
        indente(f, i);
        fprintf(f, "Gauche : \n");
        serialise_aux(f, A->fg, i+1);
    }
    if(!A->fd){                                 //Pas de fils droit
        indente(f, i);
        fprintf(f, "Droite : NULL\n");
    }
    else{                                       //On écrit le fis droit
        indente(f, i);
        fprintf(f, "Droite : \n");
        serialise_aux(f, A->fd, i+1);
    }
    return 1;                                   //Tout s'est bien passé
}


int serialise(char * nom_de_fichier, Arbre A){
    FILE *f = fopen(nom_de_fichier, "w");       //Ouvre le fichier
    int i = 0;
    if(!f){                                     //Problème d'ouverture
        fclose(f);
        return 0;
    }
    if(!serialise_aux(f, A, i)){ // si la sérialisation a échoué on supprime le fichier texte
        int len = 7 + strlen(nom_de_fichier);
        char cmd[len];
        strcpy(cmd, "rm -f ");
        strcat(cmd, nom_de_fichier);
        fclose(f);
        system(cmd);
        return 0;
    }
    fclose(f);
    return 1;
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

int recherche_val(const char *chaine, char *resultat) {

    const char *motif = "Valeur : ";        //la chaîne de caractères que l'on cherche à retirer
    size_t longueurMotif = strlen(motif);   

    const char *positionMotif = strstr(chaine, motif);  //On cherche le motif dans notre chaîne

    if (positionMotif == NULL) {            //Si l'on ne trouve pas le motif return 0
        return 0;
    }

    strcpy(resultat, positionMotif + longueurMotif);    //On copie la chaîne dans la chaîne resultat (val) en partant de "Valeur : " + sa longueur pour s'en débarasser

    return 1;       //Tout s'est bien passé
}


int deserialise_aux(FILE * f, Arbre *A){
    char val[100];      //Stockera la valeur à insérer dans le noeud
    if(!f)
        return 0;
    char c[100];        //Stocke la ligne à lire
    
    fgets(c, 512, f);               //Récupère la ligne à lire
    suppr_Espaces_Debut(c);
    c[strcspn(c, "\n")] = '\0';     //Remplace le \n à la fin de la ligne par un fin de chaîne

    recherche_val(c, val);
    *A = alloue_noeud(val);         //On alloue la valeur
    fgets(c, 512, f);               //Récupère la ligne à lire
    suppr_Espaces_Debut(c);
    c[strcspn(c, "\n")] = '\0';     //Remplace le \n à la fin de la ligne par un fin de chaîne

    if(!strcmp(c, "Gauche : "))     //On fait le sous-arbre gauche s'il existe
        deserialise_aux(f, &(*A)->fg);
    fgets(c, 512, f);               //Récupère la ligne à lire
    suppr_Espaces_Debut(c);
    c[strcspn(c, "\n")] = '\0';     //Remplace le \n à la fin de la ligne par un fin de chaîne

    if(!strcmp(c, "Droite : "))     //On fait le sous-arbre gauche s'il existe
        deserialise_aux(f, &(*A)->fd);
    return 1;                       //Tout s'est bien passé
}


int deserialise(char * nom_de_fichier, Arbre * A){
    FILE *f = fopen(nom_de_fichier, "r");       
    if(!f){         //Test si le fichier est correctement ouvert
        fclose(f);
        return 0;
    }
    deserialise_aux(f, A);
    fclose(f);      //Ferme le fichier une fois la déserialisation terminée
    return 1;
}
