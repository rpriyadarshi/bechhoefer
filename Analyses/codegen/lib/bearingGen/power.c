/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: power.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const double a[2048]
 *                double y[2048]
 * Return Type  : void
 */
void power(const double a[2048], double y[2048])
{
  int k;
  for (k = 0; k < 2048; k++) {
    y[k] = a[k] * a[k];
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
