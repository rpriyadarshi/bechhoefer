# Generated with SMOP  0.41-beta
from smop.libsmop import *
# ../Analyses/psde.m

    
@function
def psde(x=None,winln=None,Fs=None,noverlap=None,*args,**kwargs):
    varargin = psde.varargin
    nargin = psde.nargin

    #PSDE Summary of this function goes here
#   [Spec, freq] = psde(x, winln,Fs, noverlap);
#Energy power spectrual density
#using Welch's method using Hann window
#   x:          time domain data
#   windln:     window length, e.g. 2048,
#   Fs;         sampleing frequency
#   noverlap:   length of the overlp
    n=copy(winln)
# ../Analyses/psde.m:10
    m=n / 2
# ../Analyses/psde.m:11
    window=dot(0.5,(1 - cos(dot(dot(2,pi),(arange(1,m)).T) / (n + 1))))
# ../Analyses/psde.m:12
    
    window=concat([[window],[window(arange(end(),1,- 1))]])
# ../Analyses/psde.m:13
    window=ravel(window)
# ../Analyses/psde.m:14
    nfft=length(window)
# ../Analyses/psde.m:16
    n=length(x)
# ../Analyses/psde.m:18
    
    nwind=length(window)
# ../Analyses/psde.m:19
    
    if n < nwind:
        x[arange(n + 1,nwind)]=0
# ../Analyses/psde.m:21
        n=copy(nwind)
# ../Analyses/psde.m:22
    
    # Make sure x is a column vector; do this AFTER the zero-padding 
    # in case x is a scalar.
    x=ravel(x)
# ../Analyses/psde.m:26
    k=fix((n - noverlap) / (nwind - noverlap))
# ../Analyses/psde.m:28
    
    index=arange(1,nwind)
# ../Analyses/psde.m:29
    KMU=dot(k,sum(window) ** 2)
# ../Analyses/psde.m:31
    
    Spec=zeros(nfft,1)
# ../Analyses/psde.m:33
    for i in arange(1,k).reshape(-1):
        xw=multiply(window,detrend(x(index)))
# ../Analyses/psde.m:35
        index=index + (nwind - noverlap)
# ../Analyses/psde.m:36
        xx=fft(xw,nfft)
# ../Analyses/psde.m:37
        Xx=abs(xx) ** 2
# ../Analyses/psde.m:38
        Spec=Spec + Xx
# ../Analyses/psde.m:39
    
    # Select first half
    if logical_not(any(any(imag(x) != 0))):
        if rem(nfft,2):
            select=(arange(1,(nfft + 1) / 2)).T
# ../Analyses/psde.m:45
        else:
            select=(arange(1,nfft / 2)).T
# ../Analyses/psde.m:47
        Spec=Spec(select)
# ../Analyses/psde.m:49
        freq=dot((select - 1),Fs) / nfft
# ../Analyses/psde.m:50
        Spec=sqrt(dot(Spec,(4 / KMU)))
# ../Analyses/psde.m:51
    else:
        select=(arange(1,nfft)).T
# ../Analyses/psde.m:53
        freq=dot((select - 1),Fs) / nfft
# ../Analyses/psde.m:54
        Spec=sqrt(dot(Spec,(4 / KMU)))
# ../Analyses/psde.m:55
    
    return Spec,freq
    
if __name__ == '__main__':
    pass
    