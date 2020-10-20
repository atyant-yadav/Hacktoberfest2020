#include <stdio.h>
int main() {
    char operator;
    double first, second, res;
    printf("Enter an operator (+, -, *,): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &first, &second);

    switch (operator) {
    case '+':
        res = first + second;
        break;
    case '-':
        res = first - second;
        break;
    case '*':
        res = first * second;
        break;
    case '/':
        res = first / second;
        break;
        // operator doesn't match any case constant
    default:
        printf("Error! operator is not correct");
    }
    printf("%.1lf %c %.1lf = %.1lf", first, operator, second, res);
    return 0;
}
