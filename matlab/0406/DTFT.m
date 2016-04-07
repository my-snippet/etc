function [Xk] = dft_(xn,N)

n = [0:1:N-1];
k = [0:1:N-1];
WN = exp(-1j*2*pi/N);
nk = n'*k;
WNnK = wn .^ nk; % .^ : exp(nk)
Xk = xn * WNnK;
% '* : matrix multiplication
% .^ : matrix exponential

if x(n) = 0.5^n, 0<=n<=10, then X(e^{jw})?

n = 0:10; x = (0.5).^n;
X = dft(exp(j*w),length(n))