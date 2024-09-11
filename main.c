#include <stdio.h>
#include <string.h>
#include "fonctions.h"


int main() {
    int option;
    int nombreEtudiant = 0;
    struct etudiant etudiants[100];

    while (1) {
        printf("============== Demarrez la gestion en utilisant les commandes suivants =============\n");
        printf("\n");
        printf("      1 - Ajouter un etudiant\n");
        printf("      2 - Modifier ou supprimer un etudiant\n");
        printf("      3 - Afficher les details d'un etudiant\n");
        printf("      4 - Calculer la moyenne generale\n");
        printf("      5 - Statistiques\n");
        printf("      6 - Rechercher un etudiant par (nom / liste par departement)\n");
        printf("      7 - Trier les etudiants par (alphabetique / moyenne generale / reussite)\n");
        printf("      0 - Quitter le programme\n");
        printf("Veuillez entrer votre choix: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 0:
                return 0;
            case 1:
                AjouterUnEtudiant(etudiants, nombreEtudiant);
                nombreEtudiant++;
                break;
            case 2:
                printf("     1-Modifier          2-Supprimer   \n");
                scanf("%d",&option);
                if (option == 1){
                    Modifier(etudiants, nombreEtudiant);
                }else{
                    Supprimer(etudiants, &nombreEtudiant);
                }
                break;
            case 3:
                afficher(etudiants, nombreEtudiant);
                break;
            case 4:
                CalculerLaMoyenneGenerale(etudiants, nombreEtudiant);
                break;
            case 5:
                printf(" --------------- les statistique -----------------\n");
                printf("     1-Afficher le nombre total d'etudiants inscrits :\n");
                printf("     2-Afficher le nombre d'etudiants dans chaque departement :\n");
                printf("     3-Afficher les etudiants ayant une moyenne generale superieure a un certain seuil :\n");
                printf("     4-Afficher les 3 etudiants ayant les meilleures notes :\n");
                printf("     5-Afficher le nombre d'etudiants ayant reussi dans chaque departement :\n");
                printf("   Veuillez entrer votre choix: \n");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                    nombreTotale(etudiants, nombreEtudiant);
                    break;
                
                case 2:
                    nombrechaqueDep(etudiants, nombreEtudiant);
                    break;
                
                case 3:
                    etudiantsMoyenneGeneraleSuperieure(etudiants, nombreEtudiant);
                    break;
                
                case 4:
                    meilleuresNotes(etudiants, nombreEtudiant);
                    break;
                
                case 5:
                    etudiantsReussiChaqueDep(etudiants, nombreEtudiant);
                    break;
                default:
                    break;
                }
                break;
            case 6:
                printf(" --------------- Rechercher un etudiant par : -----------------\n");
                printf("     1-Rechercher un etudiant par son nom :\n");
                printf("     2-Afficher la liste des etudiants inscrits dans un departement specifique :\n");
                printf("   Veuillez entrer votre choix: \n");
                scanf("%d", &option);
                if(option == 1){
                    recherchUnEtudiant(etudiants, nombreEtudiant);
                }else if (option == 2)
                {
                    listParDepartement(etudiants, nombreEtudiant);
                }
                break;
            case 7:
                printf(" --------------- Trier un etudiant par : -----------------\n");
                printf("     1-Tri alphabetique des etudiants en fonction de leur nom (de A a Z) :\n");
                printf("     2-Tri des etudiants par moyenne genenale, du plus eleve au plus faible ou inversement :\n");
                printf("     3-Tri des etudiants selon leur statut de reussite (ceux ayant une moyenne superieure ou egale a 10/20) :\n");
                printf("   Veuillez entrer votre choix: \n");
                scanf("%d", &option);
                if(option == 1){
                    TriAlphabetique(etudiants, nombreEtudiant);
                }else if (option == 2){
                    TriParMoyenne(etudiants, nombreEtudiant);
                }else if (option == 3){
                    etudiantsReussite(etudiants, nombreEtudiant);
                }
                break;
            default:
                printf("Option invalide.\n");
                break;
        }

        // Continue or quit
        printf("0 - Pour quitter le programme\n");
        printf("1 - Pour continuer\n");
        scanf("%d", &option);
        if (option == 0) {
            return 0;
        }
    }

    return 0;
}
