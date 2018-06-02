function fault = bearingCalc(fullFileName) %#codegen
%BEARINGCALC Bearing fault calculator
%   Detailed explanation goes here
    if (fullFileName)
        data = load(fullFileName);
        info = NiceBearing();
        fault = calcFaultFreq(info, data.bearing);
    end
end

