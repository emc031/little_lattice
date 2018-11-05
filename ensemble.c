
#include"main.h"

/*generates ensemble of configs using the metropolis algorithm
(as in detailed lattice qcd for novices)*/
void Generate_ensemble( config* ensemble  ) {

  config U = random_config();

  int i, nt,nx;
  config U_candidate;

  for ( i=0; i<Ncfg; i++ ) {

    for ( nt=0; nt<=(T-1); nt++ ) {
      for ( nx=0; nx<=(L-1); nx++ ) {
      
	U_candidate = U;

	/* give t- link new random phase */
	U_candidate.t[nt][nx] = U_candidate.t[nt][nx]*expi(random_angle()*epsilon);

	/*if action is smaller, or if 
	  exp(-difference in S) > rand(0,1), keep change*/
	if ( S(U_candidate) < S(U) ||
	     exp(S(U)-S(U_candidate)) > random_angle()/(2*PI) ) {
	       U = U_candidate;
	     }

	/* give x- link new random phase */
	U_candidate.x[nt][nx] = U_candidate.x[nt][nx]*expi(random_angle()*epsilon);

	/*if action is smaller, or if 
	  exp(-difference in S) > rand(0,1), keep change*/
	if ( S(U_candidate) < S(U) ||
	     exp(S(U)-S(U_candidate)) > random_angle()/(2*PI) ) {
	       U = U_candidate;
	     }
      }
    }
    /* save current U to the ensemble */
    ensemble[i] = U;
  }

}


/*generates ensemble of configs using the metropolis algorithm,
and reports back the proportion of 'successes' of new
candidate configurations. */
void Tune_ensemble(double epsilon_t) {

  config U = random_config();

  int i, nt,nx;
  config U_candidate;

  int change_rate;
  double change_ratio;
  double accu_change_ratio = 0;

  for ( i=0; i<=Ncfg; i++ ) {

    change_rate = 0;
    for ( nt=0; nt<=(T-1); nt++ ) {
      for ( nx=0; nx<=(L-1); nx++ ) {
      
	U_candidate = U;

	/* give link new random phase */
	U_candidate.t[nt][nx] = U_candidate.t[nt][nx]*expi(random_angle()*epsilon_t);

	/*if action is smaller, or if 
	  exp(-difference in S) > rand(0,1), keep change*/
	if ( S(U_candidate) < S(U) ||
	     exp(S(U)-S(U_candidate)) > random_angle()/(2*PI) ) {
	       U = U_candidate;
	       change_rate+=1;
	     }

	U_candidate.x[nt][nx] = U_candidate.x[nt][nx]*expi(random_angle()*epsilon_t);


	/*if action is smaller, or if 
	  exp(-difference in S) > rand(0,1), keep change*/
	if ( S(U_candidate) < S(U) ||
	     exp(S(U)-S(U_candidate)) > random_angle()/(2*PI) ) {
	       U = U_candidate;
	       change_rate+=1;
	     }

      }
    }
    change_ratio=(double)change_rate/(double)(2*L*T);
    accu_change_ratio+= change_ratio;
  }
  double average_change_ratio = accu_change_ratio/(double)Ncfg;
  printf("For epsilon = %.2f: ",epsilon_t);
  printf("%.0f%% of links changed per sweep\n",average_change_ratio*100);

}
