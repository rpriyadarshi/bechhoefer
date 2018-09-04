# Generated with SMOP  0.41-beta
from smop.libsmop import *
# ../Analyses/printResults.m

    
@function
def printResults(fault=None,*args,**kwargs):
    varargin = printResults.varargin
    nargin = printResults.nargin

    #PRINTRESULTS Summary of this function goes here
#   Detailed explanation goes here
    #pks = struct('avg', 0, 'min', 0, 'max', 0, 'val', zeros(5, 1), 'loc', zeros(5, 1), 'status', zeros(5, 1));
    #[cage, ball, outer, inner, shaft];
    if (fault.pks.val(3) != 0):
        fprintf('ERROR: Outer race condition detected')
    else:
        if (fault.pks.val(4) != 0):
            fprintf('ERROR: Inner race condition detected')
    
    return
    
if __name__ == '__main__':
    pass
    