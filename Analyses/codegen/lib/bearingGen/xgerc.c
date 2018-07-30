/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: xgerc.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "xgerc.h"

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                double alpha1
 *                int ix0
 *                const double y[2]
 *                double A[4096]
 * Return Type  : void
 */
void xgerc(int m, int n, double alpha1, int ix0, const double y[2], double A
           [4096])
{
  int jA;
  int jy;
  int ix;
  double temp;
  int i4;
  int ijA;
  if (!(alpha1 == 0.0)) {
    jA = 2048;
    jy = 0;
    ix = 1;
    while (ix <= n) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        i4 = m + jA;
        for (ijA = jA; ijA < i4; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 2048;
      ix = 2;
    }
  }
}

/*
 * File trailer for xgerc.c
 *
 * [EOF]
 */
