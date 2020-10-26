WALL = "|"
# Rhombus's size (By * units of measurements), changable.
Radius = 2
inside_space = 1
for line in range(0, (Radius/2)-1):
    spaces = (Radius/2 - line) * " "
    if line < 1:
        stars = (Radius * "*") + " "
    else:
        stars = "*" + ((inside_space + Radius) * " ") + "*"
        inside_space += 2
    print(WALL + spaces + stars + spaces + WALL)

if Radius > 2:
    for line in range(1, Radius):
        print(WALL + " *" + (" " * ((Radius/2) + Radius)) + "* " + WALL)

    for line in range(Radius/2-1, -1, -1):
        spaces = (Radius/2 - line) * " "
        if line < 1:
            stars = (Radius * "*") + " "
        else:
            stars = "*" + ((inside_space + Radius) * " ") + "*"
            inside_space -= 2
        print(WALL + spaces + stars + spaces + WALL)
else:
    print(WALL + " * " + WALL)