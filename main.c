#include <stdio.h>
#include <stdlib.h>
#include "aeroport.h"
int main()
{

    char nom_compagnie[30], destination[30];
    DATE date_depart;
    COMPAGNIE **cmp;
    int n, nb_logs;
    HISTORIQUE_VOLS *logs;
    printf("Donner le nombre de compagnies: ");
    scanf("%d", &n);
    cmp = (COMPAGNIE**) malloc(n * sizeof(COMPAGNIE*));
    if(!cmp) exit(-1);
    creerCompagnies(&cmp, n);
    nb_logs = nbAvionEnvol(cmp, n);
    logs = (HISTORIQUE_VOLS*) malloc(nb_logs * sizeof(HISTORIQUE_VOLS));
    creerLogs(cmp, n, logs);
    afficherCompagnies(cmp, n);
    printf("\nDonner le nom de compagnie: ");
    scanf("%s", nom_compagnie);
    afficherAvionEnVolSelonCompagnie(cmp, n, nom_compagnie);
    afficherAvionReposSelonCompagnie(cmp, n, nom_compagnie);
    printf("\nLe nombre de passagers de compagnie %s: %d\n", nom_compagnie, nbPassagersCompagnie(logs, nom_compagnie, nb_logs));
    printf("\nDonner la destination: ");
    scanf("%s", destination);
    printf("\nLes vols selon la destination:\n\n");
    volSelonDestination(cmp, n, destination);
    printf("\nDonner la date de depart:\n");
    date_depart = Date();
    printf("\nLes vols selon la date de depart:\n\n");
    volSelonDateDepart(cmp, n, date_depart);
    printf("\nLe vol avec la plus courte duree:\n\n");
    volPlusCourteDuree(logs, nb_logs);

    return 0;
}
