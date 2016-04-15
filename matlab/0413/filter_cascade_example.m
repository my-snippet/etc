% IIR filter example
n =0:99;
x=cos(n);

b = [1, 3, 4, 3, 1];
a = [1, 1, -4, -1, 1];

broots = roots(b); aroots = roots...