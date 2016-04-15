% IIR filter example
n =0:99;
x=cos(n);

b = [1, -3, 11, -27];
a = [1, 12, 2, -4];

y = filter(b, a, x);

subplot(2,1,1); plot(n,x);
subplot(2,1,2); plot(n,y);