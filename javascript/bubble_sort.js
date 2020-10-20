//Javascript function to implement Bubble Sort [Inplace Sorting Algorithm].
function bubble_Sort(a)
{
    var swapp;
    var n = a.length-1;
    var x=a;
    do {
        swapp = false;
        for (var i=0; i < n; i++)
        {
            if (x[i] < x[i+1])
            {
               var temp = x[i];
               x[i] = x[i+1];
               x[i+1] = temp;
               swapp = true;
            }
        }
        n--;
    } while (swapp);
 return x; 
}
//Sample example to test the function
console.log("Input array:");
console.log("[12, 345, 4, 546, 122, 84, 98, 64, 9]");
console.log("Sorted array using Bubble Sort:");
console.log(bubble_Sort([12, 345, 4, 546, 122, 84, 98, 64, 9]));
