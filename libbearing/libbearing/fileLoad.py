# Generated with SMOP  0.41-beta
from smop.libsmop import *
import os
# ../Analyses/fileLoad.m

    
@function
def fileLoad(*args,**kwargs):
    varargin = fileLoad.varargin
    nargin = fileLoad.nargin

    #FILELOAD Summary of this function goes here
#   Detailed explanation goes here
#   https://www.mathworks.com/matlabcentral/answers/30238-gui-loading-a-mat-file
    
    fullFileName=[]
# ../Analyses/fileLoad.m:6
    
    # For convenience in browsing, set a starting folder from which to browse.
    startingFolder='C:\Program Files\MATLAB'
# ../Analyses/fileLoad.m:9
    if logical_not(exist(startingFolder,'dir')):
        pwd = os.getcwd()
        # If that folder doesn't exist, just start in the current folder.
        startingFolder=copy(pwd)
# ../Analyses/fileLoad.m:12
    
    # Get the name of the mat file that the user wants to use.
    defaultFileName=fullfile(startingFolder,'*.mat')
# ../Analyses/fileLoad.m:15
    baseFileName,folder=uigetfile(defaultFileName,'Select a mat file','MultiSelect','on',nargout=2)
# ../Analyses/fileLoad.m:16
    if (numel(baseFileName) == 0 and baseFileName == 0):
        # User clicked the Cancel button.
        return fullFileName
    
    fullFileName=fullfile(folder,baseFileName)
# ../Analyses/fileLoad.m:21
    return fullFileName
    
if __name__ == '__main__':
    pass
    