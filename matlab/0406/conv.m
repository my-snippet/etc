%% IMPORTANT
function z=user_conv(x,y)
N=length(x);
M=length(y);

% row vector temp
temp=[zeros(1,(N-1)),y,zeros(1,(N-1))];
% change to column vector
temp=temp(:);
% x=[4 2 3]
% y=[1 2 3 4]
% row vector version of temp=[0 0 1 2 3 4 0 0]
% temp(:) = | 0 |
%           | 0 |
%           |...|

% 3 2 4
% fliplr -->>
% if i = 1 then [0;0;1]
% ...
% if i =6 then [4;0;0]

z=zeros(1,M+N-1);

...
for i=1 ...