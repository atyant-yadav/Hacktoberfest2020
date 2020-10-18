import os
from random import randint, seed

seed(525)

print('Pick a number between 1 and 1000')
x = input()

my_num = randint(0, 1000)

print('My number is ' + my_num)
print('I was kinda close right?')


