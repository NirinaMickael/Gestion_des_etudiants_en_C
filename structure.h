#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
typedef struct Mat_Not{
   char Mat[20];
   int note;
}Mat_Not;
typedef struct Etd{
  char nom[20],prenom[20];
  int age,num_inscri;
  Mat_Not eleve[7];
}Etudiant;
void espace(int taille,int taille_vid);
int Liste_est_vide(Etudiant *el);
void Affiche_premierPage(Etudiant *el,int taille);
void Affiche_NoteEtudiant(Etudiant *el,int taille);
void Saisir_NoteEtudiant(Etudiant *el,int taille);
void Affiche_ListEtudiant(Etudiant *el,int taille);
void Saisir_ListEtudiant(Etudiant *el,int taille);
int  Ajout_ListEtudiant(Etudiant *el,int taille);
void Modifier_Etudiant(Etudiant *el,int taille);
/*Supprimer par son nom ou son numero*/
void Supp_Etudiant(Etudiant *el,int taille);
/*REchercher un etuiant*/
void Cherche_Etudiant(Etudiant *el,int taille);
void Cherche_EtudiantNum(Etudiant *el,int taille,int num_inscri);
int  Cherche_EtudiantNom(Etudiant *el,int taille,char *nom);
void Cherche_EtudiantPrenom(Etudiant *el,int taille,char *nom);
void Fin_prog();
void Messages(Etudiant *E,int taille);
#endif // STRUCTURE_H_INCLUDED
