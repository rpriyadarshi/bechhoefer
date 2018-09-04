# Generated with SMOP  0.41-beta
from smop.libsmop import *
from .niceBearing import *
from .calcFaultFreq import *
from .printResults import *
# ../Analyses/bearingGen.m

    
@function
def bearingGen(*args,**kwargs):
    varargin = bearingGen.varargin
    nargin = bearingGen.nargin

    #BEARINGGEN Bearing fault calculator
#   Detailed explanation goes here
    data=coder.load('Data/InnerRaceFault_vload_1')
# ../Analyses/bearingGen.m:4
    info=niceBearing()
# ../Analyses/bearingGen.m:5
    fault=calcFaultFreq(info,data.bearing)
# ../Analyses/bearingGen.m:6
    printResults(fault)
    
    return fault
    
if __name__ == '__main__':
    pass
    
    # codegen 'bearingGen'
    