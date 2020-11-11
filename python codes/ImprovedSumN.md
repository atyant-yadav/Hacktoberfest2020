# Improved Sum of n Numbers 

This readme file will focus on the Algorithmic Analysis of this program. The following 2 algorithms will be analysed: 

Sum of N using For Loop  

Sum of N without using For Loop

## Sum of N using For Loop  

When all of us learnt for loops in our computer science course, we all automatically learnt the sum of n numbers program using for loop. The algorithm looks like this 

 

``` General Algorithm
int SumNTraditional (int n): 
    sum = 0  
    for i in 1 to n:   <---- n
        sum += i   <-------- 1
    return sum
```

Here the time complexity:

<img src="https://latex.codecogs.com/gif.latex?Time\:Complexity&space;=&space;n(1)" title="Time\:Complexity = n(1)" />

<img src="https://latex.codecogs.com/gif.latex?=&space;O(n)" title="= O(n)" />

## Sum of N without using For Loop

Have you thought about improving the above algorithm to achieve O(1)? Its as simple as applying the summation formula: 

<img src="https://latex.codecogs.com/gif.latex?\sum&space;_{i=1}^{n}i={\frac&space;{n(n&plus;1)}{2}}" title="\sum _{i=1}^{n}i={\frac {n(n+1)}{2}}" />

``` General Algorithm
int SumNImproved (int n): 
    val = 0.5*n*(n+1)   <--- 1
    return val 
```

Here the time complexity: 

<img src="https://latex.codecogs.com/gif.latex?Time\:Complexity&space;=&space;1" title="Time\:Complexity = 1" />

<img src="https://latex.codecogs.com/gif.latex?=&space;O(1)" title="= O(1)" />

