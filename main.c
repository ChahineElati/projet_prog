#include <stdio.h>
#include <stdlib.h>
#include "aeroport.h"
int main()
{

    COMPAGNIE **cmp;
    int n;
    printf("Donner le nombre de compagnies: ");
    scanf("%d", &n);
    cmp = (COMPAGNIE**) malloc(n * sizeof(COMPAGNIE*));
    if(!cmp) exit(-1);
    creerCompagnies(&cmp, n);
    afficherCompagnies(cmp, n);
    afficherAvionRepos(cmp, n);
    afficherAvionEnVol(cmp, n);
    return 0;

}
