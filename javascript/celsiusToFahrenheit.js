const celsiusToFahrenheit = (celsius) => (
  Math.round((celsius * (9 / 5) + 32) * 100) / 100
);

const celsius = 1;

const fahrenheit = celsiusToFahrenheit(1);
console.log(fahrenheit); // 33.8
