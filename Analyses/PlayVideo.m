function PlayVideo(vidObj, axes)
%PLAYVIDEO Summary of this function goes here
%   Detailed explanation goes here
    vidObj.CurrentTime = 0.0;
    currAxes = axes;
    while hasFrame(vidObj)
        vidFrame = readFrame(vidObj);
        image(vidFrame, 'Parent', currAxes);
        currAxes.Visible = 'off';
        pause(1/vidObj.FrameRate);
    end
end

