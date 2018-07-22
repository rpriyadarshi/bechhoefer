function pks = calcFaultPeaks(info, fault) %#codegen
%CALCFAULTPEAKS Summary of this function goes here
%   Detailed explanation goes here
    pks = struct('avg', 0, 'min', 0, 'max', 0, 'val', zeros(5, 1), 'loc', zeros(5, 1), 'status', zeros(5, 1));
    [val, loc] = findpeaks(fault.spec, fault.freq);
    pks.avg = mean(val);
    pks.min = min(val);
    pks.max = max(val);
    
    %pks.val = [];
    %pks.loc = [];
    %pks.status = zeros(5, 1); %[cage, ball, outer, inner, shaft];
    for i = 1:4
        lohi = val > pks.max * info.thr & loc > fault.freqs(i) * info.min & loc < fault.freqs(i) * info.max;
        tmp_val = val(lohi);
        tmp_loc = loc(lohi);
        for j = 1:numel(tmp_loc)
            pks.val(i) = tmp_val(j);
            pks.loc(i) = tmp_loc(j);
        end
        if (numel(tmp_val))
            pks.status(i) = i;
        end
    end
end

