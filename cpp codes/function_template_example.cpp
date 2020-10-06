// Function Template
#include <iostream>
using namespace std;
template <typename T>
T getSum(T a, T b)
{
    return (a + b);
}

int main()
{
    cout << "Sum of two integers 50 and 63 is " << getSum<int>(50, 63) << endl;

    cout << "Sum of two floats 5.3 and 6.3 is " << getSum<float>(5.3f, 6.3f) << endl;

    cout << "Sum of two doubles 5.0356 and 6.3256 is " << getSum(5.0356, 6.3256) << endl;

    return 0;
}