#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wilcoxon.h"

/* ------------------------------------------------------------------------- *
 * Est le nombre de n-p mots dont le score de Wilcoxon est i pour les croix ( np - i pour les ronds )
 *
 * PARAMETRES
 * n           Nombres d'éléments de n avec n >= 0
 * p           Nombres d'éléments de p avec p >= 0
 * i           Compteur de i jusque n*p
 *
 * RETOURNE
 * int:       score de wilcoxon
 * ------------------------------------------------------------------------- */
static int w(unsigned int n, unsigned int p, unsigned int i);

static int w(unsigned int n, unsigned int p, unsigned int i){

  if(i > n*p)
    return 0;

  if((i == 0 && p == 0 ) ||( i == 0 && n == 0))
    return 1;

  return (w(n, p-1, i-n) + w(n-1, p, i));
}

void analyseCombinatoire(unsigned int n, unsigned int p){
  float temps;
  clock_t t1, t2;
  unsigned int mots = 0; // Le nombres de mots réalisable avec n 'n' et p 'p'
  unsigned int sExtremes = 0; // Le nombre de score extreme c'est à dire, dont le score entre n et p à une différence d'au moins 45 points

  t1 = clock(); // Lancement du chrono

  for(unsigned int i = 0; i <= n*p; i++){

    if(abs(i - ((n*p)-i)) >= 45) // un écart de 45 points ou plus est considéré comme un score extreme
      sExtremes += w(n, p, i);

    else
      mots += w(n, p, i);
  }

  mots += sExtremes;

  t2 = clock(); // fin du chrono
  temps = (float)(t2-t1)/CLOCKS_PER_SEC; // durée de l'exécution du programme

  printf("durée de l'exécution = %f secondes\n", temps);
  printf("\nil y a exactement %u mots, parmi lesquels %u donnent lieu à des scores \"extremes\" %f %%\n\n", mots, sExtremes, (float)(sExtremes)/(float)(mots)*100);


}
