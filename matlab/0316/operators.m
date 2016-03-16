A = [10 30 ; 20 40];

B = find(A == 20);
B1 = (A > 15);
B2 = [0, 1 ; 1, 1];

C1 = (A <= 25);
D1 = (A ~= 40);
E1 = (A > 50);

F = A(B1);                                  % RESULT IS AUTOMATICALLY SORTED
% F1 = A(B2)                                % IT WILL CAUSES AN ERROR

F2 = A([1, 1 ; 2, 2]);

H = A > 15 & A < 33;