#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <getopt.h>
#include "wilcoxon.h"

int main(int argc, char *argv[]) {
  char *optstring = ":sce"; //argument du programme // s = simulation , c = analyse combinatoire et e = recherche exhaustive
  char val;
  short check = 0; // permet de vérifier si l'utilisateur compile bien aved -s , -c ou -e
  unsigned int n;
  unsigned int p;
  unsigned int essais;

  while((val=getopt(argc, argv, optstring))!=EOF){
    switch(val){

      case 's':
        printf("Veuillez insérer le nombre de n\n");
        scanf("%u", &n);

        printf("Veuillez insérer le nombre de p\n");
        scanf("%u", &p);

        printf("Veuillez insérer le nombre d'essais que vous voulez effectuer\n");
        scanf("%u", &essais);
        simulation(n, p, essais);
        check = 1;
        break;

      case 'c':
        printf("Veuillez insérer le nombre de n\n");
        scanf("%u", &n);

        printf("Veuillez insérer le nombre de p\n");
        scanf("%u", &p);

        analyseCombinatoire(n, p);
        check = 1;
        break;

      case 'e':
        printf("Veuillez insérer le nombre de n\n");
        scanf("%u", &n);

        printf("Veuillez insérer le nombre de p\n");
        scanf("%u", &p);

        exhaustive(n, p);
        check =1;
        break;

      default:
        printf("erreur");
        }
    }

    if(!check)
      printf("-s pour une simulation, -c pour l'analyse combinatoire, -e pour une recherche exhaustive\n");

}
