/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: findpeaks.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "findpeaks.h"
#include "eml_setop.h"

/* Function Declarations */
static void c_findPeaksSeparatedByMoreThanM(const int iPk_size[1], int idx_data[],
  int idx_size[1]);
static void getAllPeaksCodegen(const double y_data[], const int y_size[1], int
  iPk_data[], int iPk_size[1], int iInf_data[], int iInf_size[1], int
  iInflect_data[], int iInflect_size[1]);
static void keepAtMostNpPeaks(int idx_data[], int idx_size[1], double Np);
static void parse_inputs(const double Yin_data[], const int Yin_size[1], const
  double varargin_1_data[], const int varargin_1_size[1], double y_data[], int
  y_size[1], double x_data[], int x_size[1], double *NpOut);
static void removeSmallPeaks(const double y_data[], const int iFinite_data[],
  const int iFinite_size[1], int iPk_data[], int iPk_size[1]);

/* Function Definitions */

/*
 * Arguments    : const int iPk_size[1]
 *                int idx_data[]
 *                int idx_size[1]
 * Return Type  : void
 */
static void c_findPeaksSeparatedByMoreThanM(const int iPk_size[1], int idx_data[],
  int idx_size[1])
{
  int n;
  int y_data[4096];
  int yk;
  int k;
  if (iPk_size[0] < 1) {
    n = 0;
  } else {
    n = iPk_size[0];
  }

  if (n > 0) {
    y_data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }

  idx_size[0] = n;
  if (0 <= n - 1) {
    memcpy(&idx_data[0], &y_data[0], (unsigned int)(n * (int)sizeof(int)));
  }
}

/*
 * Arguments    : const double y_data[]
 *                const int y_size[1]
 *                int iPk_data[]
 *                int iPk_size[1]
 *                int iInf_data[]
 *                int iInf_size[1]
 *                int iInflect_data[]
 *                int iInflect_size[1]
 * Return Type  : void
 */
static void getAllPeaksCodegen(const double y_data[], const int y_size[1], int
  iPk_data[], int iPk_size[1], int iInf_data[], int iInf_size[1], int
  iInflect_data[], int iInflect_size[1])
{
  int nPk;
  int nInf;
  int nInflect;
  char dir;
  int kfirst;
  double ykfirst;
  boolean_T isinfykfirst;
  int k;
  double yk;
  boolean_T isinfyk;
  char previousdir;
  short b_iPk_data[2048];
  unsigned int b_iInflect_data[2048];
  nPk = 0;
  nInf = 0;
  nInflect = -1;
  dir = 'n';
  kfirst = 0;
  ykfirst = rtInf;
  isinfykfirst = true;
  for (k = 0; k < y_size[0]; k++) {
    yk = y_data[k];
    if (rtIsNaN(y_data[k])) {
      yk = rtInf;
      isinfyk = true;
    } else if (rtIsInf(y_data[k]) && (y_data[k] > 0.0)) {
      isinfyk = true;
      nInf++;
      iInf_data[nInf - 1] = k + 1;
    } else {
      isinfyk = false;
    }

    if (yk != ykfirst) {
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
        if (kfirst >= 1) {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
        }
      } else if (yk < ykfirst) {
        dir = 'd';
        if ('d' != previousdir) {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
          if (previousdir == 'i') {
            nPk++;
            iPk_data[nPk - 1] = kfirst;
          }
        }
      } else {
        dir = 'i';
        if ('i' != previousdir) {
          nInflect++;
          iInflect_data[nInflect] = kfirst;
        }
      }

      ykfirst = yk;
      kfirst = k + 1;
      isinfykfirst = isinfyk;
    }
  }

  if ((!isinfykfirst) && ((nInflect + 1 == 0) || (iInflect_data[nInflect] <
        y_size[0]))) {
    nInflect++;
    iInflect_data[nInflect] = y_size[0];
  }

  if (1 > nPk) {
    nPk = 0;
  }

  kfirst = (short)y_size[0];
  for (k = 0; k < kfirst; k++) {
    b_iPk_data[k] = (short)iPk_data[k];
  }

  iPk_size[0] = nPk;
  for (k = 0; k < nPk; k++) {
    iPk_data[k] = b_iPk_data[k];
  }

  if (1 > nInf) {
    nPk = 0;
  } else {
    nPk = nInf;
  }

  kfirst = (short)y_size[0];
  for (k = 0; k < kfirst; k++) {
    b_iPk_data[k] = (short)iInf_data[k];
  }

  iInf_size[0] = nPk;
  for (k = 0; k < nPk; k++) {
    iInf_data[k] = b_iPk_data[k];
  }

  if (1 > nInflect + 1) {
    nPk = -1;
  } else {
    nPk = nInflect;
  }

  kfirst = (short)y_size[0];
  for (k = 0; k < kfirst; k++) {
    b_iInflect_data[k] = (unsigned int)iInflect_data[k];
  }

  iInflect_size[0] = nPk + 1;
  for (k = 0; k <= nPk; k++) {
    iInflect_data[k] = (int)b_iInflect_data[k];
  }
}

/*
 * Arguments    : int idx_data[]
 *                int idx_size[1]
 *                double Np
 * Return Type  : void
 */
static void keepAtMostNpPeaks(int idx_data[], int idx_size[1], double Np)
{
  int loop_ub;
  int b_idx_data[4096];
  if (idx_size[0] > Np) {
    loop_ub = (int)Np;
    if (0 <= loop_ub - 1) {
      memcpy(&b_idx_data[0], &idx_data[0], (unsigned int)(loop_ub * (int)sizeof
              (int)));
    }

    idx_size[0] = (int)Np;
    loop_ub = (int)Np;
    if (0 <= loop_ub - 1) {
      memcpy(&idx_data[0], &b_idx_data[0], (unsigned int)(loop_ub * (int)sizeof
              (int)));
    }
  }
}

/*
 * Arguments    : const double Yin_data[]
 *                const int Yin_size[1]
 *                const double varargin_1_data[]
 *                const int varargin_1_size[1]
 *                double y_data[]
 *                int y_size[1]
 *                double x_data[]
 *                int x_size[1]
 *                double *NpOut
 * Return Type  : void
 */
static void parse_inputs(const double Yin_data[], const int Yin_size[1], const
  double varargin_1_data[], const int varargin_1_size[1], double y_data[], int
  y_size[1], double x_data[], int x_size[1], double *NpOut)
{
  int loop_ub;
  y_size[0] = Yin_size[0];
  loop_ub = Yin_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&y_data[0], &Yin_data[0], (unsigned int)(loop_ub * (int)sizeof(double)));
  }

  x_size[0] = varargin_1_size[0];
  loop_ub = varargin_1_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&x_data[0], &varargin_1_data[0], (unsigned int)(loop_ub * (int)sizeof
            (double)));
  }

  *NpOut = Yin_size[0];
}

/*
 * Arguments    : const double y_data[]
 *                const int iFinite_data[]
 *                const int iFinite_size[1]
 *                int iPk_data[]
 *                int iPk_size[1]
 * Return Type  : void
 */
static void removeSmallPeaks(const double y_data[], const int iFinite_data[],
  const int iFinite_size[1], int iPk_data[], int iPk_size[1])
{
  int nPk;
  int k;
  double b_y_data;
  int b_iPk_data[2048];
  nPk = 0;
  for (k = 0; k < iFinite_size[0]; k++) {
    if (y_data[iFinite_data[k] - 1] > rtMinusInf) {
      if ((y_data[iFinite_data[k] - 2] > y_data[iFinite_data[k]]) || rtIsNaN
          (y_data[iFinite_data[k]])) {
        b_y_data = y_data[iFinite_data[k] - 2];
      } else {
        b_y_data = y_data[iFinite_data[k]];
      }

      if (y_data[iFinite_data[k] - 1] - b_y_data >= 0.0) {
        nPk++;
        iPk_data[nPk - 1] = iFinite_data[k];
      }
    }
  }

  if (1 > nPk) {
    nPk = 0;
  }

  if (0 <= nPk - 1) {
    memcpy(&b_iPk_data[0], &iPk_data[0], (unsigned int)(nPk * (int)sizeof(int)));
  }

  iPk_size[0] = nPk;
  if (0 <= nPk - 1) {
    memcpy(&iPk_data[0], &b_iPk_data[0], (unsigned int)(nPk * (int)sizeof(int)));
  }
}

/*
 * Arguments    : const double Yin_data[]
 *                const int Yin_size[1]
 *                const double varargin_1_data[]
 *                const int varargin_1_size[1]
 *                double Ypk_data[]
 *                int Ypk_size[1]
 *                double Xpk_data[]
 *                int Xpk_size[1]
 * Return Type  : void
 */
void findpeaks(const double Yin_data[], const int Yin_size[1], const double
               varargin_1_data[], const int varargin_1_size[1], double Ypk_data[],
               int Ypk_size[1], double Xpk_data[], int Xpk_size[1])
{
  double y_data[2048];
  int y_size[1];
  double x_data[2048];
  int x_size[1];
  double maxN;
  int iFinite_data[2048];
  int iInfinite_data[2048];
  int iInfinite_size[1];
  int iInflect_data[2048];
  int iInflect_size[1];
  int iPk_size[1];
  int loop_ub;
  int iPk_data[4096];
  int c_data[4096];
  int idx_data[4096];
  int i1;
  parse_inputs(Yin_data, Yin_size, varargin_1_data, varargin_1_size, y_data,
               y_size, x_data, x_size, &maxN);
  getAllPeaksCodegen(y_data, y_size, iFinite_data, x_size, iInfinite_data,
                     iInfinite_size, iInflect_data, iInflect_size);
  removeSmallPeaks(y_data, iFinite_data, x_size, iInflect_data, iInflect_size);
  iPk_size[0] = iInflect_size[0];
  loop_ub = iInflect_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&iPk_data[0], &iInflect_data[0], (unsigned int)(loop_ub * (int)sizeof
            (int)));
  }

  do_vectors(iPk_data, iPk_size, iInfinite_data, iInfinite_size, c_data, y_size,
             iInflect_data, iInflect_size, iFinite_data, x_size);
  c_findPeaksSeparatedByMoreThanM(y_size, idx_data, x_size);
  keepAtMostNpPeaks(idx_data, x_size, maxN);
  loop_ub = x_size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    iPk_data[i1] = c_data[idx_data[i1] - 1];
  }

  Ypk_size[0] = x_size[0];
  loop_ub = x_size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    Ypk_data[i1] = y_data[iPk_data[i1] - 1];
  }

  Xpk_size[0] = x_size[0];
  loop_ub = x_size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    Xpk_data[i1] = x_data[iPk_data[i1] - 1];
  }
}

/*
 * File trailer for findpeaks.c
 *
 * [EOF]
 */
