# Generated with SMOP  0.41-beta
from smop.libsmop import *
from .niceBearing import *
from .calcFaultFreq import *
# ../Analyses/bearingCalc.m

    
@function
def bearingCalc(data=None,*args,**kwargs):
    varargin = bearingCalc.varargin
    nargin = bearingCalc.nargin

    #BEARINGCALC Bearing fault calculator
#   Detailed explanation goes here
    if (numel(data)):
        info=niceBearing()
# ../Analyses/bearingCalc.m:5
        fault=calcFaultFreq(info,data.bearing)
# ../Analyses/bearingCalc.m:6
    
    return fault
    
if __name__ == '__main__':
    pass
