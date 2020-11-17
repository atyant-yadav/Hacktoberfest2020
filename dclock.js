function start() {
    var today = new Date();
    var h = today.getHours();
    var m = today.getMinutes();
    var s = today.getSeconds();
    m = correctTime(m);
    s = correctTime(s);
    document.getElementById('clock').innerHTML = h + ":" + m + ":" + s;
    var t = setTimeout(start, 1000);
}
function correctTime(i) {
    if (i < 10) {
        i = "0" + i;
    }
    return i;
}