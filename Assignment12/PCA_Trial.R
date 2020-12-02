# https://aaronschlegel.me/principal-component-analysis-r-example.html
# https://builtin.com/data-science/step-step-explanation-principal-component-analysis
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

# Extras (Eigen Values and Eigen vectors calculation)
# Calculate corelation of all the attributes
cor_matrix <- cor(winedf[, -1])
sum(diag(cor_matrix))

eigenvals <- eigen(cor_matrix)
eigenvals$vectors


for(a in eigenvals$values){
  print(a / sum(eigenvals$values))
}

plot(eigenvals$values, xlab = "Eigenvalue number", ylab = "Eigenvalue size", 
     main = "Scree Graph")
lines(eigenvals$values)
eigenvals$vectors
