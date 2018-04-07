function bearingScript(bearing)
%BEARINGSCRIPT Summary of this function goes here
%   Detailed explanation goes here

    [rd, pd, ca, ne, side] = NiceBearing;

    faultRates = ones(5, 1); %[cage, ball, outer, inner, shaft];
    for i = 1:4
        faultRates(i) = GetBearFreqRatio(rd, pd, ca, ne, i, side);
    end

    faultFreq = faultRates * bearing.rate;

    [env, dty] = envelope1(bearing.gs, 1/bearing.sr, 128, 2000, 4000);

	[spec, freq] = psde(env, 2048,1/dty, 1024);

    plot(freq, spec);
    ax = [xlim ylim]; % axis();
    hold on
    for i = 1:5
        f = faultFreq(i);
        plot([f f], ax(3:4),'LineWidth',2)
    end
    hold off
    legend('env','cage','ball','outer','inner','1/rev')
    xlabel('Hz')
    ylabel('Gs')
    %axis([0 200 ax(3:4)])
    xlim([0 200])
    ylim(ax(3:4))
end
