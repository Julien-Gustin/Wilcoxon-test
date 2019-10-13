#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rechercheExhaustive.h"

static void switchVal(char *tab, int x, int y);
/* switch le contenu de tab[x] et tab[y] */

static void mettreXDernierePos(char *tab, int tailleTab, int *check);
/* permet de mettre tout les 'p' à la fin du tableau afin d'exploiter tout les possibilités du tableau */


static void switchVal(char *tab, int x, int y){
  char tmp = tab[y];
  tab[y] = tab[x];
  tab[x] = tmp;

}

static void mettreXDernierePos(char *tab, int tailleTab, int *check){
  int pos = -1;

  for(int i = 0 ; i < tailleTab ;i++){
    //printf("[%c]", tab[i]);
    if(i != 0){ // tab[-1] n'existe pas
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
  // init variable

  int nbrN;
  int nbrP;
  int stockageN;
  int stockageP;
  int j = 0;
  int check;
  int scoresExtremes = 0;

  // fin init variable

  char *tab = malloc(sizeof(char) *n+p); //crée un tableau de la taille du nombre de n + le nombre de p

  for(int i = 0; i < n+p ; i++){

    if(i < n)
      tab[i] = 'n';

    else
      tab[i] = 'p';
  }
  //printf("\n");
    //printf("\n");

  //printf("\n");


  while(check != p-1){ //s'arrete si le dernier p est à la position du nombre de p ce qui veut dire que le tableau à été inverser [n][p][p] => [p][p][n] et donc toute les possibilités de tab ont été  crée

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

    printf("\n score extremes %d  sur %d \n ce qui correspond à %f %%", scoresExtremes, j, (float)(scoresExtremes)/(float)(j)*100);
    free(tab);


}
