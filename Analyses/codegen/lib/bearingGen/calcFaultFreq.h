/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: calcFaultFreq.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

#ifndef CALCFAULTFREQ_H
#define CALCFAULTFREQ_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "bearingGen_types.h"

/* Function Declarations */
extern void calcFaultFreq(double *fault_pks_avg, double *fault_pks_min, double
  *fault_pks_max, double fault_pks_val[5], double fault_pks_loc[5], double
  fault_pks_status[5], double fault_freqs[5], double fault_spec_data[], int
  fault_spec_size[1], double fault_freq_data[], int fault_freq_size[1]);

#endif

/*
 * File trailer for calcFaultFreq.h
 *
 * [EOF]
 */
