WALL = "|"

def cover_with_walls(string):
    """
    Covers a given string with 'walls'
    @param string The string to cover.
    @return the string covered.
    """
    return WALL + string + WALL

# Amount of stars in a square's edge.
SQUARE_EDGE_STARS_AMOUNT = 6
print(cover_with_walls("_" * SQUARE_EDGE_STARS_AMOUNT))
print(cover_with_walls(SQUARE_EDGE_STARS_AMOUNT * "*"))
for line in range(SQUARE_EDGE_STARS_AMOUNT-2):
    spaces = (SQUARE_EDGE_STARS_AMOUNT-2) * " "
    print(cover_with_walls("*" + spaces + "*"))
print(cover_with_walls(SQUARE_EDGE_STARS_AMOUNT * "*"))
print(cover_with_walls("-" * SQUARE_EDGE_STARS_AMOUNT))