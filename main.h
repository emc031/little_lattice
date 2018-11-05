
#include<stdio.h>
#include<complex.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define PI 3.14159265359

#define L 6 //spacial extent of lattice
#define T 6 //temporal extent of lattice
#define beta 0.1 //coupling constant
#define Ncfg 2000 //number of configurations in ensemble 
#define epsilon 0.51 //max random phase added to links per itteration in metropolis (in units of 2pi)

typedef struct conf {
  complex double t[T][L];
  complex double x[T][L];
} config; //single gauge field configuration

#include"utilities.h"
#include"operators.h"
#include"ensemble.h"
#include"correlations.h"
