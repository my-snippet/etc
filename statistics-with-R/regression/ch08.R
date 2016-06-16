possum <- read.table(file="possum.txt",sep="\t",head=TRUE)

# scatter-plot
plot(possum$headL, possum$totalL)

# correlation
cor(possum$headL, possum$totalL)

# correlation test
cor.test(possum$headL, possum$totalL)

# simple linear regression
lm(possum$headL ~ possum$totalL)

# check the formulas used in regression
possum.res<-lm(possum$headL ~ possum$totalL)
summary(possum.res)

# variation analysis == F test
anova(possum.res)
