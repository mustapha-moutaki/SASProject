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

int i, nbr_total = 0;
int choix;
int newID = 0;


void menu(){
    printf("---------------< MENU >---------------\n");
    printf("1) Ajouter un etudiant\n");
    printf("2) Modifier les informations d'un etudiant\n");
    printf("3) Supprimer les details d'un etudiant\n");
    printf("4) Afficher les details d'un etudiant\n");
    printf("5) La moyenne generale\n");
    printf("6) Statistique\n");
    printf("7) Rechercher\n");
    printf("8) Trier des etudiants\n");
    printf("-------------\n");
    printf("Tapez N:\t");
    scanf("%d", &choix);
    printf("-------------\n");
}


void ajouter(){
    printf("<><><><><><><>Ajouter un etudiant<><><><><><><>\n");
    printf("Le nom: \t");
    scanf(" %[^\n]s", &etudiant[nbr_total].nom);
    printf("Le prenom: \t");
    scanf(" %[^\n]s", &etudiant[nbr_total].prenom);

    printf("La date de naissance (j/m/annee):\n");
    printf("Jour: ");
    scanf("%d", &etudiant[nbr_total].date_de_naissance.jour);
    printf("Mois: ");
    scanf("%d", &etudiant[nbr_total].date_de_naissance.mois);
    printf("Annee: ");
    scanf("%d", &etudiant[nbr_total].date_de_naissance.annee);

    printf("Le note generale: \t");
    scanf("%f", &etudiant[nbr_total].note_generale);
    printf("Departement: \t");
    scanf(" %[^\n]s", &etudiant[nbr_total].departement);
    
    etudiant[nbr_total].nombre_unique = ++newID;
    nbr_total++;
}


void modifier(){
    int nbr_modifier, modification_nbr;
    char new_nom[50], new_pre[50], nouv_depart[50];
    int nouv_jour, nouv_mois, nouv_annee;
    float nouv_note_genera;

    printf("=================Tous les etudiants========================\n");
    for (i = 0; i < nbr_total; i++){
        printf("________________________________________________\n");
        printf("Nom: %s\n", etudiant[i].nom);
        printf("Prenom: %s\n", etudiant[i].prenom);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("Note generale: %.2f\n", etudiant[i].note_generale);
        printf("Date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
        printf("________________________________________________\n");
    }

    printf("============================================================\n");
    printf("Tapez ID:\t");
    scanf("%d", &nbr_modifier);
    for (i = 0; i < nbr_total; i++){
        if(nbr_modifier == etudiant[i].nombre_unique){
            printf("1) Modifier le nom et prenom\n");
            printf("2) Modifier la date de naissance\n");
            printf("3) Modifier la note generale\n");
            printf("4) Modifier le departement\n");
            scanf("%d", &modification_nbr);

            switch (modification_nbr){
            case 1:
                printf("Entrez le nom:\t");
                scanf(" %[^\n]s", new_nom);
                printf("Entrez le prenom:\t");
                scanf(" %[^\n]s", new_pre);
                strcpy(etudiant[i].nom, new_nom);
                strcpy(etudiant[i].prenom, new_pre);
                printf("|| Fait avec succes ||\n");
                break;    
            case 2:
                printf("Entrez la date (jour mois annee):\t");
                scanf("%d %d %d", &nouv_jour, &nouv_mois, &nouv_annee);
                etudiant[i].date_de_naissance.jour = nouv_jour;
                etudiant[i].date_de_naissance.mois = nouv_mois;
                etudiant[i].date_de_naissance.annee = nouv_annee;
                printf("|| Fait avec succes ||\n");
                break;
            case 3:
                printf("Entrez la note generale:\t");
                scanf("%f", &nouv_note_genera);
                etudiant[i].note_generale = nouv_note_genera;
                printf("|| Fait avec succes ||\n");
                break;
            case 4:
                printf("Entrez le departement:\t");
                scanf(" %[^\n]s", nouv_depart);
                strcpy(etudiant[i].departement, nouv_depart);
                printf("|| Fait avec succes ||\n");
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
    printf("============Tous les etudiants===================\n");
    for (i = 0; i < nbr_total; i++){
        printf("________________________________________________\n");
        printf("Nom: %s\n", etudiant[i].nom);
        printf("Prenom: %s\n", etudiant[i].prenom);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("Note generale: %.2f\n", etudiant[i].note_generale);
        printf("Date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
        printf("________________________________________________\n");
    }

    printf("=================================================\n");
    printf("Tapez ID d'etudiant: \n");
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
    printf("---------------< Tous les etudiants >---------------\n");
    for (i = 0; i < nbr_total; i++){
        printf("\n**************************\n");
        printf("Nom: %s\n", etudiant[i].nom);
        printf("Prenom: %s\n", etudiant[i].prenom);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("Note generale: %.2f\n", etudiant[i].note_generale);
        printf("Date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
    }
    printf("-------------------------------------------------\n");
}


void cal_moye_gene_part(){
    char T[20][50];
    int countDep = 0;

    for (i = 0; i < nbr_total; i++){
        int alreadyPrinted = 0;
        for (int j = 0; j < i; j++){
            if (strcmp(etudiant[i].departement, etudiant[j].departement) == 0){
                alreadyPrinted = 1;
                break;
            }
        }
        if (!alreadyPrinted){
            strcpy(T[countDep], etudiant[i].departement);
            countDep++;
        }
    }

    for (i = 0; i < countDep; i++){
        float somme = 0;
        int lengthDep = 0;

        for (int j = 0; j < nbr_total; j++){
            if (strcmp(T[i], etudiant[j].departement) == 0){
                somme += etudiant[j].note_generale;
                lengthDep++;
            }
        }
        printf("Departement %d %s: %.2f\n", i + 1, T[i], somme / lengthDep);
    }

    float somme = 0;
    for (i = 0; i < nbr_total; i++){
        somme += etudiant[i].note_generale;
    }

    printf("La moyenne generale de l'universite: %.2f\n", somme / nbr_total);
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
        printf("la note generale: %.2f\n", etudiant[i].note_generale);
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



void triAlphabitique() {
    list_etudiant tmp;
    for(int i = 0; i < nbr_total - 1; i++) {
        for(int x = 0; x < nbr_total - i - 1; x++) {
            if(strcasecmp(etudiant[x].nom, etudiant[x + 1].nom) > 0) {
                tmp = etudiant[x];
                etudiant[x] = etudiant[x + 1];
                etudiant[x + 1] = tmp;
            }
        }
    }


    for (int i = 0; i < nbr_total; i++) {
        printf("**************************\n");
        printf("Nom: %s\n", etudiant[i].nom);
        printf("Prenom: %s\n", etudiant[i].prenom);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("Note generale: %.2f\n", etudiant[i].note_generale);
        printf("Date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
    }
}


void trierMoyenne() {
    list_etudiant tmp;
    for(int i = 0; i < nbr_total - 1; i++) {
        for(int x = 0; x < nbr_total - i - 1; x++) {
            if(etudiant[x].note_generale < etudiant[x + 1].note_generale) {
                tmp = etudiant[x];
                etudiant[x] = etudiant[x + 1];
                etudiant[x + 1] = tmp;
            }
        }
    }


    for (int i = 0; i < nbr_total; i++) {
        printf("**************************\n");
        printf("Nom: %s\n", etudiant[i].nom);
        printf("Prenom: %s\n", etudiant[i].prenom);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("Note generale: %.2f\n", etudiant[i].note_generale);
        printf("Date de naissance: %d/%d/%d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("| ID: >%d<|\n", etudiant[i].nombre_unique);
    }
}


int main(){
    do{
        menu();
        switch (choix){
        case 1:
            ajouter();
            break;
        case 2:
            modifier();
            break;
        case 3:
            suprimer();
            break;
        case 4:
            affichier();
            break;
        case 5:
            cal_moye_gene_part();
            break;
        case 6:
            statistique();
            break;
        case 7:
            printf("Recherche pas encore disponible\n");
            break;
        case 8:
            printf("Trier par:\n1) Alphabetiquement\n2) Par Moyenne Generale\n");
            int sortChoice;
            scanf("%d", &sortChoice);
            if (sortChoice == 1) {
                triAlphabitique();
            } else if (sortChoice == 2) {
                trierMoyenne();
            } else {
                printf("Choix invalide!\n");
            }
            break;
        default:
            printf("Choix invalide! Veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
