function fault = bearingGen() %#codegen
%BEARINGGEN Bearing fault calculator
%   Detailed explanation goes here
    data = load('Data/InnerRaceFault_vload_1');
    info = NiceBearing();
    fault = calcFaultFreq(info, data.bearing);
    %plotFaultFreq(fault);
end

% codegen 'bearingGen'

