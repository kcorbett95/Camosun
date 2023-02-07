#set working directory to the folder where bears.txt is located
setwd("/Users/Kev/Downloads")
bears <- read.table("bears.txt", header = TRUE)

#print first 6 lines of the dataset
head(bears, 6)

#calculate mean age of bears
mean_age <- mean(bears$Age)
print(paste("Mean age: ", mean_age))

#calculate variance of headwidth
var_headwidth <- var(bears$Headwidth)
print(paste("Variance of headwidth: ", var_headwidth))

#create a side-by-side box plot to compare weight of bears separated by gender
boxplot(Weight~Gender,data=bears,main="K. Corbett: Weight of Bears by Gender",xlab="Gender",ylab="Weight",col="blue",border="black")

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
print(paste("Median velocity: ", median_velocity))

# Determine if data is symmetric, skewed left, or skewed right
if(mean_velocity == median_velocity){
  print("Data is symmetric")
} else if(mean_velocity < median_velocity){
  print("Data is skewed left")
} else {
  print("Data is skewed right")
}

# Create histogram
hist(velocities,main="K. Corbett: Air Velocity Histogram",col="light blue")

# Calculate standard deviation and IQR
std_velocity <- sd(velocities)
print(paste("Standard Deviation: ",std_velocity))
iqr_velocity <- IQR(velocities)
print(paste("IQR: ",iqr_velocity))

# Create boxplot
boxplot(velocities,main="K. Corbett: Boxplot of Air Velocities",xlab="Velocity",col="blue",border="black",horizontal=TRUE)