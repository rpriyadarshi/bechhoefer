function peaks = calcFaultPeaks(fault)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    [val, loc] = findpeaks(fault.spec, fault.freq);
    
    peaks.val = [];
    peaks.loc = [];
    for i = 1:4
        lohi = loc > fault.freqs(i) * 0.95 & loc < fault.freqs(i) * 1.05;
        tmp_val = val(lohi);
        tmp_loc = loc(lohi);
        for j = 1:numel(tmp_loc)
            peaks.val = [peaks.val tmp_val(j)];
            peaks.loc = [peaks.loc tmp_loc(j)];
        end
    end
end

