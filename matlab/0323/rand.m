N = 100;
n =1:N;
x = rand(1,N);
y = randn(1,N);
plot(n, x, '+r'); hold on; plot(n, y, '*k');