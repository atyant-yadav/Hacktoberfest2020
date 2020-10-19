const fs = require('fs');
let lines = 0;
fs.readFile(process.argv[2],'utf8',(err,data)=>{
    if(err) throw err;
    lines = data.split('\n').length -1;
    console.log(lines);
    
});
