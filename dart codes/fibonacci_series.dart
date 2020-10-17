import 'dart:io';

void main() {
  int number = 20;

  stdout.write("Number           : ${number}\n");
  stdout.write("Fibonacci series : ");
  
  for (int counter = 0; counter < number; counter++) {
    stdout.write(fibonacci(counter));
    stdout.write(" ");
  }
}

int fibonacci(int number) {
  if (number == 0 || number == 1)
    return number;
  else
    return fibonacci(number - 1) + fibonacci(number - 2);
}