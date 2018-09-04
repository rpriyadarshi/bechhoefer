# Generated with SMOP  0.41-beta
from smop.libsmop import *
import math
# ../Analyses/envelope1.m

    
@function
def envelope1(data=None,dt=None,nfilt=None,lowf=None,highf=None,*args,**kwargs):
    varargin = envelope1.varargin
    nargin = envelope1.nargin

    #ENVELOPE1 Summary of this function goes here
#   [env,dty] = envelope1(data,dt,nfilt,lowf,highf);
#Inputs:
#   data:   data vector, time domain
#   dt:     sampling time interval
#   nfilt:  size of filter for low pass filtering
#   lowf:   low frequency limit of bandpass filter
#   highf:  high frequency limit of bandpass filter
#Outputs:
#   env:    Envelope of data
#   dty:    decimated sample rate
    
    c=(highf + lowf) / 2
# ../Analyses/envelope1.m:14
    if 1 / dt / 2 < c:
        y=[]
# ../Analyses/envelope1.m:16
        dt=[]
# ../Analyses/envelope1.m:17
    else:
        ndata=length(data)
# ../Analyses/envelope1.m:20
        z=multiply(ravel(data),exp(dot(dot(dot(dot(dot(- 2,math.pi),1j),c),dt),(arange(0,ndata - 1)).T)))
# ../Analyses/envelope1.m:21
        bw=highf - lowf
# ../Analyses/envelope1.m:22
        b=fir1(nfilt,dot(bw,dt))
# ../Analyses/envelope1.m:23
        x=filter(b,1,z)
# ../Analyses/envelope1.m:24
        r=fix(1 / (dot(dot(bw,2),dt)))
# ../Analyses/envelope1.m:25
        env=abs(x(arange(nfilt + 1,ndata,r)))
# ../Analyses/envelope1.m:26
        dty=dot(dt,r)
# ../Analyses/envelope1.m:28
    
    return env,dty
    
if __name__ == '__main__':
    pass
    