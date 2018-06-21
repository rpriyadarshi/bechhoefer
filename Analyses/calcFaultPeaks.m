function peaks = calcFaultPeaks(info, fault) %#codegen
%CALCFAULTPEAKS Summary of this function goes here
%   Detailed explanation goes here
    peaks = struct('avg', 0, 'min', 0, 'max', 0, 'val', [], 'loc', [], 'status', zeros(5, 1));
    [val, loc] = findpeaks(fault.spec, fault.freq);
    peaks.avg = mean(val);
    peaks.min = min(val);
    peaks.max = max(val);
    
    peaks.val = [];
    peaks.loc = [];
    peaks.status = zeros(5, 1); %[cage, ball, outer, inner, shaft];
    for i = 1:4
        lohi = val > peaks.max * info.thr & loc > fault.freqs(i) * info.min & loc < fault.freqs(i) * info.max;
        tmp_val = val(lohi);
        tmp_loc = loc(lohi);
        for j = 1:numel(tmp_loc)
            peaks.val(j) = tmp_val(j);
            peaks.loc(j) = tmp_loc(j);
        end
        if (numel(tmp_val))
            peaks.status(i) = i;
        end
    end
end

