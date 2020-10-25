function swap(items, leftIndex, rightIndex) {
  const temp = items[leftIndex];
  items[leftIndex] = items[rightIndex];
  items[rightIndex] = temp;
}
function partition(items, left, right) {
  const pivot = items[Math.floor((right + left) / 2)];
  let i = left,
    j = right;
  while (i <= j) {
    while (items[i] < pivot) {
      i++;
    }
    while (items[j] > pivot) {
      j--;
    }
    if (i <= j) {
      swap(items, i, j);
      i++;
      j--;
    }
  }
  return i;
}

function quickSort(items, left, right) {
  var index;
  if (items.length > 1) {
    index = partition(items, left, right);
    if (left < index - 1) {
      quickSort(items, left, index - 1);
    }
    if (index < right) {
      quickSort(items, index, right);
    }
  }
  return items;
}

const unordered = [-10, 30, 85, 102, 5, 3, 7, 6, 2, 9, 0, -1];
const sorted = quickSort(unordered, 0, unordered.length - 1);
console.log(sorted);
