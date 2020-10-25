function calculate_number(x, y, operator) {
  switch (operator) {
    case "-":
      return x - y;
    case "+":
      return x + y;
    case "*":
      return x * y;
    default:
      return x / y;
  }
}
