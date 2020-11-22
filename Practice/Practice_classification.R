# https://www.pluralsight.com/guides/encoding-data-with-r
# Importing libraries
library("Metrics")
library(lattice)
library("DAAG")
library(leaps)
library(dplyr)
library(tidyr)
library(ggplot2)

# Set working directory and read the data
setwd("E:/College/CL7/Practice/")
data <- read.csv("bank-full.csv", header = T)

# Observe data
head(data)
dim(data)
summary(data)

# Cleaning data
# 1. Removing outliers in age
clean_data <- data
outliers <- boxplot(data$age)$out
  # Taking 98.9 percentile of age
quant = quantile(data$age, c(0.989))
clean_data$age[clean_data$age > quant] <- quant
boxplot(clean_data$age)
# Need to check in balance
# y is the final outcome, so we will use label encoding
clean_data$y <- ifelse(clean_data$y == "yes", 1, 0)

# similarly for housing and default
clean_data$housing <- ifelse(clean_data$housing == "yes", 1, 0)
clean_data$default <- ifelse(clean_data$default == "yes", 1, 0)

  # Cleaning the balance
outliers1 = boxplot(clean_data$balance)$out
quant1 = quantile(data$balance, c(0.95))
clean_data$balance[clean_data$balance > quant1] <- quant1
  
  # cleaning the duration
outliers2 = boxplot(clean_data$duration)$out
quant2 <- quantile(clean_data$duration, c(0.95))
clean_data$duration[clean_data$duration > quant2] <- quant2

  # Cleaning the campaign
outliers3 = boxplot(clean_data$campaign)$out
quant3 <- quantile(clean_data$campaign, c(0.95))
clean_data$campaign[clean_data$campaign > quant3] <- quant3

  #Cleaning pdays
outliers4 <- boxplot(clean_data$pdays)$out
quant4 = quantile(clean_data$pdays, c(0.95))
clean_data$pdays[clean_data$pdays > quant4] <- quant4

  # cleaning previous
outliers5 <- boxplot(clean_data$previous)$out
quant5 <- quantile(clean_data$previous, c(0.95))
clean_data$previous[clean_data$previous > quant5] <- quant5

summary(clean_data)

## Removing NA values
clean_data <- na.exclude(clean_data)

#install.packages("mltools")
library(mltools)
#install.packages("data.table")
library(data.table)
 
# Categorical variables into One Hot encoding
clean_data <- one_hot(as.data.table(clean_data), cols="job", sparsifyNAs=F, naCols=F, dropCols=T, dropUnusedLevels=F)

