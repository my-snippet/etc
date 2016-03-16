figure('color', 'w')
t =linspace(-2*pi, 2*pi, 250); y1=sin(t); y2=cos(t); y3=2*sin(t);

subplot(2,2,1)
plot(t, y1, '+b');
title('graph1'); xlabel('Time(s)'); ylabel('Amplitude');
subplot(2,2,2)
plot(t, y2, '-r');
title('graph2'); xlabel('Time(s)'); ylabel('Amplitude');
subplot(2,2,3)
plot(t, y3, 'xk');
title('graph3'); xlabel('Time(s)'); ylabel('Amplitude');
subplot(2,2,4)
plot(t, y1, '+b'); hold on; plot(t, y2, '-r'); plot(t, y3, 'xk');
title('graph4'); xlabel('Time(s)'); ylabel('Amplitude');
