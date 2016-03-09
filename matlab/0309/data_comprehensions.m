% l = m = n 
l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

% increase from 1 to 10 by 1
m = 1 : 1 : 10;
n = 1 : 10;

o = linspace(1, 20, 10);

% 3 to 6 by 1, 
% 5 to 1 by-2, 
% 1 to 10 of 5 points 
A = [3:6, 5:-2:1, linspace(1, 10, 5)];

B = zeros(10, 5);
C = ones(7, 3);

% unit vector 
D = eye(5, 5);

% MA BANG JIN
E = magic(3);

% diagonal
F = diag([1 3 5 2]);