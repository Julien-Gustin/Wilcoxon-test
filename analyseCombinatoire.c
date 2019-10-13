#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "analyseCombinatoire.h"

static int w(int n, int p, int i);

static int w(int n, int p, int i){


  if(i < 0 || i > n*p)
    return 0;

  if((i == 0 && p == 0 ) ||( i == 0 && n == 0))
    return 1;


  return (w(n, p-1, i-n) + w(n-1, p, i));
}

void analyseCombinatoire(int n, int p){
  unsigned int mots = 0;
  unsigned int sExtremes = 0;

  for(int i = 0; i <= n*p; i++){

    if(abs(i - ((n*p)-i)) >= 45)
      sExtremes += w(n, p, i);

    else
      mots += w(n, p, i);
  }
  mots += sExtremes;

  printf("\nil y a exactement %u mots, parmi lesquels %u donnent lieu à des scores \"extremes\" %f %%\n\n", mots, sExtremes, (float)(sExtremes)/(float)(mots)*100);


}
