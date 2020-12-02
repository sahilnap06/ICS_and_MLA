setwd("E:/College/CL7/Assignment12")
winedf <- read.csv("../Datasets/wine.csv")

head(winedf)

# Calculate Correlation of all attributes
cor_mat <- cor(winedf[, -1])
cor_mat

WPCA <- princomp(winedf[, -1], cor = T, scores = T, covmat = NULL)

summary(WPCA)

plot(WPCA)

loadings(WPCA)
plot(WPCA, t='l')
screeplot(WPCA, type="line", main="Scree plot")
biplot(WPCA)
WPCA$scores[1:10, 1]

attributes(WPCA)
