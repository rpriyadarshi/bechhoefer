function bearingScript() %#codegen
%BEARINGSCRIPT Summary of this function goes here
%   Detailed explanation goes here

    fullFileName = fileLoad();
    if (fullFileName)
        fault = bearingCalc(fullFileName);
        plotFaultFreq(fault);
    end
end

% Tookbox dependency: [fList,pList] = matlab.codetools.requiredFilesAndProducts('bearingScript.m')
