% ex2-1 : x(n) = cos(0.04 pi n) + 0.2w(n), 0 <= n <= 50;

n = 0 : 50; N =length(n);
x = cos(0.04 * pi *n) + 0.2 * randn(1, N);
stem(n, x);
xlabel('n'); ylabel('x(n)');