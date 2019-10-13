#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simulation.h"


void simulation(int o, int x, int essais){
  srand(time(NULL));
  int somme = o+x;
  char *tab = malloc(sizeof(char)*somme);

  unsigned int nbrRond;
  unsigned int stockageRond;
  unsigned int nbrCroix;
  unsigned int stockageCroix;

  int i;

  unsigned long scoresExtremes = 0;

  int xtmp;
  int otmp;

  for(int j = 0; j < essais; j++){

    otmp = o;
    xtmp = x;
    nbrRond = 0;
    stockageRond = 0;
    nbrCroix = 0;
    stockageCroix = 0;

    for(i = somme-1; i >= 0 ; i--){
      if(rand()%(xtmp + otmp) < xtmp){
        xtmp--;
        tab[i] = 'x';
        //printf("[x]");
        nbrCroix++;
        stockageCroix += nbrRond;
      }

      else{
        otmp--;
        tab[i] = 'o';
        //printf("[o]");
        nbrRond++;
        stockageRond += nbrCroix;
      }

    }
    //printf("\n");


        if(abs(stockageRond - stockageCroix) >= 45)
          scoresExtremes++;


      //printf("\n Les Ronds en remportent %u et les croix %u\n", stockageRond, stockageCroix);

    }


      printf("\nIl y a %lu scores extremes, %f %% ", scoresExtremes, (float)(scoresExtremes)/(float)(essais)*100);


free(tab);
}
