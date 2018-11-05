

#include"main.h"

/*returns the average (unnormalized) correlation between polyakov loops 
  evaluated on configurations in the ensemble with index separated by 'lag'*/
double correlation(config* ensemble, int lag) {

  int i;

  //compute average polyakov loop over ensemble
  double av_loop = 0;
  for ( i=0; i<Ncfg; i++ ) {
    av_loop = av_loop + polyakov_loop(ensemble[i],0);
  }
  av_loop = av_loop/Ncfg;

  //compute average correlation between loops
  double av_correlation = 0;
  for ( i=lag; i<Ncfg; i++ ) {
    av_correlation = av_correlation + 
      ( polyakov_loop(ensemble[i],0) - av_loop )*( polyakov_loop(ensemble[i-lag],0) - av_loop );
  }
  av_correlation = av_correlation/(Ncfg-lag);

  return fabs(av_correlation);
}
