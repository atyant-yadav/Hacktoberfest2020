const net = require('net');
let date = new Date();
const server = net.createServer((socket)=>{
    //socket logig
    let mese = convertMonth(date.getMonth());
    socket.write(date.getFullYear()+'-'+mese+'-'+date.getDate()+' '+date.getHours()+':'+date.getMinutes());
    socket.end('\n');
}).on('error', (err)=>{
    throw err;
})
server.listen(process.argv[2])
function convertMonth(dat){
    let month = ''
    switch(dat){
        case 0: month = '01';
                break;
        case 1: month = '02';
                break;
        case 2: month = '03';
                break;
        case 3: month = '04';
                break;
        case 4: month = '05';
                break;
        case 5: month = '06';
                break;
        case 6: month = '07';
                break;
        case 7: month = '08';
                break;
        case 8: month = '09';
                break;
        
                

    }

    return month;

    function zeroFill (i) {
        return (i < 10 ? '0' : '') + i
      }
}
