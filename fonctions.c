#include <stdio.h>
#include <string.h>
#include "fonctions.h"


void AjouterUnEtudiant(struct etudiant etudiants[], int nombreEtudiant) {
    if (nombreEtudiant >= 100) {
        printf("La table des etudiants est pleine.\n");
        return;
    }
    int index = nombreEtudiant;
    printf("Veuillez entrer le nom de l'etudiant: ");
    scanf(" %[^\n]", etudiants[index].nom);
    printf("Veuillez entrer le prenom de l'etudiant: ");
    scanf(" %[^\n]", etudiants[index].prenom);
    printf("Veuillez entrer le numero unique de l'etudiant: ");
    scanf("%d", &etudiants[index].numeroUnique);
    printf("Veuillez entrer la date de naissance de l'etudiant\n");
    printf("Le jour: ");
    scanf("%d", &etudiants[index].date.jour);
    printf("Le mois: ");
    scanf("%d", &etudiants[index].date.mois);
    printf("L'annee: ");
    scanf("%d", &etudiants[index].date.annee);
    printf("Veuillez entrer le departement de l'etudiant: ");
    scanf(" %[^\n]", etudiants[index].departement);
    printf("Veuillez entrer la note generale de l'etudiant: ");
    scanf("%f", &etudiants[index].noteGenerale);
}

void afficher(struct etudiant etudiants[], int nombreEtudiant) {

    printf("-----------|| les informations completes des etudiants ||-----------\n");
    for (int i = 0; i < nombreEtudiant; i++) {
        printf("           les details personnel : %d \n", i + 1);
        printf("---- Nom de l'etudiant: %s\n", etudiants[i].nom);
        printf("---- Prenom de l'etudiant: %s\n", etudiants[i].prenom);
        printf("---- Numero unique de l'etudiant: %d\n", etudiants[i].numeroUnique);
        printf("---- Date de naissance de l'etudiant: %d/%d/%d\n",
               etudiants[i].date.jour,
               etudiants[i].date.mois,
               etudiants[i].date.annee);
        printf("---- Departement de l'etudiant: %s\n", etudiants[i].departement);
        printf("---- Note generale de l'etudiant: %.2f\n", etudiants[i].noteGenerale);
        printf("-------------------------------------------------------------------------\n");
    }
}

void Modifier(struct etudiant etudiants[], int nombreEtudiant){
    
    char newNom[50];
    char newPrenom[50];
    int newDateJour;
    int newDateMois;
    int newDateAnnee;
    char newDepartement[50];
    float newNoteGenerale ;

    int numeroUniqueModifier ;
    int indexRechercher = -1 ;
    printf("Veuillez entrer le numero unique de l'etudiant :");
    scanf("%d",&numeroUniqueModifier);

    printf("Veuillez entrer le nouveaux nom l'etudiant :");
    scanf(" %[^\n]",newNom);
    printf("Veuillez entrer le nouveaux prenom l'etudiant :");
    scanf(" %[^\n]",newPrenom);
    printf("Veuillez entrer la nouveaux date de naissance de l'etudiant\n");
    printf("Le jour: ");
    scanf("%d", &newDateJour);
    printf("Le mois: ");
    scanf("%d", &newDateMois);
    printf("L'annee: ");
    scanf("%d", &newDateAnnee);
    printf("Veuillez entrer la nouveaux Departement de l'etudiant :");
    scanf(" %[^\n]",newDepartement);
    printf("Veuillez entrer la nouveaux note generale de l'etudiant :");
    scanf("%f",&newNoteGenerale);

    for(int i = 0 ; i < nombreEtudiant ; i++){
        if(etudiants[i].numeroUnique == numeroUniqueModifier){
            indexRechercher = i ;
            break;
        }
    }

    if (indexRechercher == -1) {
        printf("Etudiant non trouve.\n");
        return;
    }

    strcpy(etudiants[indexRechercher].nom , newNom);
    strcpy(etudiants[indexRechercher].prenom , newPrenom);
    etudiants[indexRechercher].date.jour = newDateJour ;
    etudiants[indexRechercher].date.mois = newDateMois ;
    etudiants[indexRechercher].date.annee = newDateAnnee ;
    strcpy(etudiants[indexRechercher].departement , newDepartement);
    etudiants[indexRechercher].noteGenerale = newNoteGenerale ;

    printf("Modification reussie !\n");

}

void Supprimer(struct etudiant etudiants[], int *nombreEtudiant){
    int numeroUnique = 0 ;
    int indexRechercher = -1 ;
    printf("Veuillez entrer le numero unique de l'etudiant :");
    scanf("%d",&numeroUnique);

    for(int i = 0 ; i < *nombreEtudiant ; i++){
        if(etudiants[i].numeroUnique == numeroUnique){
            indexRechercher = i ;
            break;
        }
    }

    if (indexRechercher == -1) {
        printf("Etudiant non trouve.\n");
        return;
    }

    for(int i = indexRechercher ; i < *nombreEtudiant - 1 ; i++){
        strcpy(etudiants[i].nom , etudiants[i + 1].nom);
        strcpy(etudiants[i].prenom , etudiants[i + 1].prenom);
        etudiants[i].numeroUnique = etudiants[i + 1].numeroUnique ;
        etudiants[i].date.jour = etudiants[i + 1].date.jour ;
        etudiants[i].date.mois = etudiants[i + 1].date.mois ;
        etudiants[i].date.annee = etudiants[i + 1].date.annee ;
        strcpy(etudiants[i].departement , etudiants[i + 1].departement);
        etudiants[i].noteGenerale = etudiants[i + 1].noteGenerale ;
    }
    (*nombreEtudiant)-- ;
}

void CalculerLaMoyenneGenerale(struct etudiant etudiants[], int nombreEtudiant) {
    char departementNames[nombreEtudiant][50];
    int isUnique;
    int uniqueCount = 0;

    //loop for put departement unique name on an array "departementNames"
    for (int i = 0; i < nombreEtudiant; i++) {
        isUnique = 1;

        for (int j = 0; j < uniqueCount; j++) {
            if (strcasecmp(etudiants[i].departement, departementNames[j]) == 0) {
                isUnique = 0; 
                break;
            }
        }

        if (isUnique) {
            strcpy(departementNames[uniqueCount], etudiants[i].departement);
            uniqueCount++;
        }
    }

    //loop for calc somme of the Note with each departement name
    for(int i = 0 ; i < uniqueCount ; i++){
        int somme = 0, counteurEtudiant = 0;
        float moyenne ;
        for (int y = 0; y < nombreEtudiant; y++)
        {
            if (strcasecmp(etudiants[y].departement, departementNames[i]) == 0) {
                somme +=  etudiants[y].noteGenerale ;
                counteurEtudiant++ ;
            }
        }
        
        moyenne =  (float)somme / counteurEtudiant ;
        printf("la moyenne generale de departement %s est : %.2f\n", departementNames[i] ,moyenne);
        
    }

    //loop for get somme of all etudiants
    int somme = 0 ;
    float moyenne ;
    for(int i = 0; i < nombreEtudiant; i++){
        somme += + etudiants[i].noteGenerale ;
    }
    moyenne = (float)somme / nombreEtudiant ;
    printf("la moyenne generale de l universite est : %.2f\n", moyenne);
    
}

// Statistique Fonctions 
void nombreTotale(struct etudiant etudiants[], int nombreEtudiant){
    printf("     le nombre total d'etudiants inscrits est : %d \n", nombreEtudiant );
}

void nombrechaqueDep(struct etudiant etudiants[], int nombreEtudiant){
    char departementNames[nombreEtudiant][50];
    int isUnique;
    int uniqueCount = 0;

    //loop for put departement unique name on an array "departementNames"
    for (int i = 0; i < nombreEtudiant; i++) {
        isUnique = 1;

        for (int j = 0; j < uniqueCount; j++) {
            if (strcasecmp(etudiants[i].departement, departementNames[j]) == 0) {
                isUnique = 0; 
                break;
            }
            
        }

        if (isUnique) {
            strcpy(departementNames[uniqueCount], etudiants[i].departement);
            uniqueCount++;
        }
    }

    //calc la Note somme des etudiant pour chaque departement
    for(int i = 0 ; i < uniqueCount ; i++){ //tableau des departement unique
    int counterUnique = 0 ;
        for (int j = 0; j < nombreEtudiant; j++)//tableau des etudiant 
        {
            if (strcasecmp(departementNames[i],  etudiants[j].departement) == 0) {
                counterUnique++ ;
            }
        }
        printf("     le nombre d'etudiants de departement %s est %d : \n", departementNames[i], counterUnique);
    }
}

void etudiantsMoyenneGeneraleSuperieure(struct etudiant etudiants[], int nombreEtudiant){
    //loop for get somme of all etudiants
    int sommeGenerale = 0 ;
    float moyenneGenerale = 0 ;
    for(int i = 0; i < nombreEtudiant; i++){
        sommeGenerale += + etudiants[i].noteGenerale ;
    }
    moyenneGenerale = sommeGenerale / nombreEtudiant ;
    printf("     les atudiants ayant une moyenne generale superieure a un certain seuil %.2f \n", moyenneGenerale);
    for(int i = 0; i < nombreEtudiant; i++){
        if (etudiants[i].noteGenerale >= moyenneGenerale)
        {
            printf("---- Nom de l'etudiant: %s\n", etudiants[i].nom);
            printf("---- Prenom de l'etudiant: %s\n", etudiants[i].prenom);
            printf("---- Numero unique de l'etudiant: %d\n", etudiants[i].numeroUnique);
            printf("---- Date de naissance de l'etudiant: %d/%d/%d\n",
                   etudiants[i].date.jour,
                   etudiants[i].date.mois,
                   etudiants[i].date.annee);
            printf("---- Departement de l'etudiant: %s\n", etudiants[i].departement);
            printf("---- Note generale de l'etudiant: %.2f\n\n", etudiants[i].noteGenerale);
            printf("-------------------------------------------------------------------------\n");
        }
        
    }
}

void meilleuresNotes(struct etudiant etudiants[], int nombreEtudiant){
     //loop for tri le tableau des note afine de afficher les 3 meilleures 
    int tabMeilleures[nombreEtudiant] ;
    int tmp  = 0;

    for (int i = 0; i < nombreEtudiant; i++) {// affecter les note dans un nouveau tableau
        tabMeilleures[i] = etudiants[i].noteGenerale;
    }

    for (int i = 0; i < nombreEtudiant - 1; i++)//trier le tableau croissance
    {
        for (int y = 0; y < nombreEtudiant - 1 ; y++)
        {
            if(tabMeilleures[y] < tabMeilleures[y + 1] ){
                tmp = tabMeilleures[y];
                tabMeilleures[y] = tabMeilleures[y + 1];
                tabMeilleures[y + 1] = tmp ;
            }
        }
        
    }

    
    for (int i = 0 ; i < 3 && i < nombreEtudiant ; i++)
    {
        int isgrande = 0 ;
        int index = 0 ;

        for (int y = 0; y < nombreEtudiant; y++)
        {
            if (tabMeilleures[i] == etudiants[y].noteGenerale)
            {
                isgrande = 1 ;
                index = y ;
                break;
            }
        }
        if (isgrande)
            {
                printf("\n---- Nom de l'etudiant: %s\n", etudiants[index].nom);
                printf("---- Prenom de l'etudiant: %s\n", etudiants[index].prenom);
                printf("---- Numero unique de l'etudiant: %d\n", etudiants[index].numeroUnique);
                printf("---- Date de naissance de l'etudiant: %d/%d/%d\n",
                       etudiants[index].date.jour,
                       etudiants[index].date.mois,
                       etudiants[index].date.annee);
                printf("---- Departement de l'etudiant: %s\n", etudiants[index].departement);
                printf("---- Note generale de l'etudiant: %.2f\n\n", etudiants[index].noteGenerale);
                printf("-------------------------------------------------------------------------\n");
            }
        
    }
}

void etudiantsReussiChaqueDep(struct etudiant etudiants[], int nombreEtudiant){
    char departementNames[nombreEtudiant][50];
    int isUnique;
    int uniqueCount = 0;

    //loop for put departement unique name on an array "departementNames"
    for (int i = 0; i < nombreEtudiant; i++) {
        isUnique = 1;

        for (int j = 0; j < uniqueCount; j++) {
            if (strcasecmp(etudiants[i].departement, departementNames[j]) == 0) {
                isUnique = 0; 
                break;
            }
            
        }

        if (isUnique) {
            strcpy(departementNames[uniqueCount], etudiants[i].departement);
            uniqueCount++;
        }
    }

    for(int i = 0; i < uniqueCount; i++){
        int counter = 0 ;
        for (int x = 0; x < nombreEtudiant; x++)
        {
            if (etudiants[x].noteGenerale >= 10 && strcasecmp(departementNames[i] , etudiants[x].departement) == 0)
            {
                counter++ ;
            }
        } 
        printf("la moyenne generale de departement %s est : %d\n", departementNames[i] ,counter);
    }
}

//les fonctions de recherche
void recherchUnEtudiant(struct etudiant etudiants[], int nombreEtudiant){
    char nomRechercher[50] ;
    printf("Veuillez entrer le nom d'etudiant Rechercher : ");
    scanf("%s" , nomRechercher);
    for (int i = 0; i < nombreEtudiant; i++)
    {
        if (strcasecmp(etudiants[i].nom , nomRechercher ) == 0)
        {
            printf("---- Nom de l'etudiant: %s\n", etudiants[i].nom);
            printf("---- Prenom de l'etudiant: %s\n", etudiants[i].prenom);
            printf("---- Numero unique de l'etudiant: %d\n", etudiants[i].numeroUnique);
            printf("---- Date de naissance de l'etudiant: %d/%d/%d\n",
                   etudiants[i].date.jour,
                   etudiants[i].date.mois,
                   etudiants[i].date.annee);
            printf("---- Departement de l'etudiant: %s\n", etudiants[i].departement);
            printf("---- Note generale de l'etudiant: %.2f\n\n", etudiants[i].noteGenerale);
            printf("-------------------------------------------------------------------------\n");
            break;
        }
        
    }
    
}

void listParDepartement(struct etudiant etudiants[], int nombreEtudiant){
    char departementRechercher[50] ;
    printf("Veuillez entrer le nom le departement Rechercher : ");
    scanf("%s" , departementRechercher);
    printf("---------------------les etudiants de departement %s : ", departementRechercher);
    for (int i = 0; i < nombreEtudiant; i++)
    {
        if (strcasecmp(etudiants[i].departement , departementRechercher ) == 0)
        {
            printf("---- Nom de l'etudiant: %s\n", etudiants[i].nom);
            printf("---- Prenom de l'etudiant: %s\n", etudiants[i].prenom);
            printf("---- Numero unique de l'etudiant: %d\n", etudiants[i].numeroUnique);
            printf("---- Date de naissance de l'etudiant: %d/%d/%d\n",
                   etudiants[i].date.jour,
                   etudiants[i].date.mois,
                   etudiants[i].date.annee);
            printf("---- Departement de l'etudiant: %s\n", etudiants[i].departement);
            printf("---- Note generale de l'etudiant: %.2f\n\n", etudiants[i].noteGenerale);
            printf("-------------------------------------------------------------------------\n");
        }
        
    }
}

//les fonction de tri
void TriAlphabetique(struct etudiant etudiants[], int nombreEtudiant){
    char tmp[50];
    int tmpN ;

    for (int i = 0; i < nombreEtudiant - 1; i++) {
        for (int j = 0; j < nombreEtudiant - i - 1; j++) {

            if (strcasecmp(etudiants[j].nom, etudiants[j + 1].nom) > 0) {
                //swape Nom
                strcpy(tmp, etudiants[j].nom);
                strcpy( etudiants[j].nom, etudiants[j + 1].nom);
                strcpy( etudiants[j + 1].nom, tmp);
                //swape prenom
                strcpy(tmp, etudiants[j].prenom);
                strcpy( etudiants[j].prenom, etudiants[j + 1].prenom);
                strcpy( etudiants[j + 1].prenom, tmp);
                //swape departement
                strcpy(tmp, etudiants[j].departement);
                strcpy( etudiants[j].departement, etudiants[j + 1].departement);
                strcpy( etudiants[j + 1].departement, tmp);
                //swape jour
                tmpN = etudiants[j].date.jour;
                etudiants[j].date.jour =  etudiants[j + 1].date.jour;
                etudiants[j + 1].date.jour =  tmpN;
                //swape prenom
                tmpN = etudiants[j].date.mois;
                etudiants[j].date.mois = etudiants[j + 1].date.mois;
                etudiants[j + 1].date.mois = tmpN;
                //swape prenom
                tmpN = etudiants[j].date.annee;
                etudiants[j].date.annee = etudiants[j + 1].date.annee;
                etudiants[j + 1].date.annee = tmpN;
                //swape nombreUnique
                tmpN = etudiants[j].numeroUnique;
                etudiants[j].numeroUnique = etudiants[j + 1].numeroUnique;
                etudiants[j + 1].numeroUnique = tmpN;
                //swape note generale
                tmpN = etudiants[j].noteGenerale;
                etudiants[j].noteGenerale = etudiants[j + 1].noteGenerale;
                etudiants[j + 1].noteGenerale = tmpN;
            }
        }
    }

    printf("-----------|| les informations completes des etudiants alphabitique ||-----------\n");
    for (int i = 0; i < nombreEtudiant; i++) {
        printf("           les details personnel : %d \n", i + 1);
        printf("---- Nom de l'etudiant: %s\n", etudiants[i].nom);
        printf("---- Prenom de l'etudiant: %s\n", etudiants[i].prenom);
        printf("---- Numero unique de l'etudiant: %d\n", etudiants[i].numeroUnique);
        printf("---- Date de naissance de l'etudiant: %d/%d/%d\n",
               etudiants[i].date.jour,
               etudiants[i].date.mois,
               etudiants[i].date.annee);
        printf("---- Departement de l'etudiant: %s\n", etudiants[i].departement);
        printf("---- Note generale de l'etudiant: %.2f\n\n", etudiants[i].noteGenerale);
        printf("-------------------------------------------------------------------------\n");
    }


}

void TriParMoyenne(struct etudiant etudiants[], int nombreEtudiant){
    char tmp[50];
    int tmpN ;

    for (int i = 0; i < nombreEtudiant - 1; i++) {
        for (int j = 0; j < nombreEtudiant - i - 1; j++) {

            if (etudiants[j].noteGenerale < etudiants[j + 1].noteGenerale){
                //swape Nom
                strcpy(tmp, etudiants[j].nom);
                strcpy( etudiants[j].nom, etudiants[j + 1].nom);
                strcpy( etudiants[j + 1].nom, tmp);
                //swape prenom
                strcpy(tmp, etudiants[j].prenom);
                strcpy( etudiants[j].prenom, etudiants[j + 1].prenom);
                strcpy( etudiants[j + 1].prenom, tmp);
                //swape departement
                strcpy(tmp, etudiants[j].departement);
                strcpy( etudiants[j].departement, etudiants[j + 1].departement);
                strcpy( etudiants[j + 1].departement, tmp);
                //swape jour
                tmpN = etudiants[j].date.jour;
                etudiants[j].date.jour =  etudiants[j + 1].date.jour;
                etudiants[j + 1].date.jour =  tmpN;
                //swape prenom
                tmpN = etudiants[j].date.mois;
                etudiants[j].date.mois = etudiants[j + 1].date.mois;
                etudiants[j + 1].date.mois = tmpN;
                //swape prenom
                tmpN = etudiants[j].date.annee;
                etudiants[j].date.annee = etudiants[j + 1].date.annee;
                etudiants[j + 1].date.annee = tmpN;
                //swape nombreUnique
                tmpN = etudiants[j].numeroUnique;
                etudiants[j].numeroUnique = etudiants[j + 1].numeroUnique;
                etudiants[j + 1].numeroUnique = tmpN;
                //swape note generale
                tmpN = etudiants[j].noteGenerale;
                etudiants[j].noteGenerale = etudiants[j + 1].noteGenerale;
                etudiants[j + 1].noteGenerale = tmpN;
            }
        }
    }

    printf("-----------|| les informations completes des etudiants par moyenne générale ||-----------\n");
    for (int i = 0; i < nombreEtudiant; i++) {
        printf("           les details personnel : %d \n", i + 1);
        printf("---- Nom de l'etudiant: %s\n", etudiants[i].nom);
        printf("---- Prenom de l'etudiant: %s\n", etudiants[i].prenom);
        printf("---- Numero unique de l'etudiant: %d\n", etudiants[i].numeroUnique);
        printf("---- Date de naissance de l'etudiant: %d/%d/%d\n",
               etudiants[i].date.jour,
               etudiants[i].date.mois,
               etudiants[i].date.annee);
        printf("---- Departement de l'etudiant: %s\n", etudiants[i].departement);
        printf("---- Note generale de l'etudiant: %.2f\n\n", etudiants[i].noteGenerale);
        printf("-------------------------------------------------------------------------\n");
    }

}

void etudiantsReussite(struct etudiant etudiants[], int nombreEtudiant){
    char tmp[50];
    int tmpN ;

    for (int i = 0; i < nombreEtudiant - 1; i++) {
        for (int j = 0; j < nombreEtudiant - i - 1; j++) {

            if (etudiants[j].noteGenerale < etudiants[j + 1].noteGenerale){
                //swape Nom
                strcpy(tmp, etudiants[j].nom);
                strcpy( etudiants[j].nom, etudiants[j + 1].nom);
                strcpy( etudiants[j + 1].nom, tmp);
                //swape prenom
                strcpy(tmp, etudiants[j].prenom);
                strcpy( etudiants[j].prenom, etudiants[j + 1].prenom);
                strcpy( etudiants[j + 1].prenom, tmp);
                //swape departement
                strcpy(tmp, etudiants[j].departement);
                strcpy( etudiants[j].departement, etudiants[j + 1].departement);
                strcpy( etudiants[j + 1].departement, tmp);
                //swape jour
                tmpN = etudiants[j].date.jour;
                etudiants[j].date.jour =  etudiants[j + 1].date.jour;
                etudiants[j + 1].date.jour =  tmpN;
                //swape prenom
                tmpN = etudiants[j].date.mois;
                etudiants[j].date.mois = etudiants[j + 1].date.mois;
                etudiants[j + 1].date.mois = tmpN;
                //swape prenom
                tmpN = etudiants[j].date.annee;
                etudiants[j].date.annee = etudiants[j + 1].date.annee;
                etudiants[j + 1].date.annee = tmpN;
                //swape nombreUnique
                tmpN = etudiants[j].numeroUnique;
                etudiants[j].numeroUnique = etudiants[j + 1].numeroUnique;
                etudiants[j + 1].numeroUnique = tmpN;
                //swape note generale
                tmpN = etudiants[j].noteGenerale;
                etudiants[j].noteGenerale = etudiants[j + 1].noteGenerale;
                etudiants[j + 1].noteGenerale = tmpN;
            }
        }
    }
    printf("-----------|| les informations completes des etudiants reussite trier ||-----------\n");
    for (int i = 0; i < nombreEtudiant; i++) {
        if(etudiants[i].noteGenerale >= 10){
            printf("---- Nom de l'etudiant: %s\n", etudiants[i].nom);
            printf("---- Prenom de l'etudiant: %s\n", etudiants[i].prenom);
            printf("---- Numero unique de l'etudiant: %d\n", etudiants[i].numeroUnique);
            printf("---- Date de naissance de l'etudiant: %d/%d/%d\n",
                   etudiants[i].date.jour,
                   etudiants[i].date.mois,
                   etudiants[i].date.annee);
            printf("---- Departement de l'etudiant: %s\n", etudiants[i].departement);
            printf("---- Note generale de l'etudiant: %.2f\n\n", etudiants[i].noteGenerale);
            printf("-------------------------------------------------------------------------\n");
        }
    }
}

