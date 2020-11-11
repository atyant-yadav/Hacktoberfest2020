const fs = require('fs');
const path = require('path');
const dirpath = process.argv[2];
const ext = `.${process.argv[3]}`;
fs.readdir(dirpath, (err,files)=>{
    if(err) throw console.error(err);
    files.forEach((file)=>{
        if(path.extname(file)== ext){
            console.log(file);
        }
    });
    
    });

