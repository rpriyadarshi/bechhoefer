function fault = bearingGen() %#codegen
%BEARINGGEN Bearing fault calculator
%   Detailed explanation goes here
    data = coder.nullcopy(struct('bearing', struct('sr', double(0), 'gs', [], 'load', double(0), 'rate', double(0))));
    data = load('Data/InnerRaceFault_vload_1');
    info = NiceBearing();
    fault = calcFaultFreq(info, data.bearing);
    %plotFaultFreq(fault);
end

% codegen 'bearingGen'

