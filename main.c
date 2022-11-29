#include <stdio.h>
#include <stdlib.h>
#include "aeroport.h"
int main()
{

    COMPAGNIE* cmp;
    int n, i, j, k;
    cmp = allouerCompagnies(&n);
    if(!cmp) exit(-1);
    for(i=0; i<n; i++) {
        cmp[i] = creerCompagnie(i);
    }

    for(i=0; i<n; i++) {
        printf("--------------------------------------------\n");
        printf("Compagnie: %s\n\n", (cmp+i)->nom);
        printf("Avions:\n");
        for(j=0; j<(cmp+i)->nb_avions;j++){
            printf("=========================================\n");
            printf("Avion %s\n", ((cmp+i)->avions+j)->id);
            printf("Nombre de places : %d\n", ((cmp+i)->avions+j)->nb_places);
            printf("Type de l'avion : %s\n", ((cmp+i)->avions+j)->type);
            printf("Etat de l'avion : %s\n\n", ((cmp+i)->avions+j)->etat);
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
//            printf("Duree: %s\n", ((cmp+i)->avions+j)->vol.duree);
            printf("=========================================\n\n");
        };
        printf("--------------------------------------------\n\n");
    }
    return 0;
}
