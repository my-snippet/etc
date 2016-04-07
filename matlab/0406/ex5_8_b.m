n=0.99; x=cos(0.48*pi*n)*cos(0.52*pi*n);

subplot(2,1,1); plot(n,x,'k'); hold on; stem(n,x);
title('signal x(n) 0<=n<=99'); xlabel('n');

X = dft(x,length(n));
w = 2*pi/100*n;

subplot(2,1,2); plot(w/pi,abs(X),'k'); hold on; stem(w/pi,abs(X));
title('Sample of DTFT Magnitude'); xlabel('freq in pi units');