A = eye(3);
B = zeros(3,5);
C = magic(3);
D = [2; 5; 6;];

% sol1
E = zeros(6, 8);
E(1:3, 1:3) = A;
E(1:3, 4:8) = B;
E(4:6, 1:3) = C;
E(4:6, 4) = D;
E(4:6, 5) = D;
E(4:6, 6:8) = diag(D);
E

% sol2
a = [ A, B; C, D, D, diag(D)];
a