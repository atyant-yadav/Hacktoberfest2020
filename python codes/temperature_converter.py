def convert_celsius_to_fahrenheit(celsius):
    fahrenheit = (9.0/5.0) * (celsius) + 32
    return fahrenheit
celsius = int(input("Enter a temperature in Celsius: "))  
print("Temperature:" + str(celsius) + " °C " + "Fahrenheit = " + str(convert_celsius_to_fahrenheit(celsius)) + " F")
