/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: bearingGen_types.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

#ifndef BEARINGGEN_TYPES_H
#define BEARINGGEN_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_2048
#define struct_emxArray_real_T_2048

struct emxArray_real_T_2048
{
  double data[2048];
  int size[1];
};

#endif                                 /*struct_emxArray_real_T_2048*/

#ifndef typedef_emxArray_real_T_2048
#define typedef_emxArray_real_T_2048

typedef struct emxArray_real_T_2048 emxArray_real_T_2048;

#endif                                 /*typedef_emxArray_real_T_2048*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  double avg;
  double min;
  double max;
  double val[5];
  double loc[5];
  double status[5];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef struct_sW2vlGsZOKsyOk6g0sKKq0_tag
#define struct_sW2vlGsZOKsyOk6g0sKKq0_tag

struct sW2vlGsZOKsyOk6g0sKKq0_tag
{
  struct1_T pks;
  double freqs[5];
  emxArray_real_T_2048 spec;
  emxArray_real_T_2048 freq;
};

#endif                                 /*struct_sW2vlGsZOKsyOk6g0sKKq0_tag*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct sW2vlGsZOKsyOk6g0sKKq0_tag struct0_T;

#endif                                 /*typedef_struct0_T*/
#endif

/*
 * File trailer for bearingGen_types.h
 *
 * [EOF]
 */
