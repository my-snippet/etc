# Reference
# https://gist.github.com/davetang/6485079#file-permutation_with_replacement-r
# http://davetang.org/muse/2013/09/09/combinations-and-permutations-in-r/

# install if necessary
# install.packages('gtools')
library(gtools)


x <- c('red', 'blue', 'black')
# 3P2 = ?
permutations(n=3, r=2, v=x)