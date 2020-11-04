const selection_sort = (arr) => {
  let minIndex;
  let temp;
  for (let i = 0; i < arr.length; i++) {
    minIndex = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[minIndex]) minIndex = j;
    }
    if (minIndex !== i) {
      // swap
      temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
  return arr;
};

console.log(selection_sort([12, 345, 4, 546, 122, 84, 98, 64, 9]));
