/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: ixamax.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "ixamax.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const double x[2]
 *                int ix0
 * Return Type  : int
 */
int ixamax(int n, const double x[2], int ix0)
{
  int idxmax;
  idxmax = 1;
  if ((n > 1) && (fabs(x[1]) > fabs(x[ix0 - 1]))) {
    idxmax = 2;
  }

  return idxmax;
}

/*
 * File trailer for ixamax.c
 *
 * [EOF]
 */
