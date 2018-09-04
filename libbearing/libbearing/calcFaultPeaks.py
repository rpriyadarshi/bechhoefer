# Generated with SMOP  0.41-beta
from smop.libsmop import *
# ../Analyses/calcFaultPeaks.m

    
@function
def calcFaultPeaks(info=None,fault=None,*args,**kwargs):
    varargin = calcFaultPeaks.varargin
    nargin = calcFaultPeaks.nargin

    #CALCFAULTPEAKS Summary of this function goes here
#   Detailed explanation goes here
    pks=struct('avg',0,'min',0,'max',0,'val',zeros(5,1),'loc',zeros(5,1),'status',zeros(5,1))
# ../Analyses/calcFaultPeaks.m:4
    val,loc=findpeaks(fault.spec,fault.freq,nargout=2)
# ../Analyses/calcFaultPeaks.m:5
    pks.avg = copy(mean(val))
# ../Analyses/calcFaultPeaks.m:6
    pks.min = copy(min(val))
# ../Analyses/calcFaultPeaks.m:7
    pks.max = copy(max(val))
# ../Analyses/calcFaultPeaks.m:8
    
    #pks.loc = [];
    #pks.status = zeros(5, 1); #[cage, ball, outer, inner, shaft];
    for i in arange(1,4).reshape(-1):
        lohi=val > logical_and(dot(pks.max,info.thr),loc) > logical_and(dot(fault.freqs(i),info.min),loc) < dot(fault.freqs(i),info.max)
# ../Analyses/calcFaultPeaks.m:14
        tmp_val=val(lohi)
# ../Analyses/calcFaultPeaks.m:15
        tmp_loc=loc(lohi)
# ../Analyses/calcFaultPeaks.m:16
        for j in arange(1,numel(tmp_loc)).reshape(-1):
            pks.val[i]=tmp_val(j)
# ../Analyses/calcFaultPeaks.m:18
            pks.loc[i]=tmp_loc(j)
# ../Analyses/calcFaultPeaks.m:19
        if (numel(tmp_val)):
            pks.status[i]=i
# ../Analyses/calcFaultPeaks.m:22
    
    return pks
    
if __name__ == '__main__':
    pass
    