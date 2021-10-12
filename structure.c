#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "structure.h"
 void espace(int taille,int taille_vid){
  int i=0;
  while(i<taille_vid-taille){
    printf(" ");
    i++;
  }
 }
int Liste_est_vide(Etudiant *el){
 int test=0;
 if((el)->age>1000){
    test=1;
 }
 return test;
}
void Messages(Etudiant *E,int taille){
 int autre_choix;
 printf("\n\n--------Voulez-vous faire une autre option??0-non/1-oui: ");
 scanf("%d",&autre_choix);
 if(autre_choix) {
    system("cls");
    Affiche_premierPage(E,taille);
 }
 else Fin_prog();
}
void Fin_prog(){
  system("cls");
  printf("\n+++++++FIN DU PROGRAMME++++\n");
  exit(1);
}
/*FONCTION POUR GERER LES LISTES DES ETUDIANT*/
void Saisir_ListEtudiant(Etudiant *E,int taille){
int i =0;
Etudiant *pt_Etd;
pt_Etd=E;
while(i<taille){
  printf("+++++Etudiant numero %d dans la liste++++\n",i+1);
  printf("NOM  et PRENOM : ");
  scanf("%s %s",(pt_Etd+i)->nom,(pt_Etd+i)->prenom);
  printf("AGE et Numero d'inscription(5 chiffre): ");
  scanf("%d %d",&(pt_Etd+i)->age,&(pt_Etd+i)->num_inscri);
  i++;
  }
 Messages(pt_Etd,taille);
}
void Modifier_Etudiant(Etudiant *el,int taille){
  int i=0,num;char nom[20],prenom[20];
   if(Liste_est_vide(el)){
        printf("\nLa Liste est vide\n");
        printf("Remplir la liste!!!!\n");
        Messages(el,taille);
   }else{
        printf("Entrer alors le num d'inscription d'etudiant a modifier: ");
        scanf("%d",&num);
        for(;i<taille;i++){
         if((el+i)->num_inscri==num){
           printf("Saisir Nom  et Prenom : ");
           scanf("%s %s",nom,prenom);
           strcpy((el+i)-> nom,nom);
           strcpy((el+i)-> prenom,prenom);
           printf("puis son age et numero d'inscription(5 chiffre): ");
           scanf("%d",&(el+i)->age);
          }
        }
       Messages(el,taille);
    }
 }
void Affiche_ListEtudiant(Etudiant *el,int taille){
 int i=0;
 if(Liste_est_vide(el)){
        printf("\nLa Liste est vide\n");
        printf("Remplir la liste!!!!\n");
        Messages(el,taille);
 }
 else{
         printf("\n+++++++++++++++++++AFFICHAGE LISTE+++++++++++++++++++++++++\n");
         printf("\n________________________________________________________\n");
         printf("|NOM             |PRENOM          |AGE|N INSCRIPTION|\n");
         printf("---------------------------------------------------------\n");
         while(i<taille){
           printf("|%s",(el+i)->nom);
           espace(strlen((el+i)->nom),16);
           printf("|%s",(el+i)->prenom);
           espace(strlen((el+i)->prenom),16);
           printf("| %d |   %d   |",(el+i)->age,(el+i)->num_inscri);
           printf("\n--------------------------------------------------------\n");
           i++;
         }
         Messages(el,taille);
  }
}
/*Chercher un etudiant par son numero*/
void Cherche_EtudiantNum(Etudiant *el,int taille,int num_inscri){
 int i=0,trouver=0;
 while(i<taille && (trouver==0)){
    if((el+i)->num_inscri==num_inscri){
     trouver=1;
    }
    else{
        i++;
    }
 }
 if(trouver){
      printf("Numero est trouvé\n");
     printf("|NOM : %s|PRENOM: %s|AGE: %d|N INSCRIPTION: %d|\n",(el+i)->nom,(el+i)->prenom,(el+i)->age,(el+i)->num_inscri);
 }
 else{
    printf("le numero n'existe pas");
 }
}
/*Chercher un etudiant par son  prenom ou nom*/
int Cherche_EtudiantNom(Etudiant *el,int taille,char *nom){
  int i=0,j=0,trouver=0;
  while(i<taille && (trouver==0)){
    if(strlen((el+i)->nom)==strlen(nom)){
       while(nom[j]==(el+i)->nom[j] && nom[j]!='\0'){
            j++;
       }
       if(j==strlen(nom)){
        trouver=1;
       }
       else{
        i++;
       }
    }
    else{
      i++;
    }
  }
  if(trouver) return i;
  else return -1;
}
/*Chercher un etudiant par son  prenom*/
void Cherche_EtudiantPrenom(Etudiant *el,int taille,char *nom){
  int i=0,j=0,trouver=0;
  while(i<taille && (trouver==0)){
    if(strlen((el+i)->prenom)==strlen(nom)){
       while(nom[j]==(el+i)->nom[j] && nom[j]!='\0'){
            j++;
       }
       if(j==strlen(nom)){
        trouver=1;
       }
       else{
        i++;
       }
    }
    else{
      i++;
    }
  }
  if(trouver){
     printf("Etudiant est trouvé\n");
     printf("|NOM : %s|PRENOM: %s|AGE: %d|N INSCRIPTION: %d|\n",(el+i)->nom,(el+i)->prenom,(el+i)->age,(el+i)->num_inscri);
    }
   else{
    printf("cette personne n'est pas dans la liste");
    }
}
/*CHERCHER*/
void Cherche_Etudiant(Etudiant *el,int taille){
     int choix,inscri;
 if(Liste_est_vide(el)){
        printf("\nLa Liste est vide\n");
        printf("Remplir la liste!!!!\n");
        Messages(el,taille);
 }else{
     char nom[20],prenom[20];
     printf("\n+++++++++++++++++++++++++++++++CHERCHER UN ETUDIANT++++++++++++++++++++++++++++\n");
     printf(" _______________________________________________________________________________\n");
     printf("|                  (1) Par son Numero d'inscription                             |\n");
     printf("|                  (2) par son Nom                                              |\n");
     printf("|                  (3) Par son Prenom                                           |\n");
     printf(" --------------------------------------------------------------------------------\n");
     printf("Entrer votre choix:  ");
     scanf("%d",&choix);
     if(choix==1){
       printf("Numero d'insciption : ");
       scanf("%d",&inscri);
       Cherche_EtudiantNum(el,taille,inscri);
       }
      else if(choix==2){
       printf("Nom  d'etudiant: ");
       scanf("%s",nom);
        if(Cherche_EtudiantNom(el,taille,nom)!=-1){
         int i=Cherche_EtudiantNom(el,taille,nom);
         printf("Etudiant est trouvé\n");
         printf("|NOM : %s|PRENOM: %s|AGE: %d|N INSCRIPTION: %d|\n",(el+i)->nom,(el+i)->prenom,(el+i)->age,(el+i)->num_inscri);
        }
        else{printf("\ncette personne n'est pas dans la liste\n");}
       }
      else if(choix==3){
       printf("Prenom  d'etudiant: ");
       scanf("%s",prenom);
       Cherche_EtudiantPrenom(el,taille,prenom);
       }
       else{
        printf("Votre choix n'est pas validé");
       }
    Messages(el,taille);
 }

}
/*Supprimer Etudiant*/
void Supp_Etudiant(Etudiant *el,int taille){
  char nom[20];
  int num,index;
   if(Liste_est_vide(el)){
        printf("\nLa Liste est vide\n");
        printf("Remplir la liste!!!!\n");
        Messages(el,taille);
   }else{
        printf("\n+++++++++++++++++SUPPRIMER ETUDIANTS+++++++++++++++++++++++++\n");
        printf("Entrer son NOM et son numero d'inscription : ");
        scanf("%s %d",nom,&num);
        index=Cherche_EtudiantNom(el,taille,nom);
        if(index!=-1){
          while(index<taille){
          printf("L'Etudiant qui porte le nom %s est bien supprime\n",(el+index)->nom);
         *(el+index)=*(el+(index+1));
          index++;
           }
         taille=taille-1;
        }else{
         printf("l'Etudiant n'est pas dans la liste\n");
         }
     Messages(el,taille);
   }
}
/*++++SAISIR les Note des etudiant par Matiere+++++++*/
void Saisir_NoteEtudiant(Etudiant *el,int taille){
    int i=0,j;
     if(Liste_est_vide(el)){
        printf("\nLa Liste est vide\n");
        printf("Remplir la liste!!!!\n");
        Messages(el,taille);
     }
    /*initialiser les non de matiere*/
     else{
       while(i<taille){
       strcpy((el+i)->eleve[0].Mat,"ANALYSE");
       strcpy((el+i)->eleve[1].Mat,"ALGEBRE");
       strcpy((el+i)->eleve[2].Mat,"GEOMETRIE");
       strcpy((el+i)->eleve[3].Mat,"PROBABILITE");
       strcpy((el+i)->eleve[4].Mat,"INFORMATIQUE");
       strcpy((el+i)->eleve[5].Mat,"CHIMIE");
       strcpy((el+i)->eleve[6].Mat,"PHYSIQUE");
        i++;
       }
       i=0;
       while(i<taille){
          printf("------Les note obtient par %s------- \n",(el+i)->nom);
          j=0;
          while(j<7){
          printf("NOTE %s vaut(2 chidffres et sur 20):",(el+i)->eleve[j].Mat);
          scanf("%d",&(el+i)->eleve[j].note);
          j++;
          }
        system("cls");
        i++;
       }
      Messages(el,taille);
     }
}
/*AFFICHER SES NOTES EN TABLEAU*/
void Affiche_NoteEtudiant(Etudiant *el,int taille){
    int i,j;
    float moyen=0;
    if(Liste_est_vide(el)){
        printf("\nLa Liste est vide\n");
        printf("Remplir la liste!!!!\n");
        Messages(el,taille);
     }else{
         printf("\n\t\t\t+++++++++++++++++++++++++++++++NOTES DES ETUDIANTS++++++++++++++++++++++++++++\n\n");
         j=0;
         printf("                         ");
         while(j<7){printf("|%s",(el+0)->eleve[j].Mat);j++;}
          printf("|Moyenne");
          i=0;
         while(i<taille){
           printf("\n");
           for(int k=0;k<53;k++)printf("--");
           printf("\n");
           printf("|%s %s",(el+i)->nom,(el+i)->prenom);
           espace(strlen((el+i)->nom)+strlen((el+i)->prenom)+1,24);/*Pour bien ger le tableau*/
           j=0;
            while(j<7){
              printf("|%d",(el+i)->eleve[j].note*4);
              espace(2,strlen((el+i)->eleve[j].Mat));
              moyen+=((el+i)->eleve[j].note*4);
              j++;
            }
         moyen=moyen/28;
         printf("|%f",moyen);
         i++;
        }
     Messages(el,taille);
     }
}
/*Affichage premier plan*/
void Affiche_premierPage(Etudiant *el,int taille){
    int choix;
   do{
     printf("\n\t\t\t+++++++++++++++++++++++++++++++GESTON DES ETUDIANTS++++++++++++++++++++++++++++\n");
     printf("\t\t\t\t\t\t+++il y a %d Etudiants+++\n ",taille);
     printf("\t\t\t _______________________________________________________________________________\n");
     printf("\t\t\t|                  (1) Saisir des etuiants  a la liste                           |\n");
     printf("\t\t\t|                  (2) Modifier la liste d'etuiants                              |\n");
     printf("\t\t\t|                  (3) Afficher la liste d'etuiants                              |\n");
     printf("\t\t\t|                  (4) chercher un etudiant dans la liste                        |\n");
     printf("\t\t\t|                  (5) Suppprimer un etudiant dans la liste                      |\n");
     printf("\t\t\t|                  (6) Saisir les notes d'etudiants par matiere                  |\n");
     printf("\t\t\t|                  (7) Afficher les notes d'etudiants par matiere                |\n");
     printf("\t\t\t|                  (8) quitter le programme                                      |\n");
     printf(" \t\t\t--------------------------------------------------------------------------------\n");
     do{
       printf("\t\t\t\t\t\tEntrer votre choix: ");
       scanf("%d",&choix);
     }while(choix<0);

     switch(choix){
     case 1:{
       system("cls");
       Saisir_ListEtudiant(el,taille);
       break;
       }
     case 2:{
       system("cls");
       Modifier_Etudiant(el,taille);
       break;
       }
      case 3:{
       system("cls");
       Affiche_ListEtudiant(el,taille);
       break;
       }
      case 4:{
      system("cls");
      Cherche_Etudiant(el,taille);
      break;
      }
      case 5:{
      system("cls");
      Supp_Etudiant(el,taille);
      break;
      }
      case 6:{
      system("cls");
      Saisir_NoteEtudiant(el,taille);
      break;
      }
      case 7:{
      system("cls");
      Affiche_NoteEtudiant(el,taille);
      break;
      }
       default:
       Fin_prog();
       break;
     }

   }while(choix!=8);
}
