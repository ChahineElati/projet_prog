#include <stdio.h>
#include <stdlib.h>
#include "aeroport.h"
#include <string.h>
#include <math.h>

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
    v.duree = calculerDuree(v.date_depart, v.date_arrivee);

    return v;
}

COMPAGNIE* allouerCompagnie() {

    return (COMPAGNIE*) malloc(sizeof(COMPAGNIE));
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
    do {
        printf("Donner l'etat de l'avion (au_repos ou en_vol): ");
        scanf("%s", av.etat);
    } while(strcmp(av.etat,"en_vol")!=0 && strcmp(av.etat,"au_repos")!=0);
    if(strcmp(av.etat, "en_vol")==0){
        av.passagers = allouerPassagers(&av.nb_passagers);
        if(!av.passagers) exit(-4);
        for(int i=0; i<av.nb_passagers; i++) {
            av.passagers[i] = creerPassager();
        }
        av.vol = creerVol();
    }

    return av;
}

void creerCompagnies(COMPAGNIE ***cmp, int n) {

    for(int i=0; i<n; i++) {
        (*cmp)[i] = allouerCompagnie();
        if(!(*cmp)[i]) exit(-2);
        printf("Saisir le nom de la compagnie %d: ", i+1);
        scanf("%s", (*cmp)[i]->nom);
        (*cmp)[i]->avions = allouerAvions(&(*cmp)[i]->nb_avions);
        if(!(*cmp)[i]->avions) exit(-3);
        for(int j=0; j<(*cmp)[i]->nb_avions; j++) {
            (*cmp)[i]->avions[j] = creerAvion(j);
        }
    }
}

void afficherPassager(PASSAGER psg){
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("nom et prenom: %s %s\n", psg.nom, psg.prenom);
    printf("age: %d\n",psg.age);
    printf("numero de cin: %ld\n",psg.num_cin);
    printf("+++++++++++++++++++++++++++++++++++++++\n\n");


}
void afficherDate(DATE dateD,DATE dateA){
    printf("Date de depart: %d/%d/%d %d:%d\n", dateD.annee,dateD.mois, dateD.jour, dateD.heure, dateD.minute);
    printf("Date d'arrivee: %d/%d/%d %d:%d\n", dateA.annee,dateA.mois, dateA.jour, dateA.heure, dateA.minute);
}
void afficherVole(VOL vol){
    printf("Numero vol: %s\n", vol.num);
    printf("Destination: %s\n", vol.destination);
    afficherDate(vol.date_depart, vol.date_arrivee);
    afficherDuree(vol.duree);
}

void afficherAvion(AVION av){
    printf("=========================================\n");
    printf("Avion %s\n", av.id);
    printf("Nombre de places : %d\n",av.nb_places);
    printf("Type de l'avion : %s\n", av.type);
    printf("Etat de l'avion : %s\n\n", av.etat);
    if(strcmp(av.etat, "en_vol")==0) {
        printf("Passagers:\n");
        for(int i=0 ; i<av.nb_passagers ; i++)
            afficherPassager(av.passagers[i]);
        afficherVole(av.vol);
    }
    printf("=========================================\n\n");
}

void afficherCompagnies(COMPAGNIE **cmp, int n) {
    for(int i=0; i<n; i++) {
        printf("--------------------------------------------\n");
        printf("Compagnie: %s\n\n", cmp[i]->nom );
        for(int j=0; j<cmp[i]->nb_avions; j++) {
            afficherAvion(cmp[i]->avions[j]);
        }
        printf("--------------------------------------------\n");
    }
}

void afficherAvionRepos(AVION av) {
    if(!strcmp(av.etat, "au_repos")){
        afficherAvion(av);
    }
}

void afficherAvionEnVol(AVION av){
    if(strcmp(av.etat , "en_vol")==0){
        afficherAvion(av);
    }
}


   float calculerDuree(DATE date_depart, DATE date_arrivee) {

    float duree=0;

    if(date_arrivee.heure <= date_depart.heure) {
        duree = date_arrivee.heure - date_depart.heure + 24;
    }
    else {
        duree = date_arrivee.heure - date_depart.heure;
    }

    if(date_arrivee.minute <= date_depart.minute) {
        duree += (date_arrivee.minute - date_depart.minute + 60) / 60.f - 1;
    }
    else {
        duree += (date_arrivee.minute - date_depart.minute) / 60.f;
    }

    return duree;
}

void afficherAvionEnVolSelonCompagnie(COMPAGNIE **cmp, int n, char nom[30]){
    for(int i=0; i<n; i++) {
            if(strcmp(cmp[i]->nom, nom)==0) {
                printf("\nLes avions en vol de %s sont:\n", nom);
                for(int j=0; j<cmp[i]->nb_avions ;j++){
                 afficherAvionEnVol(cmp[i]->avions[j]);
                }
            }
    }
}

void afficherAvionReposSelonCompagnie(COMPAGNIE **cmp, int n, char nom[30]){
    for(int i=0; i<n; i++) {
            if(strcmp(cmp[i]->nom, nom)==0) {
                printf("\nLes avions au repos de %s sont:\n", nom);
                for(int j=0; j<cmp[i]->nb_avions ;j++){
                 afficherAvionRepos(cmp[i]->avions[j]);
                 printf("\n");
                }
            }
    }
}

void volSelonDestination(COMPAGNIE** cmp, int n, char destination[30]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j< cmp[i]->nb_avions; j++) {
            if(strcmp(cmp[i]->avions[j].etat ,"en_vol")==0 && strcmp(cmp[i]->avions[j].vol.destination , destination)==0) {
                afficherVole(cmp[i]->avions[j].vol);
                printf("\n");
            }
        }
    }
}

void volSelonDateDepart(COMPAGNIE** cmp, int n, DATE date_depart) {
    for(int i=0; i<n; i++) {
        for(int j=0; j< cmp[i]->nb_avions; j++) {
            if(strcmp(cmp[i]->avions[j].etat ,"en_vol")==0
               && cmp[i]->avions[j].vol.date_depart.annee==date_depart.annee
               && cmp[i]->avions[j].vol.date_depart.mois==date_depart.mois
               && cmp[i]->avions[j].vol.date_depart.jour==date_depart.jour
               && cmp[i]->avions[j].vol.date_depart.heure==date_depart.heure
               && cmp[i]->avions[j].vol.date_depart.minute==date_depart.minute
               ) {
                afficherVole(cmp[i]->avions[j].vol);
                printf("\n");
            }
        }
    }
}

void volPlusCourteDuree(HISTORIQUE_VOLS *logs, int nb_logs) {

    float plus_courte = logs[0].av.vol.duree;
    VOL vol= logs[0].av.vol;

    for(int i=1; i<nb_logs; i++) {
        if(logs[i].av.vol.duree<plus_courte) {
            plus_courte = logs[i].av.vol.duree;
            vol = logs[i].av.vol;
        }
    }
    afficherVole(vol);
    printf("\n");
}

void afficherDuree(float duree) {
    printf("Duree: %d heures et %d minutes\n", (int) truncf(duree), (int)((duree - truncf(duree)) * 60));
}

int nbAvionEnvol(COMPAGNIE** cmp, int n) {

    int nb=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<cmp[i]->nb_avions; j++) {
            if(strcmp(cmp[i]->avions[j].etat ,"en_vol")==0) {
                nb++;
            }
        }
    }
    return nb;

}

void creerLogs(COMPAGNIE **cmp, int n, HISTORIQUE_VOLS *logs) {

    int k =0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<cmp[i]->nb_avions; j++) {
            if(strcmp(cmp[i]->avions[j].etat ,"en_vol")==0) {
                logs[k].av = cmp[i]->avions[j];
                logs[k].cmp = cmp[i]->nom;
                k++;
            }
        }
    }
}

int nbPassagersCompagnie(HISTORIQUE_VOLS *logs, char cmp[30], int n) {

    int nb=0;

    for(int i=0; i<n; i++) {
        if(strcmp(logs[i].cmp, cmp)==0) {
            nb += logs[i].av.nb_passagers;
        }
    }

    return nb;
}
