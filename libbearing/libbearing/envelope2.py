# Generated with SMOP  0.41-beta
from smop.libsmop import *
# ../Analyses/envelope2.m

    
@function
def envelope2(data=None,dt=None,lowf=None,highf=None,*args,**kwargs):
    varargin = envelope2.varargin
    nargin = envelope2.nargin

    #ENVELOPE2 Summary of this function goes here
#   [env,dty] = envelope1(data,dt,nfilt,lowf,highf);
#Inputs:
#   data:   data vector, time domain
#   dt:     sampling time interval
#   lowf:   low frequency limit of bandpass filter
#   highf:  high frequency limit of bandpass filter
#Outputs:
#   env:    Envelope of data
#   dty:    decimated sample rate
    
    n=length(data)
# ../Analyses/envelope2.m:13
    dfq=1 / dt / n
# ../Analyses/envelope2.m:14
    idxLow=floor(lowf / dfq)
# ../Analyses/envelope2.m:15
    idxHi=ceil(highf / dfq)
# ../Analyses/envelope2.m:16
    D=fft(data)
# ../Analyses/envelope2.m:17
    idx=idxHi - idxLow + 1
# ../Analyses/envelope2.m:18
    D[arange(1,idx)]=D(arange(idxLow,idxHi))
# ../Analyses/envelope2.m:20
    D[arange(idx + 1,end())]=0
# ../Analyses/envelope2.m:21
    data=abs(ifft(D))
# ../Analyses/envelope2.m:22
    bw=highf - lowf
# ../Analyses/envelope2.m:23
    r=fix(1 / (dot(dot(bw,2),dt)))
# ../Analyses/envelope2.m:24
    env=data(arange(1,n,r))
# ../Analyses/envelope2.m:25
    
    dty=dot(dt,r)
# ../Analyses/envelope2.m:27
    return env,dty
    
if __name__ == '__main__':
    pass
