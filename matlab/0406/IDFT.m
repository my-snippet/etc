function [xn] = kmw_idft(Xk,N)

n = [0:1:N-1];
k = [0:1:N-1];
WN = exp(-1j*2*pi/N);
nk = n'*k;
WNnk = WN .^ (-nk);
xn = XK * WNnk)/N;


% ex
% difference between x(n), x_i(n)
% X(e^{jw})
n = 0:10; x = (0.5).^n;
X = dft_(x,length(n));
xi = idft(X,length(n));