function plotFaultFreq(fault) %#codegen
%PLOTFAULTFREQ Summary of this function goes here
%   Detailed explanation goes here
%   https://www.mathworks.com/help/releases/R2016b/matlab/creating_guis/graphics-support-in-app-designer.html

    plot(fault.freq, fault.spec);
    ax = [xlim ylim]; % axis();
    hold on
    for i = 1:5
        f = fault.freqs(i);
        plot([f f], ax(3:4),'LineWidth', 2)
    end
    plot(fault.peaks.loc, fault.peaks.val, 'o');
    hold off
    legend('env','cage','ball','outer','inner','1/rev')
    xlabel('Hz')
    ylabel('Gs')
    %axis([0 200 ax(3:4)])
    xlim([0 200])
    ylim(ax(3:4))
end

