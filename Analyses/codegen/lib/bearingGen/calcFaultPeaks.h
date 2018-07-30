/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: calcFaultPeaks.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

#ifndef CALCFAULTPEAKS_H
#define CALCFAULTPEAKS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "bearingGen_types.h"

/* Function Declarations */
extern void calcFaultPeaks(const double fault_freqs[5], const double
  fault_spec_data[], const int fault_spec_size[1], const double fault_freq_data[],
  const int fault_freq_size[1], double *pks_avg, double *pks_min, double
  *pks_max, double pks_val[5], double pks_loc[5], double pks_status[5]);

#endif

/*
 * File trailer for calcFaultPeaks.h
 *
 * [EOF]
 */
