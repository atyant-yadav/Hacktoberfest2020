#pragma once
#include<cmath>
extern int answer;
double Add(double a, double b)
{
	answer = a + b;
	return answer;
}
double Subtract(double a, double b)
{
	answer = a - b;
	return answer;
}
double Divide(double a, double b)
{
	answer = a / b;
	return answer;
}
double Multiply(double a, double b)
{
	answer = a * b;
	return answer;
}
double takeMod(int a, int b)
{
	answer = a % b;
	return answer;
}
double takePower(double a, double b)
{
	answer = pow(a, b);
	return answer;
}
double takeSquareRoot(double a)
{
	answer = sqrt(a);
	return answer;
}