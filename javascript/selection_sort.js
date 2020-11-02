function selectionSort(array) {
  let minimalIndex, temp
  const arrayLength = array.length

  for (let i = 0; i < arrayLength; i++) {
    minimalIndex = i

    for (let j = i + 1; j < arrayLength; j++) {
      if (array[j] < array[minimalIndex]) {
        minimalIndex = j
      }
    }

    temp = array[i]
    array[i] = array[minimalIndex]
    array[minimalIndex] = temp
  }
  return array
}

console.log(selectionSort([12, 345, 4, 546, 122, 84, 98, 64, 9]));
