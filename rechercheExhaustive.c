#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wilcoxon.h"

/* ------------------------------------------------------------------------- *
 * Calcul le nombres de scores extremes d'un tableau donné
 *
 * PARAMETRES
 * tab                 Tableau de char contenant une combinaison possible de n 'n' et p 'p' et donc de taille n+p
 * taille              La taille du tableau avec taille >= 0
 * scoresExtremes      L'adresse du nombres de scores extremes
 *
 * ------------------------------------------------------------------------- */
static void calculScoreExtreme(char *tab, unsigned int taille, unsigned int *scoresExtremes);

/* ------------------------------------------------------------------------- *
 * Crée toute les combinaisons possibles de n 'n' et p 'p'
 *
 * PARAMETRES
 * n                   Nombres d'éléments de n restant avec n >= 0
 * p                   Nombres d'éléments de p restant avec p >= 0
 * i                   indice tel que 0 <= i <= taille du tableau tab, ( sauf pour l'init ou i = -1)
 * tab                 Tableau de char
 * c                   Caractère tel que c = 'n' ou 'p'
 * Mots                Compte le nombres de mots différent possible avec n 'n' et p 'p'
 * taille              La taille du tableau avec taille >= 0
 * scoresExtremes      L'adresse du nombres de scores extremes
 *
 * ------------------------------------------------------------------------- */
static void reccExhaustive(unsigned int n, unsigned int p, int i, char *tab, char c, unsigned int *mot, unsigned int *scoresExtremes);

static void calculScoreExtreme(char *tab, unsigned int taille, unsigned int *scoresExtremes){
  unsigned int nbrN = 0; // Nombres de 'n' déja parcourus
  unsigned int stockageN = 0; // stocke le score de N
  unsigned int nbrP = 0; // Nombres de 'p' déja parcourus
  unsigned int stockageP = 0; // stocke le score de P

  for(int k = taille; k >= 0; k--){ // parcour le tableau pour calculer le score de wilcoxon et le nombre de score extreme qui en découle
    if(tab[k] == 'n'){
      nbrN++;
      stockageP += nbrP;
    }

    else{
      nbrP++;
      stockageN += nbrN;
    }
  }

  if(abs(stockageN - stockageP) >= 45) // calcul l'ecart du score de wilcoxon entre 'n' et 'p'
    (*scoresExtremes)++;
  return;
}

static void reccExhaustive(unsigned int n, unsigned int p, int i, char *tab, char c, unsigned int *mot, unsigned int *scoresExtremes){

  if(i >= 0) // ne remplis pas le tableau à la première itération car i = -1
    tab[i] = c;

  if(n+p == 0){
    calculScoreExtreme(tab, i, scoresExtremes);
    (*mot)++;
    return;
  }

  if(n != 0)
    reccExhaustive(n-1, p, i+1, tab, 'n', mot, scoresExtremes);

  if(p != 0)
    reccExhaustive(n, p-1, i+1, tab, 'p', mot, scoresExtremes);

}


void exhaustive(unsigned int n, unsigned int p){
  float temps;
  clock_t t1, t2;

  t1 = clock(); // lancement du chrono

  unsigned int mot = 0; // nombres de combinaison de mots possibles
  unsigned int scoresExtremes = 0; // nombres de score extremes
  char tab[n+p]; // tableau de la taille du nombre de n + p

  reccExhaustive(n, p, -1, tab, '/', &mot, &scoresExtremes);

  t2 = clock(); // fin du chrono
  temps = (float)(t2-t1)/CLOCKS_PER_SEC;

  printf("durée de l'exécution = %f secondes\n", temps);
  printf("\n score extremes %u  sur %u \n ce qui correspond à %f %%", scoresExtremes, mot, (float)(scoresExtremes)/(float)(mot)*100);
}
