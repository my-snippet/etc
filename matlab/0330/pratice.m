% ex3.2
w = [0:1:500]*pi/500;
X = exp(1j*w)./(exp(1j*w) - 0.5*ones(1,length(w)));
% It May do not need to add ones, therefore
X = exp(1j*w)./(exp(1j*w) - 0.5;

% 3.3
w = [0:1:500]*pi/500;
X = exp(1j*w)./(exp(1j*w) - 0.5*ones(1,length(w)));
subplot(2,2,1); plot(w/pi,abs(X)); grid % grid means dotted line
xlabel('freq in pi unit'); ylabel('Magnitude');
subplot(2,2,3); plot(w/pi,angle(X)); grid
xlabel('freq in pi unit'); ylabel('Radians'); grid
subplot(2,2,2); plot(w/pi,real(X)); grid
xlabel('freq in pi unit'); ylabel('Real'); grid
subplot(2,2,4); plot(w/pi,imag(X)); grid
xlabel('freq in pi unit'); ylabel('Imaginary'); grid

% 3.3 more
k = 0:500; w = k * (pi/500); % <- w = [0:1:500]*pi/500;
n = 0:2; % index
x = (0.5).^n;
X = x * (exp(-1j).^(n'*w)); % matrix multiplication

%{
' makes the column vector
If n in [0 1 2] then,
n' =	| 0 |
			| 1 |
			| 2 |
%}

%{
The length of matrix

1. length of n by 1 * length of w by 1 =  length of n by length of w
shortly, ln by 1 * lw by 1 = ln by lw

2. 1 by ln * ln by lw = 1 by lw

3. Length of matrix X = lX = lw

%}


% 3.5
n = 0:10; x = (0.9*exp(1j*pi/3)).^n;
k = -200:200; w = (pi/100)*k;
subplot(2,1,1); plot(w/pi,abs(X)); grid
xlabel('freq in pi unit'); ylabel('|X|');
subplot(2,1,2); plot(w/pi,angle(X)/pi); grid
xlabel('freq in pi unit'); ylabel('radians/pi');

% exp(2xy) = e^{2xy}

% 3.19
% a.
% all the sequences are already sampled Period.
% To be similar to analog, do one more sampling.
Dt = 0.000005; t = -0.005:Dt:0.005; xa = exp(-1000*abs(t));
Ts = 0.0002; n = -25:1:25; x=exp(-1000*abs(n*Ts));
K = 500; k = (-1*K):1:K; w=pi*k/K;
X = x*exp(-1j*n'*w); X = real(X);
% dicrete-time signal

subplot(2,1,1); plot(t*1000,xa);
hold on; xlabel('t in msec.'); ylabel('x1(n)');
stem(n*Ts*1000,x); gtext('Ts=0.2 msec');
% gtext : text in graph, default : right above

subplot(2,1,2); plot(w/pi,X);
xlabel('freq in pi unit'); ylabel('X1(w)');

% plot(t*1000,xa,'r')


% b.
% Ts = 0.001; n = -5:1:5; % it is similar to 3.19 except the sampling rate,
% sampling rate = 1000, sampling period = .0001


% ex3.21
...
Ts = 0.0002; n = -25:1:25; nTs = n*Ts
Fs = 1/Ts; x = exp(-1000*abs(n*Ts));
Dt = 0.00005; t = -0.005:Dt:0.005;
xt = exp(-1000*abs(t));
xa = x *sinc(Fs(ones(length(n),1)*t - nTs'*ones(1,length(t))));
error = max(abs(xa - exp(-1000*abs(t))));

subplot(2,1,1); plot(t*1000,xa);
hold on; xlabel('t in msec.'); ylabel('xa(n)');
stem(n*Ts*1000,x); gtext('Ts=0.1 msec');

subplot(2,1,2); plot(t*1000,xt);
xlabel('t in msec'); ylabel('x(t)');

% quiz
%{
x(n) | 0<= n <= 10, [0,1], x(n), X(e^{jw}), 501 points
%}
x = rand(1,11); n = 0:10
k = 0:500; w = (pi/500)*k;
X = x*(exp(-1j*pi/500)).^(n'*k);

subplot(2,2,1); plot(w/pi,abs(X)); grid

subplot(2,2,1); plot(w/pi,abs(X)); grid % grid means dotted line
xlabel('freq in pi unit'); ylabel('Magnitude');
subplot(2,2,3); plot(w/pi,angle(X)); grid
xlabel('freq in pi unit'); ylabel('Radians'); grid
subplot(2,2,2); plot(w/pi,real(X)); grid
xlabel('freq in pi unit'); ylabel('Real'); grid
subplot(2,2,4); plot(w/pi,imag(X)); grid
xlabel('freq in pi unit'); ylabel('Imaginary'); grid