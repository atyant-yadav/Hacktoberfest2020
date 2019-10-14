let array = [1, 2, 3, 4, 5, 'two', 'jesse'];

array.push(21);
array.unshift('text');

//Playing around with forEach loop in JS
array.forEach(element => {
    num = 0;
    num++;
    array.push(num);
    console.log(element);
});

//For in Loop
for (const key in array) {
        console.log(key);
        
    }


console.log(array);