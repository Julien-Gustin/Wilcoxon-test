#include <stdio.h>
#include <math.h>
#include <getopt.h>
#include "simulation.h"
#include "analyseCombinatoire.h"
#include "rechercheExhaustive.h"

int main(int argc, char *argv[]) {
  char *optstring = ":sce";
  char val;
  int check = 0;
  int n;
  int p;
  int essais;



  while((val=getopt(argc, argv, optstring))!=EOF){
    switch(val){

      case 's':
        printf("Veuillez insérer le nombre de n\n");
        scanf("%d", &n);

        printf("Veuillez insérer le nombre de p\n");
        scanf("%d", &p);

        printf("Veuillez insérer le nombre d'essais que vous voulez effectuer\n");
        scanf("%d", &essais);
        simulation(n, p, essais);
        check = 1;
        break;

      case 'c':
        printf("Veuillez insérer le nombre de n\n");
        scanf("%d", &n);

        printf("Veuillez insérer le nombre de p\n");
        scanf("%d", &p);

        analyseCombinatoire(n, p);
        check = 1;
        break;

      case 'e':
        printf("Veuillez insérer le nombre de n\n");
        scanf("%d", &n);

        printf("Veuillez insérer le nombre de p\n");
        scanf("%d", &p);

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
