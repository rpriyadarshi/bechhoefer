/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: calcFaultPeaks.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "calcFaultPeaks.h"
#include "mean.h"
#include "findpeaks.h"

/* Function Definitions */

/*
 * CALCFAULTPEAKS Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double fault_freqs[5]
 *                const double fault_spec_data[]
 *                const int fault_spec_size[1]
 *                const double fault_freq_data[]
 *                const int fault_freq_size[1]
 *                double *pks_avg
 *                double *pks_min
 *                double *pks_max
 *                double pks_val[5]
 *                double pks_loc[5]
 *                double pks_status[5]
 * Return Type  : void
 */
void calcFaultPeaks(const double fault_freqs[5], const double fault_spec_data[],
                    const int fault_spec_size[1], const double fault_freq_data[],
                    const int fault_freq_size[1], double *pks_avg, double
                    *pks_min, double *pks_max, double pks_val[5], double
                    pks_loc[5], double pks_status[5])
{
  int i;
  static double val_data[4096];
  int val_size[1];
  static double loc_data[4096];
  int loc_size[1];
  int idx;
  int k;
  boolean_T exitg1;
  double maxval;
  int tmp_size_idx_0;
  int loop_ub;
  int b_loop_ub;
  int end;
  int b_end;
  double b_fault_freqs;
  boolean_T tmp_data[4096];
  boolean_T b_tmp_data[4096];
  int j;
  int c_end;
  int partialTrueCount;
  int c_tmp_data[4096];
  int d_tmp_data[4096];
  for (i = 0; i < 5; i++) {
    pks_val[i] = 0.0;
    pks_loc[i] = 0.0;
    pks_status[i] = 0.0;
  }

  findpeaks(fault_spec_data, fault_spec_size, fault_freq_data, fault_freq_size,
            val_data, val_size, loc_data, loc_size);
  *pks_avg = mean(val_data, val_size);
  if (val_size[0] <= 2) {
    if (val_size[0] == 1) {
      *pks_min = val_data[0];
    } else if ((val_data[0] > val_data[1]) || (rtIsNaN(val_data[0]) && (!rtIsNaN
                 (val_data[1])))) {
      *pks_min = val_data[1];
    } else {
      *pks_min = val_data[0];
    }

    if (val_size[0] == 1) {
      *pks_max = val_data[0];
    } else if ((val_data[0] < val_data[1]) || (rtIsNaN(val_data[0]) && (!rtIsNaN
                 (val_data[1])))) {
      *pks_max = val_data[1];
    } else {
      *pks_max = val_data[0];
    }
  } else {
    if (!rtIsNaN(val_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= val_size[0])) {
        if (!rtIsNaN(val_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      *pks_min = val_data[0];
    } else {
      *pks_min = val_data[idx - 1];
      while (idx + 1 <= val_size[0]) {
        if (*pks_min > val_data[idx]) {
          *pks_min = val_data[idx];
        }

        idx++;
      }
    }

    if (!rtIsNaN(val_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= val_size[0])) {
        if (!rtIsNaN(val_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      *pks_max = val_data[0];
    } else {
      *pks_max = val_data[idx - 1];
      while (idx + 1 <= val_size[0]) {
        if (*pks_max < val_data[idx]) {
          *pks_max = val_data[idx];
        }

        idx++;
      }
    }
  }

  /* pks.val = []; */
  /* pks.loc = []; */
  /* pks.status = zeros(5, 1); %[cage, ball, outer, inner, shaft]; */
  maxval = *pks_max * 0.75;
  tmp_size_idx_0 = val_size[0];
  loop_ub = val_size[0];
  b_loop_ub = loc_size[0];
  end = val_size[0];
  b_end = val_size[0];
  for (i = 0; i < 4; i++) {
    b_fault_freqs = fault_freqs[i] * 0.95;
    for (idx = 0; idx < loop_ub; idx++) {
      tmp_data[idx] = ((val_data[idx] > maxval) && (loc_data[idx] >
        b_fault_freqs));
    }

    b_fault_freqs = fault_freqs[i] * 1.05;
    for (idx = 0; idx < b_loop_ub; idx++) {
      b_tmp_data[idx] = (loc_data[idx] < b_fault_freqs);
    }

    idx = -1;
    for (k = 0; k < end; k++) {
      if (tmp_data[k] && b_tmp_data[k]) {
        idx++;
      }
    }

    for (j = 0; j <= idx; j++) {
      c_end = tmp_size_idx_0 - 1;
      partialTrueCount = 0;
      for (k = 0; k <= c_end; k++) {
        if (tmp_data[k] && b_tmp_data[k]) {
          c_tmp_data[partialTrueCount] = k + 1;
          partialTrueCount++;
        }
      }

      pks_val[i] = val_data[c_tmp_data[j] - 1];
      c_end = tmp_size_idx_0 - 1;
      partialTrueCount = 0;
      for (k = 0; k <= c_end; k++) {
        if (tmp_data[k] && b_tmp_data[k]) {
          d_tmp_data[partialTrueCount] = k + 1;
          partialTrueCount++;
        }
      }

      pks_loc[i] = loc_data[d_tmp_data[j] - 1];
    }

    idx = 0;
    for (k = 0; k < b_end; k++) {
      if (tmp_data[k] && b_tmp_data[k]) {
        idx++;
      }
    }

    if (idx != 0) {
      pks_status[i] = 1.0 + (double)i;
    }
  }
}

/*
 * File trailer for calcFaultPeaks.c
 *
 * [EOF]
 */
