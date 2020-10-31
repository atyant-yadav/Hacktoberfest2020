a = prompt("Enter a number");
if (isNaN(a))
    document.write("Please input a valid number");
else {
    let i = Number(a);
    let fact = 1;
    do {
        fact = fact * i;
        i--;
    }
    while (i > 0)
    document.write(`Factorial of ${a} is ${fact}`);
}