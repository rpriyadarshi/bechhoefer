/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: _coder_bearingGen_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

#ifndef _CODER_BEARINGGEN_API_H
#define _CODER_BEARINGGEN_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_bearingGen_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_2048
#define struct_emxArray_real_T_2048

struct emxArray_real_T_2048
{
  real_T data[2048];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_2048*/

#ifndef typedef_emxArray_real_T_2048
#define typedef_emxArray_real_T_2048

typedef struct emxArray_real_T_2048 emxArray_real_T_2048;

#endif                                 /*typedef_emxArray_real_T_2048*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T avg;
  real_T min;
  real_T max;
  real_T val[5];
  real_T loc[5];
  real_T status[5];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef struct_sW2vlGsZOKsyOk6g0sKKq0_tag
#define struct_sW2vlGsZOKsyOk6g0sKKq0_tag

struct sW2vlGsZOKsyOk6g0sKKq0_tag
{
  struct1_T pks;
  real_T freqs[5];
  emxArray_real_T_2048 spec;
  emxArray_real_T_2048 freq;
};

#endif                                 /*struct_sW2vlGsZOKsyOk6g0sKKq0_tag*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct sW2vlGsZOKsyOk6g0sKKq0_tag struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void bearingGen(struct0_T *fault);
extern void bearingGen_api(int32_T nlhs, const mxArray *plhs[1]);
extern void bearingGen_atexit(void);
extern void bearingGen_initialize(void);
extern void bearingGen_terminate(void);
extern void bearingGen_xil_terminate(void);

#endif

/*
 * File trailer for _coder_bearingGen_api.h
 *
 * [EOF]
 */
