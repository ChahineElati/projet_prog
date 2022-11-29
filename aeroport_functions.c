#include <stdio.h>
#include <stdlib.h>
#include "aeroport.h"
#include <string.h>

void saisirType(char type[30]) {
    do {
        printf("Donner le type d'avion (court, moyen, long): ");
        scanf("%s", type);
    } while(strcmp(type, "court")!=0 && strcmp(type, "moyen")!=0 && strcmp(type, "long")!=0);
}

DATE Date() {

    DATE d;

    printf("\nJour: ");
    scanf("%d", &d.jour);
    printf("Mois: ");
    scanf("%d", &d.mois);
    printf("Annee: ");
    scanf("%d", &d.annee);
    printf("Heure: ");
    scanf("%d", &d.heure);
    printf("Minute: ");
    scanf("%d", &d.minute);

    return d;
}

VOL creerVol() {

    VOL v;

    printf("Donner le numero vol: ");
    scanf("%s", v.num);
    printf("Donner la destination: ");
    scanf("%s", v.destination);
    printf("Donner la date de depart: ");
    v.date_depart = Date();
    printf("Donner la date d'arrivee: ");
    v.date_arrivee = Date();
//     v.duree = calculerDuree(v.date_depart, v.date_arrivee);
    return v;
}

COMPAGNIE* allouerCompagnies(int *nb_compagnies) {

    printf("Donner le nombre de compagnies: ");
    scanf("%d", nb_compagnies);

    return (COMPAGNIE*) malloc(*nb_compagnies * sizeof(COMPAGNIE));
}

AVION* allouerAvions(int *nb_avions) {

    printf("Donner le nombre d'avions: ");
    scanf("%d", nb_avions);

    return (AVION*) malloc(*nb_avions * sizeof(AVION));
}

PASSAGER* allouerPassagers(int *nb_passagers) {

    printf("Donner le nombre de passagers: ");
    scanf("%d", nb_passagers);

    return (PASSAGER*) malloc(*nb_passagers * sizeof(PASSAGER));
}

PASSAGER creerPassager() {

    PASSAGER psg;

    printf("Donner le nom et prenom du passager: ");
    scanf("%s%s", psg.nom, psg.prenom);
    printf("Donner l'age du passager: ");
    scanf("%d", &psg.age);
    printf("Donner le numero de cin: ");
    scanf("%ld", &psg.num_cin);

    return psg;
}

AVION creerAvion(int i) {

    AVION av;

    printf("Donner l'id de l'avion %d: ", i+1);
    scanf("%s", av.id);
    saisirType(av.type);
    switch (av.type[0]) {
    case 'c':
        av.nb_places = 200;
        break;
    case 'm':
        av.nb_places = 400;
        break;
    case 'l':
        av.nb_places = 600;
        break;
    }
    av.passagers = allouerPassagers(&av.nb_passagers);
    for(int i=0; i<av.nb_passagers; i++) {
        av.passagers[i] = creerPassager();
    }
    av.vol = creerVol();
    av.etat = "au_repos";

    return av;
}

COMPAGNIE creerCompagnie(int i) {

    COMPAGNIE cmp;

    printf("Saisir le nom de la compagnie %d: ", i+1);
    scanf("%s", cmp.nom);
    cmp.avions = allouerAvions(&cmp.nb_avions);
    for(int i=0; i<cmp.nb_avions; i++) {
        cmp.avions[i] = creerAvion(i);
    }

    return cmp;
}

float calculerDuree(DATE date_depart, DATE date_arrivee) {

    float duree;
    if(date_arrivee.jour - date_depart.jour == 0) {
        duree = date_arrivee.heure - date_depart.heure;
    }

    return duree;
}
