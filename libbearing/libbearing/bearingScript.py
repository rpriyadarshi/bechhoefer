# Generated with SMOP  0.41-beta
from smop.libsmop import *
from .fileLoad import *
from .bearingCalc import *
from .plotFaultFreq import *
# ../Analyses/bearingScript.m

    
@function
def bearingScript(*args,**kwargs):
    varargin = bearingScript.varargin
    nargin = bearingScript.nargin

    #BEARINGSCRIPT Summary of this function goes here
#   Detailed explanation goes here
    
#    filename=fileLoad()
    filename='data/baseline_1.mat'
# ../Analyses/bearingScript.m:5
    if (numel(filename)):
        filedata=load(filename)
        data = Data();
        data.bearing.gs = filedata['bearing']['gs'][0][0]
        data.bearing.sr = filedata['bearing']['sr'][0][0][0]
        data.bearing.load = filedata['bearing']['load'][0][0][0]
        data.bearing.rate = filedata['bearing']['rate'][0][0][0]
# ../Analyses/bearingScript.m:7
        fault=bearingCalc(data)
# ../Analyses/bearingScript.m:8
        plotFaultFreq(fault)
    
    return
    
if __name__ == '__main__':
    pass
    
    # Tookbox dependency: [fList,pList] = matlab.codetools.requiredFilesAndProducts('bearingScript.m')