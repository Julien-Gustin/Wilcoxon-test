#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wilcoxon.h"

void simulation(unsigned int n, unsigned int p, unsigned int essais){ // o x

  int somme = n+p;
  char *tab = malloc(sizeof(char)*somme);
  if(tab == NULL)
    return;

  unsigned int nbrN = 0; // Nombre de 'n' qui ont déja été parcourus
  unsigned int stockageN = 0; // score de wilcoxon de n
  unsigned int nbrP = 0; // Nombre de 'p' qui ont déja été parcourus
  unsigned int stockageP = 0; // score de wilcoxon de p
  unsigned long scoresExtremes = 0;

  unsigned int pTmp = p;
  unsigned int nTmp = n;

  float temps;
  clock_t t1, t2;

  t1 = clock(); // début du chrono

  srand(time(NULL));

  for(unsigned int j = 0; j < essais; j++){
    nTmp = n;
    pTmp = p;
    nbrN = 0;
    stockageN = 0;
    nbrP = 0;
    stockageP = 0;

    for(int i = somme-1; i >= 0 ; i--){
      if(rand()%(pTmp + nTmp) < pTmp){ // randome exacte de tel maniere d'avoir p chance sur n+p d'avoir un 'p' et donc n chance sur n+p d'avoir un 'n'
        pTmp--;
        tab[i] = 'p';
        nbrP++;
        stockageP += nbrN;
      }

      else{
        nTmp--;
        tab[i] = 'n';
        nbrN++;
        stockageN += nbrP;
      }
    }

    if(abs(stockageN - stockageP) >= 45)
        scoresExtremes++;
  }

      t2 = clock(); // fin du chrono
      temps = (float)(t2-t1)/CLOCKS_PER_SEC;
      printf("durée de l'exécution = %f secondes\n", temps);
      printf("\nIl y a %lu scores extremes pour %u essais, %f %% ", scoresExtremes, essais, (float)(scoresExtremes)/(float)(essais)*100);

}
