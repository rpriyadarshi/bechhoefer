/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: _coder_bearingGen_api.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_bearingGen_api.h"
#include "_coder_bearingGen_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "bearingGen",                        /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const struct0_T *u);

/* Function Definitions */

/*
 * Arguments    : const struct0_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const struct0_T *u)
{
  const mxArray *y;
  static const char * sv0[4] = { "pks", "freqs", "spec", "freq" };

  const mxArray *b_y;
  static const char * sv1[6] = { "avg", "min", "max", "val", "loc", "status" };

  const mxArray *c_y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 5 };

  real_T *pData;
  int32_T i0;
  int32_T i;
  static const int32_T iv1[1] = { 5 };

  static const int32_T iv2[1] = { 5 };

  static const int32_T iv3[1] = { 5 };

  int32_T u_size[1];
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 4, sv0));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 6, sv1));
  c_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->pks.avg);
  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "avg", c_y, 0);
  c_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->pks.min);
  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "min", c_y, 1);
  c_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->pks.max);
  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "max", c_y, 2);
  c_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  for (i = 0; i < 5; i++) {
    pData[i0] = u->pks.val[i];
    i0++;
  }

  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "val", c_y, 3);
  c_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv1, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  for (i = 0; i < 5; i++) {
    pData[i0] = u->pks.loc[i];
    i0++;
  }

  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "loc", c_y, 4);
  c_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv2, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  for (i = 0; i < 5; i++) {
    pData[i0] = u->pks.status[i];
    i0++;
  }

  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "status", c_y, 5);
  emlrtSetFieldR2017b(y, 0, "pks", b_y, 0);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv3, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  for (i = 0; i < 5; i++) {
    pData[i0] = u->freqs[i];
    i0++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "freqs", b_y, 1);
  u_size[0] = u->spec.size[0];
  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, u_size, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  for (i = 0; i < u->spec.size[0]; i++) {
    pData[i0] = u->spec.data[i];
    i0++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "spec", b_y, 2);
  u_size[0] = u->freq.size[0];
  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, u_size, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  for (i = 0; i < u->freq.size[0]; i++) {
    pData[i0] = u->freq.data[i];
    i0++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "freq", b_y, 3);
  return y;
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void bearingGen_api(int32_T nlhs, const mxArray *plhs[1])
{
  struct0_T fault;
  (void)nlhs;

  /* Invoke the target function */
  bearingGen(&fault);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&fault);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void bearingGen_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  bearingGen_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void bearingGen_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void bearingGen_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_bearingGen_api.c
 *
 * [EOF]
 */
