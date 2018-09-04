# Generated with SMOP  0.41-beta
from smop.libsmop import *
# ../Analyses/playVideo.m

    
@function
def playVideo(vidObj=None, axes=None, *args, **kwargs):
    varargin = playVideo.varargin
    nargin = playVideo.nargin

    #PLAYVIDEO Summary of this function goes here
#   Detailed explanation goes here
    vidObj.CurrentTime = copy(0.0)
# ../Analyses/playVideo.m:4
    currAxes=copy(axes)
# ../Analyses/playVideo.m:5
    while hasFrame(vidObj):

        vidFrame=readFrame(vidObj)
# ../Analyses/playVideo.m:7
        image(vidFrame,'Parent',currAxes)
        currAxes.Visible = copy('off')
# ../Analyses/playVideo.m:9
        pause(1 / vidObj.FrameRate)

    
    return
    
if __name__ == '__main__':
    pass
    