import math

print("Minkowski Distance Calculator")
print("Please read the readme before using this software.")


X_RAW = input("Enter values of X space-separated (x1 x2 ... xn): ")
Y_RAW = input("Enter values of Y space-separated (y1 y2 ... yn): ")

# Manipulate the X and Y
# Convert to List of String
listX = X_RAW.strip().split(' ')
listY = Y_RAW.strip().split(' ')

# Throw an error if both lists are not equal
if len(listX) != len(listY):
    print("Error, X and Y must have same number of elements")
    exit()

# Convert to Float List
X=[]
Y=[]
for xi, yi in zip(listX, listY):
    X.append(float(xi))
    Y.append(float(yi))

# Get the Order (p)
p = float(input("Enter order (p) (Type 2 for Euclidean Distance): "))

# Calculate the Minkowski Distance
sum_XY = 0.0
for xi, yi in zip(X, Y):
    diff_xy = math.fabs(xi-yi)
    sum_XY = sum_XY + math.pow(diff_xy, p)
res = math.pow(sum_XY, 1/p)

print("Minkowski Distance = %f" % res)
