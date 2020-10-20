//Javascript function to implement Insertion Sort [Inplace Sorting Algorithm].
function insertion_Sort(unsortedData) {
    for (let i = 1; i < unsortedData.length; i++) {
    let current = unsortedData[i];
    let j;
    for(j=i-1; j >= 0 && unsortedData[j] > current;j--) {
    unsortedData[j + 1] = unsortedData[j] }
    unsortedData[j + 1] = current;
    }
    return unsortedData;
    }    
//Sample example to test the function
console.log("Input array:");
console.log("[12, 345, 4, 546, 122, 84, 98, 64, 9]");
console.log("Sorted array using Insertion Sort:");
console.log(insertion_Sort([12, 345, 4, 546, 122, 84, 98, 64, 9]));    