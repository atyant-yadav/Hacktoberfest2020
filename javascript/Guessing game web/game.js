//random logic
cmpguess = Math.random(1, 100)
cmpguess = cmpguess * 100
cmpguess = Math.ceil(cmpguess + 1)
var noguess = 0;
//----------

//! working of the web 
var ul = document.getElementsByClassName("great")
var li

var inputfromweb = document.querySelector('.input')
inputfromweb.addEventListener('click', () => {

    var input = document.querySelector('.in')
    var item = input.value

    if (isNaN(item)) {
        alert("Insert a NUMBER")

    } else {
        while (true && noguess < 10) {
            noguess += 1

            if (item < cmpguess) {
                var node = document.createElement("li")
                let texta = document.createTextNode(`Computer's guess is greater than your guess \n`)
                node.appendChild(texta)
                let greatresult = document.querySelector('.great').appendChild(node)
                console.log(greatresult);
                return false

            } else if (item > cmpguess) {
                var node = document.createElement("li")
                let textb = document.createTextNode(`Computer's guess is lesser than your guess \n`)
                node.appendChild(textb)
                let greatresult = document.querySelector('.great').appendChild(node)
                console.log(greatresult);
                return false

            } else if (item == cmpguess) {
                var node = document.createElement("li")
                let textc = document.createTextNode(`\n Correct Answer Total no of guesses :  ${noguess} \n`)
                node.appendChild(textc)
                let greatresult = document.querySelector('.great').appendChild(node)
                console.log(greatresult);
                return false
            }
        }
    }
})