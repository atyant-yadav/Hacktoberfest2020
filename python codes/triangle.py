# Lines count, changable.
PYRAMID_HEIGHT = 6
WALL = "|"
for line in range(1, PYRAMID_HEIGHT+1):
    print(WALL + "*" * line + " " * (PYRAMID_HEIGHT - line) + WALL) 