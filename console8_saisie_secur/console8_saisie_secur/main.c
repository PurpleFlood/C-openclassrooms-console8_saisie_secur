//
//  main.c
//  console8_saisie_secur
//
//  Created by asap on 15/04/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fgets(char *str, int num, FILE *stream);
int lire(char *str, int longueur);
long lireLong();
double lireDouble();
char * strchr (const char * str, int ch);
long strtol(const char *start, char **end, int base);
double strtod(const char *start, char **end);
void viderBuffer();

int main(int argc, const char * argv[]) {
    
    char nom[10];
    long age = 0;
    double poids=0;
    printf("Saisissez votre nom : ");
    lire(nom, 10);
    printf("Vous vous appelez %s.\n\n", nom);
    printf("Quel âge avez vous ? ");
    age = lireLong();
    printf("Vous avez %d ans !\n", age);
    printf("Quel est ton poids ? ");
    poids = lireDouble();
    printf("Tu fais %d kilos", poids);
    
    return 0;
}



int lire(char *str, int longueur){
    char *positionDEntree=NULL;
    
    if (fgets(str, longueur, stdin) != NULL){
        positionDEntree = strchr(str, '\n');
        if (positionDEntree != NULL){
            *positionDEntree = '\0';
        }
        else {
            viderBuffer();
        }
        return 1;
    }
    else {
        viderBuffer();
        return 0;
    }
}

long lireLong(){
    char nombreTexte[100] = {0};
    
    if (lire(nombreTexte, 100)){
        return strtol(nombreTexte, NULL, 10);
    }
    else {
        return 0;
    }
}

double lireDouble() {
    char nombreTexte[100] = {0};
    
    if (lire(nombreTexte, 100)) {
        
        nombreTexte = strch(",", '.');
        return strtod(nombreTexte, NULL);
    }
    else {
        return 0;
    }
}
void viderBuffer(){
    int c=0;
    while(c != '\n' && c != EOF) {
        c=getchar();
    }
}
