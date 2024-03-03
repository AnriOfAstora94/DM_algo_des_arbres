#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "saage.h"

void indente(FILE * f, int  i){
    if(i < 0)
        return;
    for(int j = 0; j < i; j++){
        fprintf(f, "    ");
    }
}
int serialise_aux(FILE * f, Arbre A, int i){
    if(!A)
        return 0;
    indente(f, i);
    fprintf(f, "Valeur : %s\n", A->val);
    if(!A->fg){
        indente(f, i);
        fprintf(f, "Gauche : NULL\n");
    }
    else{
        indente(f, i);
        fprintf(f, "Gauche :\n");
        serialise_aux(f, A->fg, i+1);
    }
    if(!A->fd){
        indente(f, i);
        fprintf(f, "Droite : NULL\n");
    }
    else{
        indente(f, i);
        fprintf(f, "Droite :\n");
        serialise_aux(f, A->fd, i+1);
    }
    return 1;
}


int serialise(char * nom_de_fichier, Arbre A){
    FILE *f = fopen(nom_de_fichier, "w");
    int i = 0;
    if(!f){
        fclose(f);
        return 0;
    }
    if(!serialise_aux(f, A, i)){
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

void supprimerEspacesDebut(char *chaine) {
    size_t longueur = strlen(chaine);
    size_t i = 0;

    // Trouver le premier caractère non vide
    while (i < longueur && isspace(chaine[i])) {
        i++;
    }

    // Déplacer les caractères non vides au début de la chaîne
    if (i > 0) {
        memmove(chaine, chaine + i, longueur - i + 1);
    }
}


int deserialise_aux(FILE * f, Arbre *A, int i){
    if(!f)
        return 0;
    indente(f, i);
    char c[100];
    fscanf(f, "%s", c);
    //printf("%s\n", c);
    if(!strcmp(c, "Valeur")){
        //printf("coucou ");
        fgetc(f);
        fgetc(f);
        fgetc(f);
        fscanf(f, "%s", c);
        *A = alloue_noeud(c);
        if(!(*A))
            return 0;
    fgetc(f);
    fgets(c, 512, f);
    supprimerEspacesDebut(c);
    if(strcmp(c, "Gauche :")){
        deserialise_aux(f, &(*A)->fg, i +1);
    }
    if(strcmp(c, "Gauche : NULL")){
        deserialise_aux(f, &(*A)->fd, i);
    }
    if(strcmp(c, "Droite :")){
        deserialise_aux(f, &(*A)->fd, i+1);
    }
    if(strcmp(c, "Droite : NULL")){
        deserialise_aux(f, &(*A)->fd, i-1);
    }
/*        indente(f, i);
        fscanf(f, "%49[^\n]%*c", c);
        printf("%s ", c);
        if(!strcmp(c, "Gauche : NULL")){
            (*A)->fg = NULL;
            indente(f, i);
            fscanf(f, "%49[^\n]%*c", c);
            if(!strcmp(c, "Droite : NULL")){
                (*A)->fd = NULL;
                return 1;
            }
            else{
                deserialise_aux(f, &(*A)->fd, i);
            }
        }
        printf("%s ", c);
        if(!strcmp(c, "Gauche :")){
            deserialise_aux(f, &(*A)->fg, i+1);
        }
        if(!strcmp(c, "Droite : NULL")){
            (*A)->fd = NULL;
            indente(f, i);
            fscanf(f, "%49[^\n]%*c", c);
            if(!strcmp(c, "Gauche : NULL")){
                (*A)->fg = NULL;
                return 1;
            }
            else{
                deserialise_aux(f, &(*A)->fg, i);
            }
        }
        if(!strcmp(c, "Droite :")){
            deserialise_aux(f, &(*A)->fd, i+1);
        }*/
    }
    return 1;
}


int deserialise(char * nom_de_fichier, Arbre * A){
    FILE *f = fopen(nom_de_fichier, "r");
    int i = 0;
    if(!f){
        fclose(f);
        return 0;
    }
    deserialise_aux(f, A, i);
    //aux(f,A,i, prec); fait pas attention
    fclose(f);
    return 1;
}




int aux(FILE * f, Arbre *A, int i, int * prec){
    char  c[100];

    while(fgets(c,512,f) != NULL){
        i++;
        printf("dans le while i =%d\n",i);
        char * mot = strstr(c, "Valeur"); 
        char * mot2 = strstr(c, "Gauche : NULL");
        char * mot3 = strstr(c, "Droite : NULL");
        char * mot4 = strstr(c, "Gauche");
        char * mot5 = strstr(c, "Droite");

        if(mot){ // On test si on trouve valeur dans la ligne lu par fgets
            char rep[100];
            strncpy(rep, mot + 9, strlen(mot + 9)-1);
            printf("i = %d val : %s\n",i, rep);
            *A = alloue_noeud(rep);
            if(!*A){
                printf("Erreur d'allocation");
                return -1;
            }
        }

        if(mot3 && *prec == 1){
            printf("dans la cond d'arret i =%d\n",i);
            return 0;
        }

        if(mot2){
            printf("dans le gauche NULL %d\n", i);
            *prec = 1;
            (*A)->fg = NULL;
        }else if(mot4){
            printf("dans le gauche %d\n",i);
            *prec = 0;
            return aux(f,&(*A)->fg, i, prec);
        }
        if(mot3){
            printf("dans le droite NULL i = %d\n", i);
            (*A)->fd = NULL;
        }else if(mot5){
            printf("dans le droite i = %d\n", i);   
            *prec = 0;  
            return aux(f,&(*A)->fd, i,prec);
        }
    } 
    return 1;
}
