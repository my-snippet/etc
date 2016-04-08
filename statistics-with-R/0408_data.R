3+5
x <- 3
y <- 5
x+y

x <- "Hello"
x

x <- c(1,2,3)# vector
y <- c(4,5,6)
x+y

A <- matrix(c(1,3,5,7), ncol=2, nrow=2)
B <- matrix(c(1,2,3,4,5,6,7,8,9), ncol=3)
A;B

a1 <- c(1,2,3,4)
a2 <- c(5,6,7,8)
a3 <- c(9,10,11,12)
b1 <- c("M", "F", "M", "F")

cbind(a1, a2, a3)
rbind(a1, a2, a3)
cbind(a1, b1)

id <- c(1,2,3,4,5)
gender <- c("M", "M", "F", "F", "M")
math <- c(66,64,48,46,78)
eng <- c(70,68,46,48,84)

score <- data.frame(id, gender, math, eng)
score

gender <- factor(c("M", "M", "M", "M", "M", "M", "M", "M", "F", "F", "F", "F", "F", "F", "F", "F", "F", "F"))
score <- c(98,90,96,54,43,87,88,90,94,92,81,79,85,91,79,88,89,83)
hist(score)
hist(score, freq=F)
hist(score, breaks=10)

stem(score)
boxplot(score)

table(gender)

fivenum(x)
summary(x)
mean(score)
sd(score)
var(score)
sum(x)

math <- c(66,64,48,46,78,60,90,50,66,70)
physics <-c(70,68,46,48,84,64,92,52,68,72)
plot(math, physics)

# correlation: max 1, min 0
cor(math, physics)

for (i in 1:3) { x<-i+1 ; print(x)}
for (j in 5:1) { print(j) }

if(3>5) { print("yes") } else { print("no")}

for (i in 1:10) {
  if (i%%2==0) { print(i) }
}

# error occured
# sample(c(1:10), 100, replace=F)
