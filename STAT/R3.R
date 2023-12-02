#Q1
#set working directory to the folder where bears.txt is located
setwd("/Users/Kev/Downloads")
# Read in the data set
bears <- read.table("bears (1).txt", header = TRUE)

#print first 6 lines of the dataset
head(bears, 6)

# Get the number of observations in the Weight vector
n <- length(bears$Weight)
n

# Determine the location of underweight bears in the data
locate.underweight <- which(bears$Weight < 100)
locate.underweight

# Get the number of values in the underweight group
n.underweight <- length(locate.underweight)
print(paste("Number of underweight bears: ", n.underweight))

# State the hypothesis and check the conditions
# Hypothesis:
# H0: The proportion of underweight bears is less than or equal to 0.15.
# HA: The proportion of underweight bears is greater than 0.15.
# Conditions:
# 1. Random sample: We assume that the sample is random since the data was collected from bears in the population.
# 2. Independence: We assume that the observations are independent.
# 3. Sample size: Since n = 100 is large, we can use the normal approximation to the binomial distribution.

# Perform the hypothesis test using a one-tailed z-test with a significance level of alpha = 0.05
# Calculate the sample proportion of underweight bears
p.hat <- n.underweight / n
p.hat

# Calculate the standard error of the sample proportion
SE.p.hat <- sqrt(p.hat * (1 - p.hat) / n)
SE.p.hat

# Calculate the test statistic
z <- (p.hat - 0.15) / SE.p.hat
print(paste("Test statistic: ", z))

# Calculate the p-value
p.value <- 1 - pnorm(z)
print(paste("P-value: ", p.value))

# Interpret the results
# Since the p-value is less than the significance level of alpha = 0.05, 
# we reject the null hypothesis. Therefore, there is sufficient evidence 
# to conclude that the proportion of underweight bears in the population
# is greater than 15 percent. Measures to improve the food supply and protect 
# the existing bear population should be implemented.


# 2a. Subset data to include only female bears
locateFemale <- which(bears$Gender == 2)
bears.female <- bears[locateFemale,]

# 2b. Hypothesis test for mean chest circumference of female bears
# Null hypothesis: mu = 35 (average chest circumference of female bears is 35 inches)
# Alternative hypothesis: mu < 35 (average chest circumference of female bears is less than 35 inches)

# Check conditions (normality and independence)
hist(bears.female$Chest, main = "Histogram of Chest Circumference for Female Bears")
qqnorm(bears.female$Chest, main = "Normal Probability Plot of Chest Circumference for Female Bears")
qqline(bears.female$Chest)

# From the plots, the distribution appears approximately normal with no obvious outliers, so we can proceed with the test.

# Perform one-sample t-test
t.test(bears.female$Chest, mu = 35, alternative = "less")

# The test statistic is t = -0.76678 with a p-value of 0.2266.
# Since p-value > 0.05, we do not reject the null hypothesis and conclude that the average chest circumference of female bears is 35 inches.

# 2c. Confidence interval for mean chest circumference of female bears
# Calculate 90% confidence interval using t-distribution
t.test(bears.female$Chest, conf.level = 0.9)

# The 90% confidence interval for the mean chest circumference of female bears is (30.37, 36.79).
# Since the interval contains the null hypothesis value of 35, it agrees with our conclusion from part 
# (b) that the average chest circumference of female bears is 35 inches.

