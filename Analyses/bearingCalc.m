function fault = bearingCalc(filename) %#codegen
%BEARINGCALC Bearing fault calculator
%   Detailed explanation goes here
    if (numel(filename))
        data = load(filename);
        info = NiceBearing();
        fault = calcFaultFreq(info, data.bearing);
    end
end

% data = load('Data/baseline_1.mat');
% codegen 'bearingCalc' '-args' 'data'
% codegen 'bearingCalc' '-args' 'Data/baselint_1.mat'
