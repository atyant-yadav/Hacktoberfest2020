import turtle
import math
import time
import random

backtrail = False
choicelist = []
choice = ''
x, y = 0, 0
notvisited = []
visited = []
## width = 31
width = int(input("Enter the value of n less than 31 for a n x n maze : "))
space = 16
speed = 5

for i in range(-5 * width, 5 * width, 10):
    for j in range(5 * width, -5 * width, -10):
        notvisited.append((i * (space / 10), j * (space / 10)))


wn = turtle.Screen()
wn.bgcolor = 'white'
wn.title('PRIYAV\'S MAZE GENERATOR')
wn.tracer(2)

draw = turtle.Turtle()
# draw.speed(0)
draw.penup()
# draw.hideturtle()

draw.goto(-(space / 10) * 5 * width, -(space / 10) * 5 * width)
for i in range(width + 2):
    draw.pendown()
    for j in range(width + 1):
        draw.goto(draw.xcor(), -(space / 10) * 5 * width + (space * j))
    draw.penup()
    draw.goto(-(space / 10) * 5 * width + (space * i), draw.ycor())
draw.goto((space / 10) * 5 * width, (space / 10) * 5 * width)
for i in range(width + 2):
    draw.pendown()
    for j in range(width + 1):
        draw.goto((space / 10) * 5 * width - (space * j), draw.ycor())
    draw.penup()
    draw.goto(draw.xcor(), (space / 10) * 5 * width - (space * i))

# for i in notvisited:
# 	draw.goto(i[0],i[1])
# 	draw.pendown()
# 	draw.color('red')
# 	draw.circle(2)
# 	draw.penup()


def check_avaliability(x, y):
    global current, notvisited, choicelist, backtrail
    if (x - space, y) in notvisited:
        choicelist.append('right')
    if (x, y - space) in notvisited:
        choicelist.append('down')
    if (x + space, y) in notvisited:
        choicelist.append('left')
    if (x, y + space) in notvisited:
        choicelist.append('up')
    if len(choicelist) == 0:
        backtrail = True


def make_random_choice():
    global x, y, choicelist, choice
    no = random.randint(0, len(choicelist) - 1)
    choice = choicelist[no]
    if choice == 'up':
        x = current[0]
        y = current[1] + space
    elif choice == 'down':
        x = current[0]
        y = current[1] - space
    elif choice == 'left':
        x = current[0] + space
        y = current[1]
    elif choice == 'right':
        x = current[0] - space
        y = current[1]


def square(size, turtle):
    turtle.speed(0)
    turtle.begin_fill()
    turtle.fillcolor('grey')
    turtle.right(135)
    turtle.circle(size / math.sqrt(2), 360, 4)
    turtle.left(135)
    turtle.end_fill()
    turtle.color('black')
    turtle.pendown()
    turtle.right(135)
    turtle.circle(size / math.sqrt(2), 360, 4)
    turtle.left(135)
    turtle.speed(1)


def removewall(turtle, choice):
    global current
    turtle.speed(0)
    turtle.penup()
    if choice == 'up':
        turtle.right(90)
        turtle.forward(space)
        turtle.left(90)
        turtle.pendown()
        turtle.pencolor('grey')
        turtle.forward(space)
    elif choice == 'down':
        turtle.pendown()
        turtle.pencolor('grey')
        turtle.forward(space)
    elif choice == 'right':
        turtle.forward(space)
        turtle.right(90)
        turtle.pendown()
        turtle.pencolor('grey')
        turtle.forward(space)
        turtle.left(90)
    elif choice == 'left':
        turtle.right(90)
        turtle.pendown()
        turtle.pencolor('grey')
        turtle.forward(space)
        turtle.left(90)
    turtle.penup()
    turtle.goto(current[0], current[1])
    turtle.speed(1)
    turtle.pencolor('black')


# def backtrailing():
#     global backtrail, current, choicelist, choice, x, y, visited, notvisited
#     if len(notvisited) == 0:
#         finish()
#     else:
#         draw.goto(visited[-2])
#         visited.remove(visited[-1])
#         backtrail = False
#         current = (draw.xcor(), draw.ycor())
#         maintask()


def finish():
    print('Finished')
    wn.mainloop()
    time.delay(3)
    wn.bye()


def maintask():
    global backtrail, current, choicelist, choice, x, y, visited, notvisited
    if len(notvisited) == 0:
        finish()
    else:
        while not backtrail:
            check_avaliability(current[0], current[1])
            if not backtrail:
                make_random_choice()
                draw.goto(x, y)
                square(space, draw)
                current = (x, y)
                removewall(draw, choice)
                draw.pencolor('black')
                choicelist = []
                visited.append(current)
                notvisited.remove(current)
        else:
            draw.goto(visited[-2])
            visited.remove(visited[-1])
            backtrail = False
            current = (draw.xcor(), draw.ycor())
            maintask()


wn.tracer(2)

draw.penup()
draw.ht()
draw.goto(notvisited[0])
draw.speed(speed)
current = notvisited[0]

visited.append(notvisited[0])
notvisited.remove(notvisited[0])

draw.pendown()
draw.color('black')
square(space, draw)

maintask()
