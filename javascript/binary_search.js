//Javascript function to implement Binary Search 

//Binary Search takes only SORTED array in input
function binarySearch(sortedArray, key) {
    var lowIndex = 0;
    var highIndex = sortedArray.length - 1;
    while (lowIndex <= highIndex) {
      var midIndex = Math.floor((lowIndex + highIndex) / 2);
      if (sortedArray[midIndex] == key) {
        return midIndex;
      } else if (sortedArray[midIndex] < key) {
        lowIndex = midIndex + 1;
      } else {
        highIndex = midIndex - 1;
      }
    } return null;
  }


//Sample example to test the function
var rainbow = ["red", "orange", "yellow", "green", "blue", "indigo", "violet"];
var sortedRainbow = rainbow.sort(); 
// returns ["blue", "green", "indigo", "orange", "red", "violet", "yellow"];

var sortedRainbow = ["blue", "green", "indigo", "orange", "red", "violet", "yellow"];
console.log(binarySearch(sortedRainbow, "green")); // returns 1
console.log(binarySearch(sortedRainbow, "white")); // returns null
