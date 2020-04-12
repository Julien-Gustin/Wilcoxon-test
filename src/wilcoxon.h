#ifndef __WILCOXON__
#define __WILCOXON__

/* ------------------------------------------------------------------------- *
 * Calcul le score de wilcoxon et les scores extremes de n 'n' et p 'p' par analyse combinatoire
 *
 * PARAMETRES
 * n           Nombres d'éléments de n avec n >= 0
 * p           Nombres d'éléments de p avec p >= 0
 *
 * ------------------------------------------------------------------------- */
void analyseCombinatoire(unsigned int n, unsigned int p);

/* ------------------------------------------------------------------------- *
 * Calcul le score de wilcoxon et les scores extremes de n 'n' et p 'p' par recherche exhaustive
 *
 * PARAMETRES
 * n           Nombres d'éléments de n avec n >= 0
 * p           Nombres d'éléments de p avec p >= 0
 *
 * ------------------------------------------------------------------------- */
void exhaustive(unsigned int n, unsigned int p);

/* ------------------------------------------------------------------------- *
 * Calcul le score de wilcoxon et les scores extremes de n 'n' et p 'p' par recherche exhaustive
 *
 * PARAMETRES
 * n           Nombres d'éléments de n avec n >= 0
 * p           Nombres d'éléments de p avec p >= 0
 * essais
 *
 * ------------------------------------------------------------------------- */
void simulation(unsigned int n, unsigned int p, unsigned int essais);

#endif
