#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rechercheExhaustive.h"


static void reccExhaustive(int n, int p, int i, char c, char* tab, int *compteur, int *scoresExtremes){
  int nbrN = 0;
  int stockageN = 0;
  int nbrP = 0;
  int stockageP = 0;

  tab[i] = c;

  if(c == 'n')
    n--;

  if(c == 'p')
    p--;

  if(n != 0)
    reccExhaustive(n, p, i+1, 'n', tab, compteur, scoresExtremes);

  if(p != 0)
    reccExhaustive(n, p, i+1, 'p', tab, compteur, scoresExtremes);

  if(n+p == 0){
    (*compteur)++;
    /*printf("\n%d : ", *compteur);
    for(int j = 0; j <= i; j++)
      printf("[%c]", tab[j]);*/

    for(int k = i; k >= 0; k--){
      if(tab[k] == 'n'){
        nbrN++;
        stockageP += nbrP;
      }

      else{
        nbrP++;
        stockageN += nbrN;
      }
    }

    if(abs(stockageN - stockageP) >= 45)
      (*scoresExtremes)++;
    return;
  }
}

void exhaustive(int n, int p){
  int i = 0;
  int compteur = 0;
  int scoresExtremes1 = 0;
  int scoresExtremes2 = 0;
  char tab[n+p];
  if(n>0)
    reccExhaustive(n, p, i, 'n', tab, &compteur, &scoresExtremes1);
  if(p>0)
    reccExhaustive(n, p, i, 'p', tab, &compteur, &scoresExtremes2);

  printf("score extremes : %d, compteur : %d\n", scoresExtremes1 + scoresExtremes2, compteur);
}
