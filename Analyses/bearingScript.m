function bearingScript()
%BEARINGSCRIPT Summary of this function goes here
%   Detailed explanation goes here

    fullFileName = fileLoad();
    if (fullFileName)
        data = load(fullFileName);
        info = NiceBearing();
        fault = calcFaultFreq(info, data.bearing);
        plotFaultFreq(fault);
    end
end
