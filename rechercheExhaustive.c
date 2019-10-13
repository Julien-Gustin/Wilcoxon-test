#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rechercheExhaustive.h"


void switchVal(char *tab, int x, int y){
  char tmp = tab[y];
  tab[y] = tab[x];
  tab[x] = tmp;

}

void mettreXDernierePos(char *tab, int tailleTab, int *check){

  int pos = -1;

  for(int i = 0 ; i < tailleTab ;i++){
    //printf("[%c]", tab[i]);
    if(i != 0){
      if(tab[i-1] == 'n' && tab[i] == 'p')
        pos = i;
    }

    if(tab[i] == 'p')
      *check = i;



  }


  if(pos != -1){
    switchVal(tab, pos-1, pos);

    int j = pos +1;
    int k = tailleTab-1;

  while(j < k){
    switchVal(tab, j, k);
    j++;
    k--;

  }
    }
}


void exhaustive(int n, int p){

  int nbrN = 0;
  int nbrP = 0;
  int stockageN = 0;
  int stockageP = 0;

  char *tab = malloc(sizeof(char) *n+p);

  for(int i = 0; i < n+p ; i++){

    if(i < n)
      tab[i] = 'n';

    else
      tab[i] = 'p';

  }

  //printf("\n");
    //printf("\n");

  //printf("\n");
  int j = 0;
  int check;

  int scoresExtremes = 0;

  while(check != p-1){

    nbrN = 0;
    nbrP = 0;
    stockageN = 0;
    stockageP = 0;


      //printf("%d: ", j+1);
    mettreXDernierePos(tab, n+p, &check);
    for(int i = n+p-1; i >= 0; i--){
      if(tab[i] == 'n'){
        nbrN++;
        stockageP += nbrP;

      }
      else{
        nbrP++;
        stockageN += nbrN;
      }


    }

    if(abs(stockageN - stockageP) >= 45)
      scoresExtremes++;

    //printf("\n");
    j++;

    }


    printf("\n score extremes %d \n", scoresExtremes);



}
