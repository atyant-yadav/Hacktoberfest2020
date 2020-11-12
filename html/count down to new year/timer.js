var total;
var date = new Date();
var year = date.getFullYear()+1;
document.querySelector("#year").innerHTML = year;

var target = new Date("Jan 1,"+year+" 00:00:00").getTime();
console.log(target);

var x = setInterval(function() {

    var now = new Date().getTime();
    var distance = target - now;

    var days = Math.floor(distance / (1000 * 60 * 60 * 24));
    var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
    var seconds = Math.floor((distance % (1000 * 60)) / 1000);

    document.querySelector("#days").innerHTML = days;
    document.querySelector("#hours").innerHTML = hours;
    document.querySelector("#minutes").innerHTML = minutes;
    document.querySelector("#seconds").innerHTML = seconds;

    let progressCircle1 = document.querySelector(".dprogress");
    let progressCircle2 = document.querySelector(".hprogress");
    let progressCircle3 = document.querySelector(".mprogress");
    let progressCircle4 = document.querySelector(".sprogress");
    let radius = progressCircle1.r.baseVal.value;
    //circumference of a circle = 2πr;
    let circumference = radius * 2 * Math.PI;
    progressCircle1.style.strokeDasharray = circumference;
    progressCircle2.style.strokeDasharray = circumference;
    progressCircle3.style.strokeDasharray = circumference;
    progressCircle4.style.strokeDasharray = circumference;

    setDayProgress(days);
    setHourProgress(hours);
    setMinuteProgress(minutes);
    setSecondProgress(seconds);
    
    function setDayProgress(percent) {
        if(date.getFullYear() % 4 == 0){
            total = 366;
        }else{
            total = 365;
        }
        progressCircle1.style.strokeDashoffset = circumference - ((total - percent) / total) * circumference;
    }
    function setHourProgress(percent) {
        progressCircle2.style.strokeDashoffset = circumference - ((24 - percent) / 24) * circumference;
    }
    function setMinuteProgress(percent) {
        progressCircle3.style.strokeDashoffset = circumference - ((60 - percent) / 60) * circumference;
    }
    function setSecondProgress(percent) {
        progressCircle4.style.strokeDashoffset = circumference - ((60 - percent) / 60) * circumference;
    }

}, 1000);
