n = 10
for l in range(2, n+1):
    for i in range(1, (n-l+1)+1):
        j = i + l - 1
        for k in range(i, (j-1)+1):
            print('l=%d i=%d j=%d k=%d' % (l, i, j, k))
