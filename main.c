#include <stdio.h>
#include <stdlib.h>
#include "aeroport.h"
int main()
{

    COMPAGNIE* cmp;
    int n, i;
    cmp = allouerCompagnies(&n);
    if(!cmp) exit(-1);
    for(i=0; i<n; i++) {
        cmp[i] = creerCompagnie(i);
    }

    for(i=0; i<n; i++) {
            afficherCompagnie(cmp[i]);

    }
    return 0;
}
