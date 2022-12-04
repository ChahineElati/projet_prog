struct date
{
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;
};
typedef struct date DATE;

struct vol
{
    char num[30]; // numéro de vol
    char destination[30];
    DATE date_depart;
    DATE date_arrivee;
    float duree;
};
typedef struct vol VOL;

struct passager
{
    char nom[30];
    char prenom[30];
    int age;
    long int num_cin; // numéro de carte d'identité
};
typedef struct passager PASSAGER;

struct avion
{
    char id[30]; //id de l'avion
    int nb_places;
    VOL vol;
    PASSAGER *passagers;
    int nb_passagers;
    char type[30];
    char etat[30];
};
typedef struct avion AVION;

struct compagnie
{
    char nom[30];
    AVION *avions;
    int nb_avions;
};
typedef struct compagnie COMPAGNIE;

struct historique_vols
{
    char cmp[30]; //compagnie
    AVION av; //avion
};
typedef struct historique_vols HISTORIQUE_VOLS;

COMPAGNIE* allouerCompagnie();
AVION* allouerAvions(int*);
PASSAGER* allouerPassagers(int*);
void creerCompagnies(COMPAGNIE***, int);
AVION creerAvion(int);
PASSAGER creerPassager();
DATE Date();
VOL creerVol();
void saisirType(char []);
void afficherCompagnies(COMPAGNIE**, int);
void afficherAvion(AVION);
void afficherPassager(PASSAGER);
void afficherVole(VOL);
void afficherDate(DATE,DATE);
float calculerDuree(DATE, DATE);
void afficherAvionEnVol(COMPAGNIE**, int);
void afficherAvionRepos(COMPAGNIE**, int);
