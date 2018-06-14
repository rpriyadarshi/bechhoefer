function bearingScript() %#codegen
%BEARINGSCRIPT Summary of this function goes here
%   Detailed explanation goes here

    filename = fileLoad();
    if (numel(filename))
        fault = bearingCalc(filename);
        plotFaultFreq(fault);
    end
end

% Tookbox dependency: [fList,pList] = matlab.codetools.requiredFilesAndProducts('bearingScript.m')
