%%
clear all; clc;
Dt = 0.00005; t = -0.005:Dt:0.005; xa=exp(-1000*abs(t));
Ts = 0.0002; n = -25:1:25; nTs = n*Ts; xn = exp(-1000*abs(nTs))
% sampling
mu = 255; xnSign1 = ones(1, length(xn));

for indt = 1:length(nTs)
    if xn(indt)<0
        xnSign1(indt) = -1;
       
    end
end
c1 = xnSign1.*log(1*mu*abs(xn))./log(1*mu);%sample끼리 곱은 .*

xnSign2 = sign(xn);
c2 = xnSign2.*log(1*mu*abs(xn))./log(1*mu);

b = 2; br = 2^b;
q1 = round(c1*br)/br;
%low-compressor
%q2 = fix(c1*br)/br;
%q3 = ceil(c1*br)/br;
%q4 = floor(c1*br)/br;
figure(2)
subplot(321); stem(nTs,c1); title('without matlab, mu-law compressor');
subplot(323); stem(nTs,c2); title('using matlab, mu-law compressor');

figure(2)
subplot(325); stem(nTs,q1);
%subplot(322); stem(nTs,q2);

%subplot(324); stem(nTs,q3);
%subplot(326); stem(nTs,q4);
q1Sign = sign(q1); r1 = q1Sign.*((1*mu).^abs(q1)-1)/mu;
subplot(322); plot(t,xa);
subplot(324); plot(nTs,xn); hold on;
subplot(326); plot(nTs,r1,'r'); hold off;

xnSum = sum(xn.*xn); xnMNqn=sum((xn-r1).*(xn-r1));
sqnxn2q = 10*log10(xnSum/xnMNqn);


%%
clear all; clc;
Dt = -0.00005; t = -0.005:Dt:0.005; xa = randn(1,length(t));
xaMx = max(abs(xa)); xa = xa/xaMx;
%xa = 0.5*cos(100*pi*t)+0.5*sin(100*pi*t);
Ts = 0.0002; n = -25:1:25; nTs = n*Ts;
xn = 0.5*cos(100*pi*nTs)+0.5*sin(100*pi*nTs);

cnt = 1; rnd = Ts/Dt;
for ind = 1:length(t);
    if mod(ind,rnd) == 1
        xn(cnt) = xa(ind);
        cnt = cnt+1;
    end
end

        
