/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: mldivide.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "mldivide.h"
#include "qrsolve.h"
#include "xgeqp3.h"

/* Function Definitions */

/*
 * Arguments    : const double A[4096]
 *                const double B[2048]
 *                double Y[2]
 * Return Type  : void
 */
void mldivide(const double A[4096], const double B[2048], double Y[2])
{
  double b_A[4096];
  double tau[2];
  int jpvt[2];
  int rankA;
  double b_B[2048];
  int j;
  int i;
  double wj;
  memcpy(&b_A[0], &A[0], sizeof(double) << 12);
  xgeqp3(b_A, tau, jpvt);
  rankA = rankFromQR(b_A);
  memcpy(&b_B[0], &B[0], sizeof(double) << 11);
  for (j = 0; j < 2; j++) {
    Y[j] = 0.0;
    if (tau[j] != 0.0) {
      wj = b_B[j];
      for (i = j + 1; i + 1 < 2049; i++) {
        wj += b_A[i + (j << 11)] * b_B[i];
      }

      wj *= tau[j];
      if (wj != 0.0) {
        b_B[j] -= wj;
        for (i = j + 1; i + 1 < 2049; i++) {
          b_B[i] -= b_A[i + (j << 11)] * wj;
        }
      }
    }
  }

  for (i = 0; i < rankA; i++) {
    Y[jpvt[i] - 1] = b_B[i];
  }

  for (j = rankA - 1; j + 1 > 0; j--) {
    Y[jpvt[j] - 1] /= b_A[j + (j << 11)];
    i = 1;
    while (i <= j) {
      Y[jpvt[0] - 1] -= Y[jpvt[j] - 1] * b_A[j << 11];
      i = 2;
    }
  }
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
