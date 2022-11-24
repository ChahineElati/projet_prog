#include <stdio.h>
#include <stdlib.h>
#include "aeroport.h"
int main()
{

    COMPAGNIE* cmp;
    int n, i, j, k;
    printf("Donner le nombre de compagnies: ");
    scanf("%d", &n);
    cmp = (COMPAGNIE*) malloc(n * sizeof(COMPAGNIE));
    if(!cmp) exit(-1);
    for(i=0; i<n; i++) {
        printf("Saisir le nom de la compagnie %d: ", i+1);
        scanf("%s", &(cmp+i)->nom);
        printf("Donner le nombres d'avions: ");
        scanf("%d", &(cmp+i)->nb_avions);
        (cmp+i)->avions = (AVION*) malloc((cmp+i)->nb_avions*sizeof(AVION));
        if(!(cmp+i)->avions) exit(-2);
        for(j=0;j<(cmp+i)->nb_avions;j++) {
            printf("Donner l'id de l'avion %d: ", j+1);
            scanf("%s", &((cmp+i)->avions+j)->id);
            printf("Donner le nombre de places: ");
            scanf("%d", &((cmp+i)->avions+j)->nb_places);
            printf("%Donner le type d'avion: ");
            scanf("%s", &((cmp+i)->avions+j)->type);
            printf("Saisir le nombre de passagers: ");
            scanf("%d", &((cmp+i)->avions+j)->nb_passagers);
            ((cmp+i)->avions+j)->passagers = (PASSAGER*) malloc(((cmp+i)->avions+j)->nb_passagers * sizeof(PASSAGER));
            if(!((cmp+i)->avions+j)->passagers) exit(-3);
            for (k=0;k<((cmp+i)->avions+j)->nb_passagers;k++) {
                printf("Donner le nom et prenom du passager: ");
                scanf("%s%s", &(((cmp+i)->avions+j)->passagers+k)->nom, &(((cmp+i)->avions+j)->passagers+k)->prenom);
                printf("Donner l'age du passager: ");
                scanf("%d", &(((cmp+i)->avions+j)->passagers+k)->age);
                printf("Donner le numero de cin: ");
                scanf("%ld", &(((cmp+i)->avions+j)->passagers+k)->num_cin);
            };
            printf("Donner le numero vol: ");
            scanf("%s", &((cmp+i)->avions+j)->vol.num);
            printf("Donner la destination: ");
            scanf("%s", &((cmp+i)->avions+j)->vol.destination);
            printf("Donner la date de depart: ");
            printf("Jour:");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_depart.jour);
            printf("Mois: ");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_depart.mois);
            printf("Annee: ");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_depart.annee);
            printf("Heure: ");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_depart.heure);
            printf("Minute: ");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_depart.minute);
            printf("Donner la date de d'arrivee: ");
            printf("Jour:");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_arrivee.jour);
            printf("Mois: ");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_arrivee.mois);
            printf("Annee: ");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_arrivee.annee);
            printf("Heure: ");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_arrivee.heure);
            printf("Minute: ");
            scanf("%d", &((cmp+i)->avions+j)->vol.date_arrivee.minute);
        }
    }

    for(i=0; i<n; i++) {
        printf("--------------------------------------------\n");
        printf("Compagnie: %s\n\n", (cmp+i)->nom);
        printf("Avions:\n");
        for(j=0; j<(cmp+i)->nb_avions;j++){
            printf("=========================================\n");
            printf("Avion %s\n", ((cmp+i)->avions+j)->id);
            printf("Nombre de places : %d\n", ((cmp+i)->avions+j)->nb_places);
            printf("Type de l'avion : %s\n\n", ((cmp+i)->avions+j)->type);
            printf("Passagers:\n");
            for (k=0;k<((cmp+i)->avions+j)->nb_passagers;k++) {
                printf("+++++++++++++++++++++++++++++++++++++++\n");
                printf("nom et prenom: %s %s\n", (((cmp+i)->avions+j)->passagers+k)->nom, (((cmp+i)->avions+j)->passagers+k)->prenom);
                printf("age: %d\n",(((cmp+i)->avions+j)->passagers+k)->age);
                printf("numero de cin: %ld\n",(((cmp+i)->avions+j)->passagers+k)->num_cin);
                printf("+++++++++++++++++++++++++++++++++++++++\n\n");
            }
            printf("Numero vol: %s\n", ((cmp+i)->avions+j)->vol.num);
            printf("Destination: %s\n", ((cmp+i)->avions+j)->vol.destination);
            printf("Date de depart: %d/%d/%d %d:%d\n", ((cmp+i)->avions+j)->vol.date_depart.annee,((cmp+i)->avions+j)->vol.date_depart.mois, ((cmp+i)->avions+j)->vol.date_depart.jour, ((cmp+i)->avions+j)->vol.date_depart.heure, ((cmp+i)->avions+j)->vol.date_depart.minute);
            printf("Date d'arrivee: %d/%d/%d %d:%d\n", ((cmp+i)->avions+j)->vol.date_arrivee.annee,((cmp+i)->avions+j)->vol.date_arrivee.mois, ((cmp+i)->avions+j)->vol.date_arrivee.jour, ((cmp+i)->avions+j)->vol.date_arrivee.heure, ((cmp+i)->avions+j)->vol.date_arrivee.minute);
            printf("=========================================\n\n");
        };
        printf("--------------------------------------------\n\n");
    }
    return 0;
}
