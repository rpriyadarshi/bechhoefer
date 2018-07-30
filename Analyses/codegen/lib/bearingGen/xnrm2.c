/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: xnrm2.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "xnrm2.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const double x[4096]
 *                int ix0
 * Return Type  : double
 */
double b_xnrm2(int n, const double x[4096], int ix0)
{
  double y;
  double scale;
  int kend;
  int k;
  double absxk;
  double t;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/*
 * Arguments    : const double x[4096]
 *                int ix0
 * Return Type  : double
 */
double xnrm2(const double x[4096], int ix0)
{
  double y;
  double scale;
  int k;
  double absxk;
  double t;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = ix0; k <= ix0 + 2047; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/*
 * File trailer for xnrm2.c
 *
 * [EOF]
 */
