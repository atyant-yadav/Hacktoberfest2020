// Two simple implementations of the Euclidean algorithm, both recursive and iterative

#include <stdio.h>

int recursive_euclides(int a, int b)
{
    if (a == b)
    {
        return a;
    } else if (a > b)
    {
        return recursive_euclides(a - b, b);
    } else
    {
        return recursive_euclides(a, b - a);
    }
}

int iter_euclides(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        } else if (a < b)
        {
            b = b - a;
        }
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int a = 25;
    int b = 20;
    printf("The GCD of %d and %d is %d\t(recursive attempt)\n", a, b, recursive_euclides(a, b));
    printf("The GCD of %d and %d is %d\t(iterative attempt)\n", a, b, iter_euclides(a, b));
    return 0;
}
