/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: qrsolve.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "qrsolve.h"

/* Function Definitions */

/*
 * Arguments    : const double A[4096]
 * Return Type  : int
 */
int rankFromQR(const double A[4096])
{
  int r;
  double tol;
  r = 0;
  tol = 2048.0 * fabs(A[0]) * 2.2204460492503131E-16;
  while ((r < 2) && (!(fabs(A[r + (r << 11)]) <= tol))) {
    r++;
  }

  return r;
}

/*
 * File trailer for qrsolve.c
 *
 * [EOF]
 */
