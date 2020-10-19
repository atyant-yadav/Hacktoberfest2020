const http=require('http');
const bl = require('bl');
const risultati =[]; 
let count=0;
function printRis(){
    for (let i = 0; i < 3; i++) {
        console.log(risultati[i])
      }
}
function httpGet(index){
    http.get(process.argv[2+index], (res)=>{
        res.pipe(bl((err,data)=>{
            if(err) throw err;
            risultati[index]=data.toString();
            count++;
            if(count === 3){
                printRis();
            }
        }))
    })
}

for(let i =0;i < 3; i++){
    httpGet(i);
}

