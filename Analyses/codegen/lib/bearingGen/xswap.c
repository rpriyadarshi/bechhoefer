/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: xswap.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "xswap.h"

/* Function Definitions */

/*
 * Arguments    : double x[4096]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[4096], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 2048; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
