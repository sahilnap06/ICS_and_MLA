library("Metrics")
library("DAAG")
library("lattice")
library("leaps")
library("ISLR")
setwd("E:/College/CL7/Assignment6")
#dataset<-dataset("advertising.csv")
dataset <- read.csv("./advertising.csv")

head(dataset)
dim(dataset) # Dimensions of the dataset

#Divide the dataset into training and testing
train_dataset=dataset[1:120,]
head(train_dataset)

test_dataset=dataset[121:200,]
head(test_dataset)

# Columns for binding for predictioin
S=cbind("TV","Newspaper","Radio")

# Linear regression using Least Square method on TV
TV_Train=lm(Sales~TV,data=train_dataset)
TV_Train
  # Display the attributes of Linear regression of TV
attributes(TV_Train)
TV_Train$coefficients[1]
TV_Train$coefficients[2]

# Linear regression using Least Square method on Radio
Radio_train=lm(Sales~Radio,data=train_dataset)
Radio_train
  # Display the attributes of Linear regression of Radio
attributes(Radio_train)
Radio_train$coefficients[1]
Radio_train$coefficients[2]

# Linear regression using Least Square method on Newspapers
Np_train=lm(Sales~Newspaper,data=train_dataset)
Np_train
  # Display the attributes of Linear regression of Radio
attributes(Np_train)
Np_train$coefficients[1]
Np_train$coefficients[2]

# Plotting graphs of parts of dataset vs sales
plot(train_dataset$Sales~train_dataset$TV,xlab="TV",ylab = "Sales")
abline(TV1, col="blue")

plot(train_dataset$Sales~train_dataset$Radio,xlab="Radio",ylab = "Sales")
abline(Radio_train, col="red")

plot(train_dataset$Sales~train_dataset$Newspaper,xlab="Newspaper",ylab="Sales")
abline(Np_train, col="yellow")

summary(TV1)

tidy(TV1)

Tvp=predict(TV1,train_dataset)
Radiop=predict(Radio_train,train_dataset)
Newspaperp=predict(Np_train,train_dataset)

# Predict on the test data-set
Tvt=predict(TV1,test_dataset)
Radiot=predict(Radio_train,test_dataset)
Newspapert=predict(Np_train,test_dataset)

#  Finding mean square error on Training dataset
TVtrain_mse=mse(train_dataset$Sales,Tvp)
TVtrain_mse

Radiotrain_mse=mse(train_dataset$Sales,Radiop)
Radiotrain_mse

Newspapertrain_mse=mse(train_dataset$Sales,Newspaperp)
Newspapertrain_mse

#  Finding mean square error on testing dataset
TVtest_mse=mse(test_dataset$Sales,Tvt)
TVtest_mse

Radiotest_mse=mse(test_dataset$Sales,Radiot)
Radiotest_mse

Newspapertest_mse=mse(test_dataset$Newspaper,Newspapert)
Newspapertest_mse

# Combines the arguments to form a vector
TrainMSE=c(TVtrain_mse,Radiotrain_mse,Newspapertrain_mse)
TrainMSE

TestMSE=c(TVtest_mse,Radiotest_mse,Newspapertest_mse)
TestMSE

barplot(TrainMSE,width = 0.02,xlab="data",ylab="error",main="Training Error")
barplot(TestMSE,width=0.02,xlab = "data",ylab="error",main="Testing Error")

model1=cv.lm(dt,(Sales~TV),m=5)

# Using Subset selection method
regfit_full = regsubsets(Sales~., data= test_dataset)
reg_summary = summary(regfit_full)
reg_summary$rsq

# Set up a 2x2 grid so we can look at 4 plots at once
par(mfrow = c(2,2))
plot(reg_summary$rss, xlab = "Number of Variables", ylab = "RSS", type = "l")
plot(reg_summary$adjr2, xlab = "Number of Variables", ylab = "Adjusted RSq", type = "l")
# We will now plot a red dot to indicate the model with the largest adjusted R^2 statistic.
# The which.max() function can be used to identify the location of the maximum point of a vector
adj_r2_max = which.max(reg_summary$adjr2) # 11

# The points() command works like the plot() command, except that it puts points
# on a plot that has already been created instead of creating a new plot
points(adj_r2_max, reg_summary$adjr2[adj_r2_max], col ="red", cex = 2, pch = 20)

# We'll do the same for C_p and BIC, this time looking for the models with the SMALLEST statistic
plot(reg_summary$cp, xlab = "Number of Variables", ylab = "Cp", type = "l")
cp_min = which.min(reg_summary$cp) # 10
points(cp_min, reg_summary$cp[cp_min], col = "red", cex = 2, pch = 20)

plot(reg_summary$bic, xlab = "Number of Variables", ylab = "BIC", type = "l")
bic_min = which.min(reg_summary$bic) # 6
points(bic_min, reg_summary$bic[bic_min], col = "red", cex = 2, pch = 20)
