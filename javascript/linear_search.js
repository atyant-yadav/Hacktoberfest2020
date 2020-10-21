//Javascript function to implement Linear Search 
function linearSearch(arr, key) {
    for (var i=0; i<arr.length; i++) {
      if (arr[i] == key) {
        return i;
      }
    } return null;
  }


  //Sample example to test the function
  var rainbow = ["red", "orange", "yellow", "green", "blue", "indigo", "violet"];
  console.log(linearSearch(rainbow, "green")); // returns 3
  console.log(linearSearch(rainbow, "white")); // returns null   