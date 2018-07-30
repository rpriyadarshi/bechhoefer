/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: detrend.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "detrend.h"
#include "mldivide.h"

/* Function Definitions */

/*
 * Arguments    : double x[2048]
 * Return Type  : void
 */
void detrend(double x[2048])
{
  int i;
  double a[4096];
  double dv6[2];
  double d0;
  int i2;
  for (i = 0; i < 2048; i++) {
    a[i] = ((double)i + 1.0) / 2048.0;
    a[2048 + i] = 1.0;
  }

  mldivide(a, x, dv6);
  for (i = 0; i < 2048; i++) {
    d0 = 0.0;
    for (i2 = 0; i2 < 2; i2++) {
      d0 += a[i + (i2 << 11)] * dv6[i2];
    }

    x[i] -= d0;
  }
}

/*
 * File trailer for detrend.c
 *
 * [EOF]
 */
