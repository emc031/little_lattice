
/* main function for calculating the amplitude of two polyokov loops of varying
   spacial separations on the lattice */

#include"main.h"

config ensemble[Ncfg];
int bootstraps=300;

int main() {

  Generate_ensemble( ensemble );

  int cfg,bs,dx;
  double av_cfg_loops[bootstraps];
  double av_bs_loops[L/2];
  double av_bs_loops2[L/2];
  double sdev_bs_loops[L/2];
  double loops[Ncfg];

  for ( dx=1; dx<=L/2; dx++ ) {

    //compute ensemble of double loops
    for ( cfg=0; cfg<Ncfg; cfg++ ) {
      loops[cfg] = creal( polyakov_loop(ensemble[cfg],0)*polyakov_loop(ensemble[cfg],dx) );
    }

    av_bs_loops[dx-1] = 0;
    av_bs_loops2[dx-1] = 0;

    for ( bs=0; bs<bootstraps; bs++ ) {

      //compute average double loop over current ensemble
      av_cfg_loops[bs] = 0;
      for ( cfg=0; cfg<Ncfg; cfg++ ) {
	av_cfg_loops[bs] += loops[cfg];
      }
      av_cfg_loops[bs] = av_cfg_loops[bs]/Ncfg;

      av_bs_loops[dx-1] += av_cfg_loops[bs];
      av_bs_loops2[dx-1] += av_cfg_loops[bs]*av_cfg_loops[bs];

      //itterate to next bootrap copy of ensemble
      bootstrap_transform(loops);
    }

    av_bs_loops[dx-1] = av_bs_loops[dx-1]/bootstraps;
    av_bs_loops2[dx-1] = av_bs_loops2[dx-1]/bootstraps;

    //compute standard deviation
    sdev_bs_loops[dx-1] = sqrt( av_bs_loops2[dx-1] - av_bs_loops[dx-1]*av_bs_loops[dx-1] );

    printf("|<P(0)P(%d)>| = %.4f +- %.4f\n", dx, fabs(av_bs_loops[dx-1]), fabs(sdev_bs_loops[dx-1]) );
  }

  return 0;
}
