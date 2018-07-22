function fault = bearingGen() %#codegen
%BEARINGGEN Bearing fault calculator
%   Detailed explanation goes here
    data = coder.load('Data/InnerRaceFault_vload_1');
    info = NiceBearing();
    fault = calcFaultFreq(info, data.bearing);
    printResults(fault);
    %plotFaultFreq(fault);
end

% codegen 'bearingGen'

