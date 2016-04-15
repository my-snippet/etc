% IIR filter example
n =0:99;
x=cos(n);

b = [1, 3, 4, 3, 1];
a = [1, 1, -4, -1, 1];

K = floor(length(b)/2); B = zeros(k,3); A = zeros(K,3);
if K*2 == length(b);
  b = [b 0];
  a = [a 0];
end