n=0.99; x=cos(0.48*pi*n)*cos(0.52*pi*n);
y2= [x(1:length(n2)), zeros(1,length(n)-length(n2)); % zero-padding

subplot(2,1,1); plot(n,y2,'k'); hold on; stem(n,y2);
title('signal x(n) 0<=n<=9'); xlabel('n');

Y2 = dft(y2,length(n));
w2 = 2*pi/10*n;


subplot(2,1,2); plot(w2/pi,abs(Y2),'k'); hold on; stem(w2/pi,abs(Y2));
title('Sample of DTFT Magnitude'); xlabel('freq in pi units');