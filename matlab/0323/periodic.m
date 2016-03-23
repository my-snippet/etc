n1 = 0; n2 = 1;
n = n1 : 0.01 : n2 - 0.01;
x = n;
xtilde = [ x, x, x, x, x, x];
subplot(2,1,1); plot([0:0.01:7-0.01], xtilde);