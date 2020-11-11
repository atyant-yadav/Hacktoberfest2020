const http = require('http');
let url = process.argv[2];
http.get(url, (res)=>{
    const {statusCode} = res;
    const contentType = res.headers['content-type'];
    
    res.setEncoding('utf8');
    res.on('data', (data)=>{
        console.log(data);
    })
    res.on('error', (error)=>console.error(error))
})
