#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "structure.h"
int main()
{
    Etudiant *eleve;
    int taille=0;
    printf("Entrer le  nombre d'Etudiant dans la classe: ");
    scanf("%d",&taille);
    eleve =(Etudiant*) malloc(sizeof(Etudiant)*taille);
    Affiche_premierPage(eleve,taille);
   return 0;
}