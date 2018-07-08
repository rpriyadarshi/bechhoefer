function fault = calcFaultFreq(info, bearing) %#codegen
%CALCFAULTFREQ Summary of this function goes here
%   Detailed explanation goes here
%   sr      = Sample rate (samples/sec)
%   gs      = Vector of 'g' (accelerometer) data
%   load    = Load
%   rate    = Shaft rate

    fault.pks = struct('avg', 0, 'min', 0, 'max', 0, 'val', zeros(5, 1), 'loc', zeros(5, 1), 'status', zeros(5, 1));

    faultRates = ones(5, 1); %[cage, ball, outer, inner, shaft];
    for i = 1:4
        faultRates(i) = GetBearFreqRatio(info.rd, info.pd, info.ca, info.ne, i, info.side);
    end

    fault.freqs = faultRates * bearing.rate;

    %1/bearing.sr = 2.0480e-05
    bearing_sr = 1/bearing.sr;
    %bearing_sr = 2.0480e-05;
    
    [env, dty] = envelope1(bearing.gs, bearing_sr, 128, 2000, 4000);

	[fault.spec, fault.freq] = psde(env, 2048,1/dty, 1024);
    
    fault.pks = calcFaultPeaks(info, fault);
end
