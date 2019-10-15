#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rechercheExhaustive.h"

static void calculScoreExtreme(char *tab, int taille, int *scoresExtremes){
  int nbrN = 0;
  int stockageN = 0;
  int nbrP = 0;
  int stockageP = 0;

  for(int k = taille; k >= 0; k--){
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


static void reccExhaustive(int n, int p, int i, char *tab, char c, int *compteur, int *scoresExtremes){

  if(i >= 0)
    tab[i] = c;

  if(n+p == 0){
    /*printf("\n%d : ", *compteur);
    for(int j = 0; j <= i; j++)
      printf("[%c]", tab[j]);*/

    calculScoreExtreme(tab, i, scoresExtremes);

    (*compteur)++;
    return;
  }

  if(n != 0)
    reccExhaustive(n-1, p, i+1, tab, 'n', compteur, scoresExtremes);

  if(p != 0)
    reccExhaustive(n, p-1, i+1, tab, 'p', compteur, scoresExtremes);

}


void exhaustive(int n, int p){
  int compteur = 0;
  int scoresExtremes = 0;
  char tab[n+p];

  reccExhaustive(n, p, -1, tab, '/', &compteur, &scoresExtremes);

  printf("\n score extremes %d  sur %d \n ce qui correspond à %f %%", scoresExtremes, compteur, (float)(scoresExtremes)/(float)(compteur)*100);
}
