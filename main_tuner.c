
/* main function for testing out different values of 'epsilon' in the metropolis
   algorithm, and showing the percentage success rate of update attempts. */

#include"main.h"

config ensemble[Ncfg];

int main() {

  printf("Ncfg = %d\t L = %d\t T = %d\n",Ncfg,L,T);

  double epsilon_t;

  for ( epsilon_t=0.3; epsilon_t<=0.7; epsilon_t+=0.01 ) {
    Tune_ensemble(epsilon_t);
  }

  return 0;
}
