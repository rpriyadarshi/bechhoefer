/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: exp.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "exp.h"

/* Function Definitions */

/*
 * Arguments    : creal_T x[146484]
 * Return Type  : void
 */
void b_exp(creal_T x[146484])
{
  int k;
  double x_re;
  double r;
  for (k = 0; k < 146484; k++) {
    if (x[k].im == 0.0) {
      x_re = exp(x[k].re);
      r = 0.0;
    } else if (rtIsInf(x[k].im) && rtIsInf(x[k].re) && (x[k].re < 0.0)) {
      x_re = 0.0;
      r = 0.0;
    } else {
      r = exp(x[k].re / 2.0);
      x_re = r * (r * cos(x[k].im));
      r *= r * sin(x[k].im);
    }

    x[k].re = x_re;
    x[k].im = r;
  }
}

/*
 * File trailer for exp.c
 *
 * [EOF]
 */
