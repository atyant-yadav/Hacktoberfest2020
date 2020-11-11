const http = require('http')
const bl = require('bl')

http.get(process.argv[2], (res)=> {
  res.pipe(bl( (err, data) =>{
    if (err) throw err;
    data = data.toString()
    console.log(data.length)
    console.log(data)
  }))
})