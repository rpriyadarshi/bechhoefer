/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: abs.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "abs.h"
#include "bearingGen_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T x[12197]
 *                double y[12197]
 * Return Type  : void
 */
void b_abs(const creal_T x[12197], double y[12197])
{
  int k;
  for (k = 0; k < 12197; k++) {
    y[k] = rt_hypotd_snf(x[k].re, x[k].im);
  }
}

/*
 * Arguments    : const creal_T x[2048]
 *                double y[2048]
 * Return Type  : void
 */
void c_abs(const creal_T x[2048], double y[2048])
{
  int k;
  for (k = 0; k < 2048; k++) {
    y[k] = rt_hypotd_snf(x[k].re, x[k].im);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
