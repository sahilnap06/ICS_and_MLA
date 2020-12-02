# Importing the libraries
library("arules")
library('arulesViz')
library('tidyverse')
library('knitr')
library('lubridate')
library('plyr')
library('dplyr')
library('datasets')
setwd("E:/College/CL7/Assignment7")
# Read the data-set
pd <- read.transactions("./groceries.csv",sep=',', header = F)
inspect(pd[1:10,])

# Summary of the dataset
summary(pd)

options(repr.plot.width = 10, repr.plot.height = 8)
itemFrequencyPlot(pd, support = .001, topN = 50, col="lightgreen", xlab = "Item name", 
                  ylab = " Frequency (relative)", main = "Top 50 items with 0.001 support (relative)")

itemFrequencyPlot(pd, topN = 15, col="lightblue", xlab = "Item name", type = "absolute", 
                  ylab = " Frequency (Absolute)", main = "Top 15 items (absolute frequency)")

pd_rules = apriori(pd, parameter = list(support = 0.001, confidence = 0.8, minlen = 2))
summary(pd_rules)
inspect(sort(pd_rules, by="lift"))
plot(pd_rules)
plot(pd_rules,method="grouped", jitter = 0)
plot(pd_rules,method="graph")
plot(pd_rules, method="graph", control=list(layout=igraph::in_circle()))

# Sorting the rules by confidence value
rules = sort(pd_rules, by = "confidence")
options(digits = 2)
inspect(rules)

# removing redundant rules
inspect(rules[is.redundant(rules)])
rules = rules[!is.redundant(rules)]
inspect(rules[1:5])

rules1 = apriori(pd, parameter = list(support = 0.001, confidence = 0.8, minlen = 2),
                appearance = list(default = "lhs", rhs = "whole milk"))
options(digits = 2)
inspect(rules1)

# plot(rules1, method = "graph", engine = "interactive")
plot(rules1, method = "paracoord")
plot(rules1, method = "matrix", control = list(reorder = "none"))
plot(rules1, jitter = 0)

