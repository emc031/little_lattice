
/* main function for testing the correlation time of configurations in the ensemble.
   This computes the function

   C(lag) = sum_t ( O(U(t)) - <O> )*( O(U(t-lag)) - <O> ) / C(0)

   Where U(t) is the t'th configuration generated in the ensemble, 
   and the operator O used in this case is a polyokov loop. */

#include"main.h"

config ensemble[Ncfg];

int bin=1; //bins C(lag)
int max_lag=100; //max lag to test

int main() {

  printf("Ncfg=%d, L = %d, T = %d\n", Ncfg, L, T );
  printf("Autocorrelations between polyakov loops on configurations\nspearated by \'lag\' in Monte Carlo time\n\n");

  Generate_ensemble( ensemble );

  //calculate correlation at 0 lag for normalization
  double N = correlation( ensemble, 0 );

  double c;
  int lag, ilag;
  for ( lag=0; lag<max_lag; lag=lag+bin ) {

    c = 0;
    for ( ilag=lag; ilag<lag+bin; ilag++ ) {
      c += correlation( ensemble, ilag );
    }
    c = c/(N*bin);

    printf("autocorrelation at lag~%d is %.3f\n", lag+bin/2, c );
  }

  return 0;
}
