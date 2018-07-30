/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: any.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "any.h"

/* Function Definitions */

/*
 * Arguments    : const boolean_T x[12197]
 * Return Type  : boolean_T
 */
boolean_T any(const boolean_T x[12197])
{
  boolean_T y;
  int k;
  boolean_T exitg1;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 12197)) {
    if (x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

/*
 * Arguments    : boolean_T x
 * Return Type  : boolean_T
 */
boolean_T b_any(boolean_T x)
{
  return x;
}

/*
 * File trailer for any.c
 *
 * [EOF]
 */
