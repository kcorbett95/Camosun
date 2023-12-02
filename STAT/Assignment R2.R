# Question 1: radioactive particles
lambda <- 8.2 	# average number of particles emitted per second
n <- 25 		# number of particles observed
t <- 7 		# time in seconds
p <- dpois(n, lambda*t) 	# probability mass function for Poisson distribution
# output:
p
# 
# Question 2: brittle ceramic blades
p_brittle <- 0.031 	# probability that a blade is too brittle
n <- 40 		# sample size
k <- 2 		# at least 2 blades are too brittle
p <- pbinom(k, n, p_brittle, lower.tail = FALSE) 	# cumulative distribution function for binomial distribution
# output:
p
# 
# Question 3: daily rainfall
mu <- 12.3 		# mean daily rainfall in mm
sigma <- 3.9 	# standard deviation of daily rainfall in mm
# 
# part (a)
x <- 10 	# threshold for less than x mm of rain
p <- pnorm(x, mu, sigma) 	# cumulative distribution function for normal distribution
# output:
p
# 
# part (b)
p <- qnorm(0.85, mu, sigma) 	# quantile function for normal distribution
# output:
p
# 
# Question 4: steel sheet thicknesses
a <- 150 	# lower limit of uniform distribution
b <- 200 	# upper limit of uniform distribution
# 
# part (a)
set.seed(059) 	# set seed for reproducibility
n <- 100 		# sample size
steel <- runif(n, a, b) 	# generate sample of steel sheet thicknesses
# create histogram of sample
hist(steel, col='green', main = "Corbett:\nHistogram of Steel Sheet Thicknesses and Sample Means\n(#sheets = 100, #samples = 30, Seed = 059)", xlab = "Thickness (mm)") 
# 
# part (b)
mean_sample <- mean(steel) 		# sample mean
sd_sample <- sd(steel) 			# sample standard deviation
mean_theoretical <- (a + b)/2 	# theoretical mean of uniform distribution
sd_theoretical <- (b - a)/sqrt(12) 	# theoretical standard deviation of uniform distribution
# output:
mean_sample
# output:
sd_sample 
# output:
mean_theoretical
# output:
sd_theoretical 
# The sample mean is close to the theoretical mean, 
# but the sample standard deviation is slightly smaller 
# than the theoretical standard deviation. We could improve 
# the estimates by increasing the sample size.
# 
# part (c)
mu_x <- mean_theoretical 		# mean of sample means is equal to the population mean
StdErr_x <- sd_theoretical/sqrt(n) 	# std dev of sample means is equal to pop'n std dev divided by sqrt of sample size
# output:
mu_x 
# output:
StdErr_x 
# Theoretical distribution for sample average of x is Normal
# 
# part (d)
steel.means <- c() 	# initiate empty vector for means
for (i in 1:30) {
  set.seed(059*i) 	# set seed for each iteration
  steel <- runif(n, a, b) 	# generate new sample
  new.mean <- mean(steel) 	# calculate sample mean
  steel.means[i] <- new.mean 	# store sample mean in vector
}
# output: vector of 30 sample means
steel.means 
# 
# part (e)
# Histogram of 30 steel sheet sample means with sample sizes of n = 100
hist(steel.means, col='red', add=TRUE, xlab = "Mean Thickness (mm)" )
legend("topright", c("Steel Sheet Thickness", "Sample Means"), fill = c("Green", "Red"), xpd = TRUE)
# Distribution appears normal, with a peak around theoretical mean of 175mm
# 
# part (f)
# Calculate mean and std dev of steel.means
mean.sample.means <- mean(steel.means)
sd.sample.means <- sd(steel.means)
# Compare to theoretical mean and std dev of sample means
mean.sample.means		# output: Average of 30 sample means
mu_x		# output: Theoretical mean of sample means
sd.sample.means		# output: Std Err of 30 sample means
StdErr_x		# output: Theoretical Std Err of sample means
# 
# part (g)
#To improve the estimates gathered in part (f), we should increase the number of samples (from t=30). 
# This is because the standard error of the mean decreases as the sample size increases, while the 
# standard deviation of the population remains constant. Therefore, by increasing the number of samples, 
# we can obtain a more precise estimate of the population mean. Increasing the number of observations in 
# each sample (from n=100) would also decrease the standard error of the mean, but it would require more 
# time and resources. Therefore, increasing the number of samples is a more efficient approach to improve
# the estimates.