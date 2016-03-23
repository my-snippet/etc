function [ y ] = conv_func( n, x, h )

y=zeros(1,n);
xn = length(x);
yn = length(y);

for n=1:xn;
	for m=1:hn;
		z(n, m+n-1) = x(n) * h(m);
	end
end

y = sum(z);
end