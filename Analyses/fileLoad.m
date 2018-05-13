function fullFileName = fileLoad()
%FILELOAD Summary of this function goes here
%   Detailed explanation goes here
%   https://www.mathworks.com/matlabcentral/answers/30238-gui-loading-a-mat-file

    fullFileName = [];
    % Have user browse for a file, from a specified "starting folder."
    % For convenience in browsing, set a starting folder from which to browse.
    startingFolder = 'C:\Program Files\MATLAB';
    if ~exist(startingFolder, 'dir')
        % If that folder doesn't exist, just start in the current folder.
        startingFolder = pwd;
    end
    % Get the name of the mat file that the user wants to use.
    defaultFileName = fullfile(startingFolder, '*.mat');
    [baseFileName, folder] = uigetfile(defaultFileName, 'Select a mat file', 'MultiSelect', 'on');
    if (numel(baseFileName) == 0 && baseFileName == 0)
        % User clicked the Cancel button.
        return;
    end
    fullFileName = fullfile(folder, baseFileName);
end

