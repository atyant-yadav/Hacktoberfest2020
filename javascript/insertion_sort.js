let insertionSort = (arr) => {
    for (let i = 1; i < arr.length; i++) {
        let current = arr[i];
        let j;
        for ( j = i-1; j >= 0 && arr[j]> current; j--){
        arr[j+1] = arr[j];
        }
            
        arr[j+1] = current;
    }
    return arr;
}

let arr =  [1,8,3,7,9,3,6,5];

console.log(insertionSort(arr))
