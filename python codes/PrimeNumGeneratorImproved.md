# Improved Prime Number Generator 

This readme file will focus on the Algorithmic Analysis of this program. There are 2 parts to the analysis: 

1. ```isPrime()``` function 
2. main program

## isPrime() 

I will explain the traditional algorithm and the improved algorithm (the one I used) here. 

### Traditional isPrime() 

Everyone learnt the basic algorithm to create a function that returns True or False for a given number if it is prime or not. The usual algorithm that would be taught is as follows: 

```General Algorithm
isPrime(int n): 
	for i in 2 to n:   <---------- n-1
		if n%i == 0:   <---------- 1
			Not Prime Number
			break   <------------- 1
	else: 
		Prime Number   <---------- 1
```

#### Time Complexity 

<img src="https://latex.codecogs.com/gif.latex?Time&space;Complexity&space;=&space;(n-1)(1)&plus;&space;1&space;&plus;&space;1" title="Time Complexity = (n-1)(1)+ 1 + 1" />

<img src="https://latex.codecogs.com/gif.latex?=&space;O(n)" title="= O(n)" />

### Improved isPrime() 

Have you wondered about the fact that in the traditional algorithm, there were a lot of redundant calculations? If we omit all the modulo calculations after the square root of that given number, we can prevent those redundant calculations. The algorithm is below (only the n is replaced with sqrt(n)): 

```General Algorithm
isPrime(int n): 
	for i in 2 to sqrt(n):
		if n%i == 0:
			Not Prime Number
			break
	else: 
		Prime Number
```

#### Non-Prime Example

Take a look at this example where n = 12: 

So, sqrt(12) is approximately 3.464, we take it as 3 

1*12 = 12

2*6 = 12

3*4 = 12

From this, we can deduce that the numbers after 3 are redundant as they will yield the same results as earlier calculations 

(example, 

4 * 3 = 3 * 4 if we crossed 3 and went on to 4, 

or 6 * 2 = 2 * 6 if we continue till 6). 

If we are calculating factors, we would stop at 3 itself as we obtained the remaining factors automatically. We do not calculate any numbers after 3. 

#### Prime Example 

For the next example, we take n = 37

So, sqrt(37) is approximately 6.083, we take floor value 6. 

The following calculations will be performed: 

37%2, 37%3, 37%4, 37%5, 37%6     <- (6 calculations) 

Instead of:

37%2, 37%3, ... , 37%36     <- (36 calculations) 

We have cut down on the unnecessary calculations after 6 because we know that if there are no factors below 6, there wont be any factors after that. 

If you still cannot understand, try this with a calculator to divide 37 by 2, all the way till 6. after 6, your result will be below 6 which indicates redundant calculations. 

#### Time Complexity

The Time Complexity Explained: 

```General Algorithm
isPrime(int n): 
	for i in 2 to sqrt(n):   <---- sqrt(n) - 1
		if n%i == 0:   <---------- 1
			Not Prime Number
			break   <------------- 1
	else: 
		Prime Number   <---------- 1
```

<img src="https://latex.codecogs.com/gif.latex?Time&space;Complexity&space;=&space;(\sqrt&space;n&space;-1)(1)&space;&plus;&space;1&space;&plus;&space;1" title="Time Complexity = (\sqrt n -1)(1) + 1 + 1" />

<img src="https://latex.codecogs.com/gif.latex?=&space;O(\sqrt&space;n)" title="= O(\sqrt n)" />

## Main Program 

The main program take user input and calculated prime numbers within the range. For each number, the ```isPrime()``` function is called and according to the return value, the prime number is printed. The algorithm is below: 

```
n = input()
for i in 1 to n:   <-------------- n
	if isPrime():   <------------- sqrt(n)
		print i   <--------------- 1
```

<img src="https://latex.codecogs.com/gif.latex?Time&space;Complexity&space;=&space;(n)\sqrt&space;n&space;(1)" title="Time Complexity = (n)\sqrt n (1)" />

<img src="https://latex.codecogs.com/gif.latex?=&space;O(n&space;\sqrt&space;n)" title="= O(n \sqrt n)" />     or    <img src="https://latex.codecogs.com/gif.latex?=&space;O(n^\frac{3}{2})" title="= O(n^\frac{3}{2})" />