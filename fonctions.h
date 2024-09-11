

struct DateDeNaissance {
    int jour;
    int mois;
    int annee;
};

struct etudiant {
    int numeroUnique;
    char nom[30];
    char prenom[30];
    struct DateDeNaissance date;
    char departement[30];
    float noteGenerale;
};


void AjouterUnEtudiant(struct etudiant etudiants[], int nombreEtudiant);

void afficher(struct etudiant etudiants[], int nombreEtudiant);

void Modifier(struct etudiant etudiants[], int nombreEtudiant);

void Supprimer(struct etudiant etudiants[], int *nombreEtudiant);

void CalculerLaMoyenneGenerale(struct etudiant etudiants[], int nombreEtudiant);

// Statistique Fonctions 
void nombreTotale(struct etudiant etudiants[], int nombreEtudiant);

void nombrechaqueDep(struct etudiant etudiants[], int nombreEtudiant);

void etudiantsMoyenneGeneraleSuperieure(struct etudiant etudiants[], int nombreEtudiant);

void meilleuresNotes(struct etudiant etudiants[], int nombreEtudiant);

void etudiantsReussiChaqueDep(struct etudiant etudiants[], int nombreEtudiant);

//les fonctions de recherche
void recherchUnEtudiant(struct etudiant etudiants[], int nombreEtudiant);

void listParDepartement(struct etudiant etudiants[], int nombreEtudiant);

//les fonction de tri
void TriAlphabetique(struct etudiant etudiants[], int nombreEtudiant);

void TriParMoyenne(struct etudiant etudiants[], int nombreEtudiant);

void etudiantsReussite(struct etudiant etudiants[], int nombreEtudiant);