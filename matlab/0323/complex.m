% x(n) = e^{(-0.1 + j0.3)n}, -10 <= n <= 10

n = -10 : 1 : 10;
x = exp((-0.1 + 0.3j) *n);
subplot(2,2,1); stem(n, real(x));
subplot(2,2,2); stem(n, imag(x));
subplot(2,2,3); stem(n, abs(x));
subplot(2,2,4); stem(n, (180/pi) * angle(x));