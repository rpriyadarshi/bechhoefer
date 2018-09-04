# Generated with SMOP  0.41-beta
from smop.libsmop import *
from .libbearing import *
from .getBearFreqRatio import *
from .envelope1 import *
from .psde import *
from .calcFaultPeaks import *
# ../Analyses/calcFaultFreq.m

    
@function
def calcFaultFreq(info=None,bearing=None,*args,**kwargs):
    varargin = calcFaultFreq.varargin
    nargin = calcFaultFreq.nargin

    #CALCFAULTFREQ Summary of this function goes here
#   Detailed explanation goes here
#   sr      = Sample rate (samples/sec)
#   gs      = Vector of 'g' (accelerometer) data
#   load    = Load
#   rate    = Shaft rate

    fault = Fault()
    #fault.pks = copy(struct('avg',0,'min',0,'max',0,'val',zeros(5,1),'loc',zeros(5,1),'status',zeros(5,1)))
# ../Analyses/calcFaultFreq.m:9
    faultRates=ones(5,1)
# ../Analyses/calcFaultFreq.m:11
    
    for i in arange(1,4).reshape(-1):
        faultRates[i]=getBearFreqRatio(info.rd,info.pd,info.ca,info.ne,i,info.side)
# ../Analyses/calcFaultFreq.m:13
    
    fault.freqs = copy(dot(faultRates,bearing.rate))
# ../Analyses/calcFaultFreq.m:16
    
    bearing_sr=1 / bearing.sr
# ../Analyses/calcFaultFreq.m:19
    
    
    env,dty=envelope1(bearing.gs,bearing_sr,128,2000,4000,nargout=2)
# ../Analyses/calcFaultFreq.m:22
    fault.spec,fault.freq=psde(env,2048,1 / dty,1024,nargout=2)
# ../Analyses/calcFaultFreq.m:24
    fault.pks = copy(calcFaultPeaks(info,fault))
# ../Analyses/calcFaultFreq.m:26
    return fault
    
if __name__ == '__main__':
    pass
    