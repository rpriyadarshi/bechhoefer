# Generated with SMOP  0.41-beta
from smop.libsmop import *
from .libbearing import *
# ../Analyses/niceBearing.m


def niceBearing(*args, **kwargs):
#    varargin = niceBearing.varargin
#    nargin = niceBearing.nargin

    #NICEBEARING Summary of this function goes here
#   rd:     roller diameter
#   pd:     pitch diameter
#   ca:     contact angle in degrees
#   ne:     number of elements
#   type    enum[cage, roller, outer race, inner race]
#   side:   inner or outer race fixed.  inner = 1, outer = 2;
#   Eric Bechhoefer, April 10, 2009 for PHM Conference
    info = Setup()

    info.rd = copy(0.235)
# ../Analyses/niceBearing.m:11
    info.ca = copy(0)
# ../Analyses/niceBearing.m:12
    info.ne = copy(8)
# ../Analyses/niceBearing.m:13
    info.pd = copy(1.245)
# ../Analyses/niceBearing.m:14
    info.side = copy(2)
# ../Analyses/niceBearing.m:16
    info.thr = copy(0.75)
# ../Analyses/niceBearing.m:18
    info.min = copy(0.95)
# ../Analyses/niceBearing.m:19
    info.max = copy(1.05)
# ../Analyses/niceBearing.m:20
    return info
    
if __name__ == '__main__':
    pass
