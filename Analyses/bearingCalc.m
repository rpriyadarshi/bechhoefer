function fault = bearingCalc(fullFileName)
%BEARINGCALC Bearing fault calculator
%   Detailed explanation goes here
    if (fullFileName)
        data = load(fullFileName);
        info = NiceBearing();
        fault = calcFaultFreq(info, data.bearing);
    end
end

