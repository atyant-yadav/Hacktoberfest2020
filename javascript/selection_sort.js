function selectionSort(inputArray) {

	for (let i = 0; i < inputArray.length; i++) {
	// get the minimum value -> minValue in the subarray
		let minValue = i;
		for (let j = i + 1; j < inputArray.length; j++) {
			if (inputArray[j] < inputArray[minValue]) {
				minValue = j;
			}
		}
		if (minValue != i) {
		// Swap the elements
			let temp = inputArray[i];
			inputArray[i] = inputArray[minValue];
			inputArray[minValue] = temp;
		}
	}
	return inputArray;
}

let inputArray = [1,8,3,7,9,3,6,5];
selectionSort(inputArray);
console.log(inputArray); // results [1, 3, 3, 5, 6, 7, 8, 9]
