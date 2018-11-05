
/*contains functions of a configuration U*/

#include"main.h"

/*returns classical (wilson) Gauge action*/
double S( config U ) {

  double action = 0;

  double realplaquette;
  int nt, nx;
  for ( nt=0; nt<=(T-1); nt++ ) {
    for ( nx=0; nx<=(L-1); nx++ ) {
      realplaquette = creal( 
      U.x[nt][nx] * U.t[nt][(nx+1)%L] * conj( U.x[(nt+1)%T][nx] ) * conj( U.t[nt][nx] )
			     );

      action += 1 - realplaquette;
    }
  }
  action = action*beta;

  return action;
}

/*returns polyakov loop at spacial position nx_p */
double polyakov_loop( config U, int nx_p ) {
  complex loop = 1;
  int nt;
  for ( nt=0; nt<=(T-1); nt++ ) {
    loop = loop * U.t[nt][nx_p];
  }
  return creal(loop);
}



