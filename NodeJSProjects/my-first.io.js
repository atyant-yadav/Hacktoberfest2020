const fs = require('fs');
let file = fs.readFileSync(process.argv[2],'utf8');
let lines = file.split('\n').length - 1;
console.log(lines);