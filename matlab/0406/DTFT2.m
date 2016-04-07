function [X] = dtft(x,n,w)
X = x*exp(-1j*n '*w);
end

% ex
% in reaility, seperate it as other file
k = 0:500; w = k*(pi/500);
n = 0:2; x = (0.5).^n;
X = dtft(x,n,w) % QUIZ