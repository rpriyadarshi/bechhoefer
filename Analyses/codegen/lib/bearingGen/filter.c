/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: filter.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "filter.h"

/* Function Definitions */

/*
 * Arguments    : const double b[129]
 *                const creal_T x[146484]
 *                creal_T y[146484]
 * Return Type  : void
 */
void filter(const double b[129], const creal_T x[146484], creal_T y[146484])
{
  int i;
  int j;
  for (i = 0; i < 146484; i++) {
    y[i].re = 0.0;
    y[i].im = 0.0;
  }

  for (i = 0; i < 129; i++) {
    for (j = i; j + 1 < 146485; j++) {
      y[j].re += b[i] * x[j - i].re;
      y[j].im += b[i] * x[j - i].im;
    }
  }
}

/*
 * File trailer for filter.c
 *
 * [EOF]
 */
