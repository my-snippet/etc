load(conv_func);

n = -10:0.01:10;
% n = 6;
x = [3, 11, 7, 0, -1, 4];
h = [2, -1, 3, 0, 0, 4];

conv_func(n, x, h);