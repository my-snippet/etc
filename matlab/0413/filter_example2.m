% IIR filter example
n =0:99;
x=cos(n);

b1 = [1, -3, 11, 27];
a1 = [1, 0, 0, 0];
y1 = filter(b1, a1, x);

b2 = [1, -3, 11, -27]; a2 =1;
y2 = filter(b2, a2, x);

er = max(abs(y1-y2));