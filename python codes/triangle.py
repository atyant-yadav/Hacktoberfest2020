print('Enter triangle height:')
height = input()
for level in xrange(height):
    output = ''
    for space in xrange((height-1)-level):
        output += ' '
    for star in xrange((level*1)+(level+1)):
        output += '*'
    print(output)