function info = NiceBearing
%NICEBEARING Summary of this function goes here
%   rd:     roller diameter
%   pd:     pitch diameter
%   ca:     contact angle in degrees
%   ne:     number of elements
%   type    enum[cage, roller, outer race, inner race]
%   side:   inner or outer race fixed.  inner = 1, outer = 2;
%   Eric Bechhoefer, April 10, 2009 for PHM Conference

    info.rd = .235;
    info.ca = 0;
    info.ne = 8;
    info.pd = 1.245;

    info.side = 2;
    
    info.thr = 0.75;
    info.min = 0.95;
    info.max = 1.05;
end
