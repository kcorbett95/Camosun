#set working directory to the folder where bears.txt is located
setwd("/Users/C0527059/Downloads")
bears <- read.table("bears.txt", header = TRUE)

#print first 6 lines of the dataset
head(bears, 6)

#calculate mean age of bears
mean_age <- mean(bears$Age)
print(paste("Mean age: ", mean_age))

#calculate variance of headwidth
var_headwidth <- var(bears$Headwidth)
print(paste("Variance of headwidth: ", var_headwidth))

#Install ggplot2 package
install.packages("ggplot2")
#create a side-by-side box plot to compare weight of bears separated by gender
library(ggplot2)
ggplot(data = bears, aes(x = factor(Gender), y = Weight, fill = factor(Gender))) +
  geom_boxplot() +
  ggtitle("Weight of Bears by Gender") +
  xlab("Gender") +
  ylab("Weight")

#determine number of bears measured in the dataset
n_bears <- dim(bears)[1]
print(paste("Number of bears: ", n_bears))

#calculate number of ways to randomly select 10 bears out of the group recorded
from_n <- dim(bears)[1]
ways <- choose(from_n,10)
print(paste("Number of ways to randomly select 10 bears out of the group recorded:", ways))


# Q2
# Set the data
velocities <- c(44,36,40,34,49,47,49,54,52,51,52,48,55,46,29,51,54,54,55,49,44,43,46)

# Calculate mean and median
mean_velocity <- mean(velocities)
print(paste("Mean velocity: ", mean_velocity))
median_velocity <- median(velocities)

# Determine if data is symmetric, skewed left, or skewed right
if(mean_velocity == median_velocity){
  print("Data is symmetric")
} else if(mean_velocity < median_velocity){
  print("Data is skewed left")
} else {
  print("Data is skewed right")
}

# Create histogram
library(ggplot2)
ggplot(data = velocities, aes(x = velocities)) +
  geom_histogram(color = "blue", fill = "blue") +
  ggtitle("Air Velocity Histogram") +
  xlab("Velocity") +
  ylab("Frequency")

# Calculate standard deviation and IQR
std_velocity <- sd(velocities)
iqr_velocity <- IQR(velocities)

# Determine which measure of spread to use
if(std_velocity > iqr_velocity){
  print("Standard deviation is a better measure of spread for this dataset.")
} else {
  print("IQR is a better measure of spread for this dataset.")
}

# Create boxplot
ggplot(data = velocities, aes(x = "", y = velocities)) +
  geom_boxplot(width = 0.5, color = "blue") +
  ggtitle("Air Velocity Boxplot") +
  ylab("Velocity") +
  theme(axis.title.y = element_text(size = rel(1.5)),
        axis.text.y = element_text(size = rel(1.5)))+
  coord_flip()
