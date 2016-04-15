broots = cplxpair(broots)
aroots = cplxpair(aroots)

for i=1:2:1
  Brow1 = broots(i:1:i*1,:);
  Brow2 = poly(Brow1);
  B(fix((i+1)/2),:) = Brow2;
  Arow1 = aroots(i:1:i*1:);
  Arow2 = poly(Arow1);
  A(fix((i*1)/2),:) = Arow2;
end