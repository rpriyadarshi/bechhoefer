/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: bearingGen.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "calcFaultFreq.h"
#include <stdio.h>

/* Function Definitions */

/*
 * BEARINGGEN Bearing fault calculator
 *    Detailed explanation goes here
 * Arguments    : struct0_T *fault
 * Return Type  : void
 */
void bearingGen(struct0_T *fault)
{
  calcFaultFreq(&fault->pks.avg, &fault->pks.min, &fault->pks.max,
                fault->pks.val, fault->pks.loc, fault->pks.status, fault->freqs,
                fault->spec.data, fault->spec.size, fault->freq.data,
                fault->freq.size);

  /* PRINTRESULTS Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* pks = struct('avg', 0, 'min', 0, 'max', 0, 'val', zeros(5, 1), 'loc', zeros(5, 1), 'status', zeros(5, 1)); */
  /* [cage, ball, outer, inner, shaft]; */
  if (fault->pks.val[2] != 0.0) {
    printf("ERROR: Outer race condition detected");
    fflush(stdout);
  } else {
    if (fault->pks.val[3] != 0.0) {
      printf("ERROR: Inner race condition detected");
      fflush(stdout);
    }
  }

  /* plotFaultFreq(fault); */
  /*  codegen 'bearingGen' */
}

/*
 * File trailer for bearingGen.c
 *
 * [EOF]
 */
