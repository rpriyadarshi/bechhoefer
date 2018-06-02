function fault = calcFaultFreq(info, bearing) %#codegen
%CALCFAULTFREQ Summary of this function goes here
%   Detailed explanation goes here
%   sr      = Sample rate (samples/sec)
%   gs      = Vector of 'g' (accelerometer) data
%   load    = Load
%   rate    = Shaft rate

    faultRates = ones(5, 1); %[cage, ball, outer, inner, shaft];
    for i = 1:4
        faultRates(i) = GetBearFreqRatio(info.rd, info.pd, info.ca, info.ne, i, info.side);
    end

    fault.freqs = faultRates * bearing.rate;

    [env, dty] = envelope1(bearing.gs, 1/bearing.sr, 128, 2000, 4000);

	[fault.spec, fault.freq] = psde(env, 2048,1/dty, 1024);
    
    fault.peaks = calcFaultPeaks(info, fault);
end
