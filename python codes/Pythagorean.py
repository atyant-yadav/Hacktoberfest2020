from math import sqrt

side = input('Which side a, b, c : ')

if side == 'c':
	a = int(input('Input the length of side a: '))
	b = int(input('Input the length of side b: '))

	c = sqrt(a * a + b * b)

	print('side c is: ' )
	print(c)

elif side == 'a':
    b = int(input('Input the length of side b: '))
    c = int(input('Input the length of side c: '))

    a = sqrt((c * c) - (b * b))

    print('side a is' )
    print(a)

elif side == 'b':
    a = int(input('Input the length of side a: '))
    c = int(input('Input the length of side c: '))

    b = sqrt(c * c - a * a)

    print('side b is')
    print(b)

else:
	print('Please select a side a, b, c')
