# Generated with SMOP  0.41-beta
from smop.libsmop import *
# ../Analyses/plotFaultFreq.m

    
@function
def plotFaultFreq(fault=None,*args,**kwargs):
    varargin = plotFaultFreq.varargin
    nargin = plotFaultFreq.nargin

    #PLOTFAULTFREQ Summary of this function goes here
#   Detailed explanation goes here
#   https://www.mathworks.com/help/releases/R2016b/matlab/creating_guis/graphics-support-in-app-designer.html
    
    plot(fault.freq,fault.spec)
    ax=concat([xlim,ylim])
# ../Analyses/plotFaultFreq.m:7
    
    hold('on')
    for i in arange(1,5).reshape(-1):
        f=fault.freqs(i)
# ../Analyses/plotFaultFreq.m:10
        plot(concat([f,f]),ax(arange(3,4)),'LineWidth',2)
    
    plot(fault.pks.loc,fault.pks.val,'o')
    hold('off')
    legend('env','cage','ball','outer','inner','1/rev')
    xlabel('Hz')
    ylabel('Gs')
    #axis([0 200 ax(3:4)])
    xlim(concat([0,200]))
    ylim(ax(arange(3,4)))
    return
    
if __name__ == '__main__':
    pass
    