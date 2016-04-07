n=0.99; x=cos(0.48*pi*n)*cos(0.52*pi*n);
n1 = 0:9; y1= x(1:1:length(n1));

subplot(2,1,1); plot(n1,y1,'k'); hold on; stem(n1,y1);
title('signal x(n) 0<=n<=9'); xlabel('n');

Y1 = dft(y1,length(n1));
w1 = 2*pi/10*n1;


subplot(2,1,2); plot(w1/pi,abs(Y1),'k'); hold on; stem(w1/pi,abs(Y1));
title('Sample of DTFT Magnitude'); xlabel('freq in pi units');