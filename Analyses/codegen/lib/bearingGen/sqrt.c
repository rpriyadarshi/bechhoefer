/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: sqrt.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "sqrt.h"

/* Function Definitions */

/*
 * Arguments    : double *x
 * Return Type  : void
 */
void b_sqrt(double *x)
{
  *x = sqrt(*x);
}

/*
 * Arguments    : double x[1024]
 * Return Type  : void
 */
void c_sqrt(double x[1024])
{
  int k;
  for (k = 0; k < 1024; k++) {
    x[k] = sqrt(x[k]);
  }
}

/*
 * Arguments    : double x[2048]
 * Return Type  : void
 */
void d_sqrt(double x[2048])
{
  int k;
  for (k = 0; k < 2048; k++) {
    x[k] = sqrt(x[k]);
  }
}

/*
 * File trailer for sqrt.c
 *
 * [EOF]
 */
