#LCM of two numbers


a,b=int(input()),int(input()) #Read the inputs

greater=max(a,b)    #Minimum lcm value

for i in range(greater,a*b+1):#Loop from minimum value to maximum which is product of the two numbers
    if i%a==0 and i%b==0:  
        lcm=i
        break       #Break out of the loop once the first divisible value is encountered

print(lcm)  #print the value
