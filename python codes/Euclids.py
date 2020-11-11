# Python program to demonstrate Basic Euclidean Algorithm 


# Function to return gcd of a and b 
def gcd(a, b): 
	if a == 0 : 
		return b 
	
	return gcd(b%a, a) 

a = 10
b = 15
print("gcd(", a , "," , b, ") = ", gcd(a, b)) 

a = 35
b = 10
print("gcd(", a , "," , b, ") = ", gcd(a, b)) 

a = 31
b = 2
print("gcd(", a , "," , b, ") = ", gcd(a, b)) 

# Code Contributed By Mohit Gupta_OMG <(0_o)> 
