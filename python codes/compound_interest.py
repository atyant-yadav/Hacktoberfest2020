print ("Enter the principal amount: ")
principal = float(input())
print ("Enter the time of investment: ")
time = float(input())
print ("Enter the rate of interest: ")
rate = float(input())/100
print ("Enter the number of times interest is calculated in a year: ")
n = float(input())
CompoundInterest = (principal * pow((1 + rate),(n*time))) - principal
FinalAmount = principal + CompoundInterest
print ("Compound Interest = : "+str(CompoundInterest))
print ("Final Amount : "+str(FinalAmount))
