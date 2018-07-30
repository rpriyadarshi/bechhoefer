/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: mean.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "mean.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[1]
 * Return Type  : double
 */
double mean(const double x_data[], const int x_size[1])
{
  double y;
  int k;
  if (x_size[0] == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_size[0]; k++) {
      y += x_data[k - 1];
    }
  }

  y /= (double)x_size[0];
  return y;
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
