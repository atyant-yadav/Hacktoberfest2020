//Javascript function to implement Selection Sort [Inplace Sorting Algorithm].
function selection_Sort(arr){
    var minIdx, temp, 
        len = arr.length;
    for(var i = 0; i < len; i++){
      minIdx = i;
      for(var  j = i+1; j<len; j++){
         if(arr[j]<arr[minIdx]){
            minIdx = j;
         }
      }
      temp = arr[i];
      arr[i] = arr[minIdx];
      arr[minIdx] = temp;
    }
    return arr;
  }
//Sample example to test the function
    console.log("Input array:");
    console.log("[12, 345, 4, 546, 122, 84, 98, 64, 9]");
    console.log("Sorted array using Selection Sort:");
    console.log(selection_Sort([12, 345, 4, 546, 122, 84, 98, 64, 9]));