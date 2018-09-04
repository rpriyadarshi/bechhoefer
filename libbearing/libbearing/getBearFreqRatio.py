# Generated with SMOP  0.41-beta
from smop.libsmop import *
import math
# ../Analyses/getBearFreqRatio.m

    
@function
def getBearFreqRatio(rd=None, pd=None, ca=None, ne=None, type_=None, side=None, *args, **kwargs):
    varargin = getBearFreqRatio.varargin
    nargin = getBearFreqRatio.nargin

    #GETBEARFREQRATIO Summary of this function goes here
#   Cage passing frequency:         f/2  (1 - (d/e) cos (?) )
#	Inner race passing frequency	bf/2 (1 + (d/e) cos (?) )
#   Outer race passing frequency	bf/2 (1 - (d/e) cos (?) )
#   Ball passing frequency          ef/d (1 - (d/e)2 cos2(?) )
#Where 
#   f is the driving frequency 
#   b is the number of rolling elements
#   d is the ball bearing diameter 
#   e is the bearing pitch diameter and
#   ? is the bearing contact angle.
    
    #Get the bearing Freq. ratio
#   rd:     roller diameter
#   pd:     pitch diameter
#   ca:     contact angle in degrees
#   ne:     number of elements
#   type    enum[cage, roller, outer race, inner race]
#   side:   inner or outer race fixed.  inner = 1, outer = 2;
#Eric Bechhoefer, April 10, 2009 for PHM Conference
#Ref: Timken Bearings Catalog 2008
    rdpd=rd / pd
# ../Analyses/getBearFreqRatio.m:23
    cs=math.cos(dot(ca, math.pi) / 180)
# ../Analyses/getBearFreqRatio.m:24
    pdrd=1 / rdpd
# ../Analyses/getBearFreqRatio.m:25
    if type_ == 1:
        if side == 1:
            d=dot(0.5,(1 - dot(rdpd,cs)))
# ../Analyses/getBearFreqRatio.m:28
        else:
            d=dot(0.5,(1 + dot(rdpd,cs)))
# ../Analyses/getBearFreqRatio.m:30
    else:
        if type_ == 2:
            d=dot((1 - (dot(rdpd,cs)) ** 2),pdrd)
# ../Analyses/getBearFreqRatio.m:33
        else:
            if type_ == 3:
                d=dot(dot(0.5,(1 - dot(rdpd,cs))),ne)
# ../Analyses/getBearFreqRatio.m:35
            else:
                d=dot(dot(0.5,(1 + dot(rdpd,cs))),ne)
# ../Analyses/getBearFreqRatio.m:37
    
    return d
    
if __name__ == '__main__':
    pass
    