/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: eml_setop.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "eml_setop.h"

/* Function Definitions */

/*
 * Arguments    : const int a_data[]
 *                const int a_size[1]
 *                const int b_data[]
 *                const int b_size[1]
 *                int c_data[]
 *                int c_size[1]
 *                int ia_data[]
 *                int ia_size[1]
 *                int ib_data[]
 *                int ib_size[1]
 * Return Type  : void
 */
void do_vectors(const int a_data[], const int a_size[1], const int b_data[],
                const int b_size[1], int c_data[], int c_size[1], int ia_data[],
                int ia_size[1], int ib_data[], int ib_size[1])
{
  int na;
  int nb;
  int ncmax;
  int nc;
  int nia;
  int nib;
  int iafirst;
  int ialast;
  int ibfirst;
  int iblast;
  int b_ialast;
  int ak;
  int b_iblast;
  int bk;
  int b_ia_data[2048];
  int b_c_data[4096];
  short b_ib_data[2048];
  na = a_size[0];
  nb = b_size[0];
  ncmax = a_size[0] + b_size[0];
  c_size[0] = (short)ncmax;
  ia_size[0] = a_size[0];
  ib_size[0] = b_size[0];
  nc = -1;
  nia = -1;
  nib = 0;
  iafirst = 1;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= na) && (iblast <= nb)) {
    b_ialast = ialast;
    ak = a_data[ialast - 1];
    while ((b_ialast < a_size[0]) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }

    ialast = b_ialast;
    b_iblast = iblast;
    bk = b_data[iblast - 1];
    while ((b_iblast < b_size[0]) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast;
    if (ak == bk) {
      nc++;
      c_data[nc] = ak;
      nia++;
      ia_data[nia] = iafirst;
      ialast = b_ialast + 1;
      iafirst = b_ialast + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      nc++;
      nia++;
      c_data[nc] = ak;
      ia_data[nia] = iafirst;
      ialast = b_ialast + 1;
      iafirst = b_ialast + 1;
    } else {
      nc++;
      nib++;
      c_data[nc] = bk;
      ib_data[nib - 1] = ibfirst + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }

  while (ialast <= na) {
    b_ialast = ialast;
    while ((b_ialast < a_size[0]) && (a_data[b_ialast] == a_data[ialast - 1])) {
      b_ialast++;
    }

    nc++;
    nia++;
    c_data[nc] = a_data[ialast - 1];
    ia_data[nia] = ialast;
    ialast = b_ialast + 1;
  }

  while (iblast <= nb) {
    b_iblast = iblast;
    while ((b_iblast < b_size[0]) && (b_data[b_iblast] == b_data[iblast - 1])) {
      b_iblast++;
    }

    nc++;
    nib++;
    c_data[nc] = b_data[iblast - 1];
    ib_data[nib - 1] = iblast;
    iblast = b_iblast + 1;
  }

  if (a_size[0] > 0) {
    if (1 > nia + 1) {
      nia = -1;
    }

    if (0 <= nia) {
      memcpy(&b_ia_data[0], &ia_data[0], (unsigned int)((nia + 1) * (int)sizeof
              (int)));
    }

    ia_size[0] = nia + 1;
    nia++;
    if (0 <= nia - 1) {
      memcpy(&ia_data[0], &b_ia_data[0], (unsigned int)(nia * (int)sizeof(int)));
    }
  }

  if (b_size[0] > 0) {
    if (1 > nib) {
      nia = 0;
    } else {
      nia = nib;
    }

    na = b_size[0];
    for (nb = 0; nb < na; nb++) {
      b_ib_data[nb] = (short)ib_data[nb];
    }

    ib_size[0] = nia;
    for (nb = 0; nb < nia; nb++) {
      ib_data[nb] = b_ib_data[nb];
    }
  }

  if (ncmax > 0) {
    if (1 > nc + 1) {
      nia = -1;
    } else {
      nia = nc;
    }

    if (0 <= nia) {
      memcpy(&b_c_data[0], &c_data[0], (unsigned int)((nia + 1) * (int)sizeof
              (int)));
    }

    c_size[0] = nia + 1;
    nia++;
    if (0 <= nia - 1) {
      memcpy(&c_data[0], &b_c_data[0], (unsigned int)(nia * (int)sizeof(int)));
    }
  }
}

/*
 * File trailer for eml_setop.c
 *
 * [EOF]
 */
