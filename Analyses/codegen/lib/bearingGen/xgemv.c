/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: xgemv.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "xgemv.h"

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                const double A[4096]
 *                const double x[4096]
 *                int ix0
 *                double y[2]
 * Return Type  : void
 */
void xgemv(int m, int n, const double A[4096], const double x[4096], int ix0,
           double y[2])
{
  int ix;
  double c;
  int ia;
  if (n != 0) {
    y[0] = 0.0;
    ix = ix0;
    c = 0.0;
    for (ia = 2049; ia <= m + 2048; ia++) {
      c += A[ia - 1] * x[ix - 1];
      ix++;
    }

    y[0] += c;
  }
}

/*
 * File trailer for xgemv.c
 *
 * [EOF]
 */
