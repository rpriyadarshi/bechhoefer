/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: GetBearFreqRatio.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Jul-2018 17:50:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bearingGen.h"
#include "GetBearFreqRatio.h"

/* Function Definitions */

/*
 * GETBEARFREQRATIO Summary of this function goes here
 *    Cage passing frequency:         f/2  (1 - (d/e) cos (?) )
 *  Inner race passing frequency bf/2 (1 + (d/e) cos (?) )
 *    Outer race passing frequency bf/2 (1 - (d/e) cos (?) )
 *    Ball passing frequency          ef/d (1 - (d/e)2 cos2(?) )
 * Where
 *    f is the driving frequency
 *    b is the number of rolling elements
 *    d is the ball bearing diameter
 *    e is the bearing pitch diameter and
 *    ? is the bearing contact angle.
 * Arguments    : double type
 * Return Type  : double
 */
double GetBearFreqRatio(double type)
{
  double d;

  /* Get the bearing Freq. ratio */
  /*    rd:     roller diameter */
  /*    pd:     pitch diameter */
  /*    ca:     contact angle in degrees */
  /*    ne:     number of elements */
  /*    type    enum[cage, roller, outer race, inner race] */
  /*    side:   inner or outer race fixed.  inner = 1, outer = 2; */
  /* Eric Bechhoefer, April 10, 2009 for PHM Conference */
  /* Ref: Timken Bearings Catalog 2008 */
  if (type == 1.0) {
    /* cage freq ratio */
    d = 0.59437751004016059;
  } else if (type == 2.0) {
    /* roller freq ratio */
    d = 5.109117320345212;
  } else if (type == 3.0) {
    /* outer race freq ratio */
    d = 3.2449799196787152;
  } else {
    /* inner race freq  */
    d = 4.7550200803212848;
  }

  return d;
}

/*
 * File trailer for GetBearFreqRatio.c
 *
 * [EOF]
 */
