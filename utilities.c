
/*misc functions*/

#include"main.h"

/*returns exp(i*phi)*/
complex expi(double phi) {
  return cos(phi)+I*sin(phi);
}

int seed = 1;
/*returns random double between 0 and 2pi*/
double random_angle() {
  if ( seed == 1 ) { seed = time(0); }
  srand(seed);
  int rand_int = rand();
  seed = rand_int;
  return ( (double)rand_int/(double)RAND_MAX )*2*PI;
}


/*generate random gauge configuration*/
config random_config() {

  config random_U;

  int nt, nx;
  for ( nt=0; nt<=(T-1); nt++ ) {
    for ( nx=0; nx<=(L-1); nx++ ) {
      random_U.t[nt][nx] = expi(random_angle());
      random_U.x[nt][nx] = expi(random_angle());
    }
  }

  return random_U;
}

/*takes in an array of monte carlo measurements by reference
  and transforms it into a bootstrap copy*/
void bootstrap_transform(double* o) {

  double new_o[Ncfg];
  int cfg, rcfg;

  if ( seed == 1 ) { seed = time(0); }

  for ( cfg=0; cfg<Ncfg; cfg++ ) {
    srand(seed);
    rcfg = rand();
    seed = rcfg;
    rcfg = rcfg % Ncfg;
    new_o[cfg] = o[rcfg];
  }

  for ( cfg=0; cfg<Ncfg; cfg++ ) {
    o[cfg] = new_o[cfg];
  }
}

/*prints configuration*/
void print_config(config U){
  int nt,nx;
  
  printf("U.x : \n");
  for ( nt=0; nt<=(T-1); nt++ ){
    for ( nx=0; nx<=(L-1); nx++ ){
      printf("[%d,%d] = %.2f+%.2fi\t",nt,nx,creal(U.x[nt][nx]),cimag(U.x[nt][nx]));
    }
    printf("\n");
  }

  printf("U.t : \n");
  for ( nt=0; nt<=(T-1); nt++ ){
    for ( nx=0; nx<=(L-1); nx++ ){
      printf("[%d,%d] = %.2f+%.2fi\t",nt,nx,creal(U.t[nt][nx]),cimag(U.t[nt][nx]));
    }
    printf("\n");
  }

}
