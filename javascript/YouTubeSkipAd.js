let skipbtn = document.getElementsByClassName("ytp-ad-skip-button ytp-button");
setInterval(() => {
if(skipbtn && skipbtn.length > 0){
skipbtn[0].click();
}
}, 500)
