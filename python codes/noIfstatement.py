TABLE = {
    (lambda x: x <= 2, 'Junior'),
    (lambda x: 1 < x <= 6, 'Semi Senior'),
    (lambda x: x < 12, 'Senior'),
    (lambda x: True, 'N/A'),
}


def fn(years):
    for check, category in TABLE:
        if check(years):
            return years, category


print(fn(7))