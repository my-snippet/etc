apples=input('Number:');
cost = 1000;

if apples > 10
    Pay = (1-20/100)*cost*apples;
elseif apples > 5
    Pay = (1-10/100)*cost*apples;
else
    Pay = (1-5/100)*cost*apples;
end

A = 0
for idx = 1 : 50
    A = A + idx;
end
A