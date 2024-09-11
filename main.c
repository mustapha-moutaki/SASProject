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
    printf("la date de naissance(j/m/ans): \n");
    scanf("%d %d %d", &etudiant[nbr_total].date_de_naissance.jour, &etudiant[nbr_total].date_de_naissance.mois, &etudiant[nbr_total].date_de_naissance.annee);

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
/*
    char nom_departemant[30];
int moyen_generale_depar=0;
int x=0;
    printf("entre le nom_departemant\n");
    scanf(" %[^\n]", nom_departemant);
    for(int i=0;i<nbr_etudiants;i++){
        if(strcmp(nom_departemant, etudiants[i].departement)==0){
            x++;
            moyen_generale_depar=(moyen_generale_depar + etudiants[i].Note_generale);

        }
    }
    printf("moyen generale %d\n",moyen_generale_depar/x);
}

//la note generale departement

// for (int i = 0; i < nbr_total; i++){
//     int isfound = 0;
//     for (int j = 0; j < nbr_total; j++){
//         if (strcmp(depdef[j].nomdef, etudiant[i].nom)==0){
//             deps[count].sumdep
//         }
        
//     }
 */   
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
        for (i = 0; i < nbr_total; i++){
            for(int j =0; i < nbr_total; i++){
                if(strcmp(etudiant[j].departement, etudiant[j+1].departement)==0){
                    acount++;
                }
            }
            
        }
        printf("le nombre d'etudiant dans chaque departement: %d");
    }
          
        break;

        case 3:
        printf("entre la moyenne:\t");
        scanf("%d", &moyenne_choisir);
        for ( i = 0; i < nbr_total; i++){
            int bonne_moyenne;
            if(etudiant[i].note_generale >= moyenne_choisir){
                // bonne_moyenne == etudiant[i].note_generale;
                
        printf("**************************\n");
        printf("le nom: %s\t", etudiant[i].nom);
        printf("le prenom: %s\n", etudiant[i].prenom);
        printf("**************************\n");
        acoun++;
            }

}
        break;

        case 4: 
        for ( i = 0; i < nbr_total-1; i++){
            int tmp;
            for (int j = 0; j < nbr_total-1-i; j++){
                
                if (etudiant[j].note_generale > etudiant[j+1].note_generale){
                    tmp = etudiant[j+1].note_generale;
                    etudiant[j+1].note_generale = etudiant[j].note_generale;
                    etudiant[j].note_generale = tmp;
                }

                
            }
            for (int i = 0; i < nbr_total; i++){
                
            }
            
            
        }
        
        break;
    
    default:
    printf("Oops!! \n");
        break;
    }

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
            break;
        case 4: affichier();
            break;
        case 5: cal_moye_gene_part();
        
        break;
        case 6: statistique();
        break;

        
        default:
        printf("Oops !!\n");
            break;
        }
    } while (choix != 0);
    
    



    return 0;
}