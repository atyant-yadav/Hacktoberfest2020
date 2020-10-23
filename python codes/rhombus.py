WALL = "|"
# Rhombus's size (By * units of measurements), changable.
Radius = 6
inside_space = 1
for line in range(Radius/2):
    spaces = (Radius/2 - line) * " "
    if line < 1:
        stars = "*"
    else:
        stars = "*" + inside_space * " " + "*"
        inside_space += 2
    print(WALL + spaces + stars + spaces + WALL)

for line in range(Radius/2, -1, -1):
    spaces = (Radius/2 - line) * " "
    if line < 1:
        stars = "*"
    else:
        stars = "*" + inside_space * " " + "*"
        inside_space -= 2
    print(WALL + spaces + stars + spaces + WALL)