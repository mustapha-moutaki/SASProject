#include<stdio.h>
#include<string.h>
struct depdef{
    char nomdep[50];
    float sumdep;
    int countdep;
};


typedef struct {
    int jour;
    int mois;
    int annee;
}Date;
typedef struct{
    int nombre_unique;
    char nom[100];
    char prenom[100];
    Date date_de_naissance;
    char departement[100];
    float note_generale;

}list_etudiant;

list_etudiant etudiant[500];

//char departement[13];
int i, nbr_total = 0;
char departement[50];
int choix;
void menu(){
    
    printf("---------------< MENU >---------------\n");
    printf("1) Ajouter un etudiant\n");
    printf("2) modifier les informations d'un etudiant\n");
    printf("3) suprimer les details d'un etudiant \n");
    printf("4) Afficher les details d'un etudiant \n");
    printf("5) La moyenne generale\n");
    printf("6) Statistique\n");
    printf("7) Rechercher\n");
    printf("8) trier des etudiants\n");
    printf("-------------\n");
    printf("tapez N:\t");
    scanf("%d", &choix);
    printf("-------------\n");
}
int newID = 0;
void ajouter(){
    
    printf("<><><><><><><>ajouter un etudiant<><><><><><><>\n");
    printf("le nom: \t");
    scanf(" %[^\n]s", &etudiant[nbr_total].nom);
    printf("le prenom: \t");
    scanf(" %[^\n]s", &etudiant[nbr_total].prenom);
    //scanf("%d %d %d", &etudiant[nbr_total].date_de_naissance.jour, &etudiant[nbr_total].date_de_naissance.mois, &etudiant[nbr_total].date_de_naissance.annee);
    //
    printf("la date de naissance(j/m/annee): \n");
    printf("jour:\t");
    scanf("%d", &etudiant[nbr_total].date_de_naissance.jour);
    printf("jour:\t");

    scanf("%d", &etudiant[nbr_total].date_de_naissance.mois);
    printf("jour:\t");

    scanf("%d", &etudiant[nbr_total].date_de_naissance.annee);
    //
    printf("le note generale: \t");
    scanf("%f", &etudiant[nbr_total].note_generale);
    printf("departement: \t");
    scanf(" %[^\n]s", &etudiant[nbr_total].departement);
    nbr_total++;
    etudiant[nbr_total].nombre_unique=++newID;

}

void modifier(){
    int nbr_modifier;
    int modification_nbr;
    char new_nom[50];
    char new_pre[50];
    int nouv_jour,nouv_mois, nouv_annee;
    int nouv_note_genera;
    char nouv_depart[50];
    printf("=================tous les etudiants========================\n");
for (int i = 0; i < nbr_total; i++){
        printf("________________________________________________\n");
        printf("le nom: %s\n", etudiant[i].nom);
        printf("le prenom: %s\n", etudiant[i].prenom);
        printf("le departement: %s\n", etudiant[i].departement);
        printf("la note general: %.2f\n", etudiant[i].note_generale);
        printf("le date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
        printf("________________________________________________\n");
    }
    printf("============================================================\n");
    printf("tapez ID:\t");
    scanf("%d", &nbr_modifier);
    for ( i = 0; i < nbr_total; i++){
        if(nbr_modifier == etudiant[i].nombre_unique){
            printf("1) modifier le nom et prenom\n");
            printf("2) modifier la date de naissance\n");
            printf("3) modifier la note generale\n");
            printf("4) modifier la departement\n");
            scanf("%d", &modification_nbr);
            switch (modification_nbr){
            case 1:
                printf("entre le nom:\t");
                scanf(" %[^\n]s", &new_nom);
                printf("entre le prenom:\t");
                scanf(" %[^\n]s", &new_pre);
                strcpy(etudiant[i].nom, new_nom);
                strcpy(etudiant[i].prenom, new_pre);
                printf("||Fait avec succes||\n");
                break;    
            case 2:
                printf("entre la date:\t");
                scanf("%d %d %d", &nouv_jour,&nouv_mois, &nouv_annee);
                etudiant[i].date_de_naissance.jour = nouv_jour;
                etudiant[i].date_de_naissance.mois = nouv_mois;
                etudiant[i].date_de_naissance.annee = nouv_annee;
                printf("||Fait avec succes||\n");
                break;
            case 3:
                printf("entre la note generale:\t");
                scanf("%f", &nouv_note_genera);
                etudiant[i].note_generale = nouv_note_genera;
                printf("||Fait avec succes||\n");
                break;
            case 4:
                printf("entre la departement:\t");
                scanf(" %[^\n]s", &nouv_depart);
                strcpy(etudiant[i].departement, nouv_depart);
                printf("||Fait avec succes||\n");
                break;
            
            default:
                printf("Oops!! Choisissez 1/2/3/4\n");
                break;
            }
        }
    }
    
}

void suprimer(){
    int choix_suprime;
    printf("============tous les etudiants===================\n");
    for (int i = 0; i < nbr_total; i++){
        printf("________________________________________________\n");
        printf("le nom: %s\n", etudiant[i].nom);
        printf("le prenom: %s\n", etudiant[i].prenom);
        printf("le departement: %s\n", etudiant[i].departement);
        printf("la note general: %f\n", etudiant[i].note_generale);
        printf("le date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
        printf("________________________________________________\n");

    }
    printf("=================================================\n");
    printf("tapez ID d'etidiant: \n");
    scanf("%d", &choix_suprime);
    for(i = 0; i < nbr_total; i++){
    if (etudiant[i].nombre_unique == choix_suprime){
        
        for (int j = i; j < nbr_total-1; j++){
            etudiant[j] = etudiant[j+1];
           
        }
         nbr_total--;
        break;
    }
    }
    

    
}

void affichier(){
        printf("---------------< tout les etudiants >---------------\n");
        for ( i = 0; i < nbr_total; i++){
            printf("\n");
        printf("**************************\n");
        printf("le nom: %s\n", etudiant[i].nom);
        printf("le prenom: %s\n", etudiant[i].prenom);
        printf("le departement: %s\n", etudiant[i].departement);
        printf("la note general: %.2f\n", etudiant[i].note_generale);
        printf("le date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
        
        }
        printf("-------------------------------------------------\n");


}

void cal_moye_gene_part(){

char T[20][50];
int countDep =0;
    for (int i = 0; i < nbr_total; i++){
    int alreadyPrinted = 0;
    for (int j = 0; j < i; j++)
    {
    if (strcmp(etudiant[i].departement, etudiant[j].departement) == 0){
        alreadyPrinted = 1;
        break;
      }
    }
    if (!alreadyPrinted)
    {
      printf("%s\n", etudiant[i].departement);
      strcpy(T[countDep], etudiant[i].departement);
      countDep++;
    }
  }

  for (int i = 0; i < countDep; i++)
  {
    float somme = 0;
    int lengthDep = 0;

    for (int j = 0; j < nbr_total; j++)
    {
      if (strcmp(T[i], etudiant[j].departement) == 0)
      {
        somme += etudiant[j].note_generale;
        lengthDep++;
      }
    }
    printf("Departement %d %s %.2f: \n ", i + 1, T[i], somme / lengthDep);
  }
float somme = 0;
for ( i = 0; i < nbr_total; i++){

    somme = somme + etudiant[i].note_generale;

}

  printf("la moyenne generale de l'univirsity: %.2f\n", somme/nbr_total);

}

void statistique(){
    int choix1;
    int moyenne_choisir;
    int bonne_moyenn;
    printf("****************************************************************************************\n");
    printf("\n1)Afficher le nombre total d'etudiants inscrits.\n");
    printf("\n2)Afficher le nombre d'etudiants dans chaque departement..\n");
    printf("\n3)Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
    printf("\n4)Afficher les 3 etudiants ayant les meilleures notes.\n");
    printf("\n5)Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");
    printf("****************************************************************************************\n");
    printf("-------------\n");
    printf("tapez N: \t");
    printf("-------------\n");
    scanf("%d", &choix1);
    
    switch (choix1){
        int acount = 0;
        int acoun=0;
    case 1:
        printf("le nombre totale d'etudiant inscrit ||  %d  etudiants ||\n", nbr_total);
        break;
    case 2:{
        char T[20][50];  
    int countDep = 0; 


    for (int i = 0; i < nbr_total; i++) {
        int alreadyPrinted = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(etudiant[i].departement, etudiant[j].departement) == 0) {
                alreadyPrinted = 1;
                break;
            }
        }
        if (!alreadyPrinted) {
            strcpy(T[countDep], etudiant[i].departement);
            countDep++;
        }
    }

    
    for (int i = 0; i < countDep; i++) {
        int countEtudiant = 0;
        for (int j = 0; j < nbr_total; j++) {
            if (strcmp(T[i], etudiant[j].departement) == 0) {
                countEtudiant++;
            }
        }
        printf("Departement %s: %d etudiants\n", T[i], countEtudiant);
    }
}
        break;

        case 3:
        printf("entre la moyenne:\t");
        scanf("%d", &moyenne_choisir);
        for ( i = 0; i < nbr_total; i++){
            if(etudiant[i].note_generale >= moyenne_choisir){
                
        printf("**************************\n");
        printf("le nom: %s\t", etudiant[i].nom);
        printf("le prenom: %s\n", etudiant[i].prenom);
        printf("le prenom: %.2f\n", etudiant[i].note_generale);
        printf("**************************\n");
        acoun++;
            }

}
        break;

        case 4: {
        for (int i = 0; i < nbr_total - 1; i++) {
        for (int j = i + 1; j < nbr_total; j++) {
            int tmp =0;
            if (etudiant[i].note_generale < etudiant[j].note_generale) {
                
                
                list_etudiant tmp = etudiant[i];  
                etudiant[i] = etudiant[j];   
                etudiant[j] = tmp;
            }
        }
    }

    
    printf("Les 3 etudiants ayant les meilleures notes:\n");
    for (int i = 0; i < 3 && i < nbr_total; i++) {
        printf("%s %s - Note: %.2f\n", etudiant[i].nom, etudiant[i].prenom, etudiant[i].note_generale);
    }
       }
        break;

        case 5:{
            char T[20][50];  
    int countDep = 0; 

    
    for (int i = 0; i < nbr_total; i++) {
        int alreadyPrinted = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(etudiant[i].departement, etudiant[j].departement) == 0) {
                alreadyPrinted = 1;
                break;
            }
        }
        if (!alreadyPrinted) {
            strcpy(T[countDep], etudiant[i].departement);
            countDep++;
        }
    }

    
    for (int i = 0; i < countDep; i++) {
        int countt = 0;
        for (int j = 0; j < nbr_total; j++) {
            if (strcmp(T[i], etudiant[j].departement) == 0 && etudiant[j].note_generale >= 10) {
                countt++;
            }
        }
        printf("Departement %s: %d Etudiants ont reussi\n", T[i], countt);
    }
        }
    
    default:
    printf("Oops!! \n");
        break;
    }

}

void triAlphabitique(){
    char tmp[50] ;
    int tmpN ;
    for(int i = 0 ; i < nbr_total ; i++){
        for (int x = 0; x > nbr_total; x++){
            if(strcasecmp(etudiant[x].nom, etudiant[x + 1].nom) > 0 ){
                //change nom
                strcpy(tmp,etudiant[x].nom);
                strcpy(etudiant[x].nom,etudiant[x + 1].nom);
                strcpy(etudiant[x + 1].nom,etudiant[x].nom);
                //change prenom
                strcpy(tmp,etudiant[x].prenom);
                strcpy(etudiant[x].prenom,etudiant[x + 1].prenom);
                strcpy(etudiant[x + 1].prenom,etudiant[x].prenom);
                //change departement
                strcpy(tmp,etudiant[x].departement);
                strcpy(etudiant[x].departement,etudiant[x + 1].departement);
                strcpy(etudiant[x + 1].departement,etudiant[x].departement);
                //date de naissance
                tmpN = etudiant[x].date_de_naissance.jour;
                etudiant[x].date_de_naissance.jour = etudiant[x + 1].date_de_naissance.jour;
                etudiant[x + 1].date_de_naissance.jour = etudiant[x].date_de_naissance.jour;

                tmpN = etudiant[x].date_de_naissance.mois;
                etudiant[x].date_de_naissance.mois = etudiant[x + 1].date_de_naissance.mois;
                etudiant[x + 1].date_de_naissance.mois = etudiant[x].date_de_naissance.mois;

                tmpN = etudiant[x].date_de_naissance.annee;
                etudiant[x].date_de_naissance.annee = etudiant[x + 1].date_de_naissance.annee;
                etudiant[x + 1].date_de_naissance.annee = etudiant[x].date_de_naissance.annee;

                //note generale
                tmpN = etudiant[x].note_generale;
                etudiant[x].note_generale = etudiant[x + 1].note_generale;
                etudiant[x + 1].note_generale = etudiant[x].note_generale;
                //numbre unique
                tmpN = etudiant[x].nombre_unique;
                etudiant[x].nombre_unique = etudiant[x + 1].nombre_unique;
                etudiant[x + 1].nombre_unique = etudiant[x].nombre_unique;

    
            }
        }
        
    }
    for (int i = 0; i < nbr_total; i++)
    {
         printf("**************************\n");
        printf("le nom: %s\n", etudiant[i].nom);
        printf("le prenom: %s\n", etudiant[i].prenom);
        printf("le departement: %s\n", etudiant[i].departement);
        printf("la note general: %.2f\n", etudiant[i].note_generale);
        printf("le date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
    }
    
   
}

void trierMoyenne(){
     char tmp[50] ;
    int tmpN ;
    for(int i = 0 ; i < nbr_total ; i++){
        for (int x = 0; x > nbr_total; x++){
            if(etudiant[x+1].note_generale < etudiant[x].note_generale ){
                //change nom
                strcpy(tmp,etudiant[x].nom);
                strcpy(etudiant[x].nom,etudiant[x + 1].nom);
                strcpy(etudiant[x + 1].nom,etudiant[x].nom);
                //change prenom
                strcpy(tmp,etudiant[x].prenom);
                strcpy(etudiant[x].prenom,etudiant[x + 1].prenom);
                strcpy(etudiant[x + 1].prenom,etudiant[x].prenom);
                //change departement
                strcpy(tmp,etudiant[x].departement);
                strcpy(etudiant[x].departement,etudiant[x + 1].departement);
                strcpy(etudiant[x + 1].departement,etudiant[x].departement);
                //date de naissance
                tmpN = etudiant[x].date_de_naissance.jour;
                etudiant[x].date_de_naissance.jour = etudiant[x + 1].date_de_naissance.jour;
                etudiant[x + 1].date_de_naissance.jour = etudiant[x].date_de_naissance.jour;

                tmpN = etudiant[x].date_de_naissance.mois;
                etudiant[x].date_de_naissance.mois = etudiant[x + 1].date_de_naissance.mois;
                etudiant[x + 1].date_de_naissance.mois = etudiant[x].date_de_naissance.mois;

                tmpN = etudiant[x].date_de_naissance.annee;
                etudiant[x].date_de_naissance.annee = etudiant[x + 1].date_de_naissance.annee;
                etudiant[x + 1].date_de_naissance.annee = etudiant[x].date_de_naissance.annee;

                //note generale
                tmpN = etudiant[x].note_generale;
                etudiant[x].note_generale = etudiant[x + 1].note_generale;
                etudiant[x + 1].note_generale = etudiant[x].note_generale;
                //numbre unique
                tmpN = etudiant[x].nombre_unique;
                etudiant[x].nombre_unique = etudiant[x + 1].nombre_unique;
                etudiant[x + 1].nombre_unique = etudiant[x].nombre_unique;
                
            }
        }
        
    }
        for (int i = 0; i < nbr_total; i++){
            printf("**************************\n");
        printf("le nom: %s\n", etudiant[i].nom);
        printf("le prenom: %s\n", etudiant[i].prenom);
        printf("le departement: %s\n", etudiant[i].departement);
        printf("la note general: %.2f\n", etudiant[i].note_generale);
        printf("le date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
        }
        
}    
void trierEtudiants(){
    int trier_Choix;
    printf("1>trier par alphabitiques\n");
    printf("2>trier par moyenne generale\n");
    printf("3>trier par la reussi\n");
    printf("tapez votre choix\t");
    scanf("%d", &trier_Choix);

    switch (trier_Choix){
    case 1:
        triAlphabitique();
        break;
    
      case 2:
        trierMoyenne();
        break;

    // case 3:
    //     break;
    
    default:
            printf("tapez votre choix");
        break;
    }
    
}



void rechercher(){
    char nom_chercher[50];
    printf("tapez le nom:\n");
    scanf(" %[^\n]", nom_chercher);
    printf("=========================RECHERCHER===============================\n");
    for (int i = 0; i < nbr_total; i++){
    if(strcmp(etudiant[i].nom, nom_chercher) == 0){
        printf("<----------------------------------------------------->\n");
        printf("Le nom: %s\n", etudiant[i].nom);
        printf("Le prenom: %s\n", etudiant[i].prenom);
        printf("La date de naissance: %d\n", etudiant[i].date_de_naissance);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("ID: %d\n", etudiant[i].nombre_unique);
        printf("\\___________________________________________________________/\n");
    }
    
    }
    printf("=================================================================\n");
}
int main(){
    
    do
    {
        menu();

        switch (choix){
        case 1: ajouter();
            break;
        case 2: modifier();
            break;
        case 3: suprimer();
            break;
            
        case 4: affichier();
            break;
        case 5: cal_moye_gene_part();
        
        break;
        case 6: statistique();
        break;

        case 7: rechercher();
        break;

        case 8: trierEtudiants();
        break;

        default:
        printf("Oops !!\n");
            break;
        }
    } while (choix != 0);
    
    



    return 0;
}