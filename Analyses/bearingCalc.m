function fault = bearingCalc(data) %#codegen
%BEARINGCALC Bearing fault calculator
%   Detailed explanation goes here
    if (numel(data))
        info = NiceBearing();
        fault = calcFaultFreq(info, data.bearing);
    end
end

