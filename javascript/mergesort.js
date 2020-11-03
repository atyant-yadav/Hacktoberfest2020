function merge_sort(left_part, right_part) {
  var i = 0;
  var j = 0;
  var results = [];

  while (i < left_part.length || j < right_part.length) {
    if (i === left_part.length) {
      // j is the only index left_part
      results.push(right_part[j]);
      j++;
    } else if (j === right_part.length || left_part[i] <= right_part[j]) {
      results.push(left_part[i]);
      i++;
    } else {
      results.push(right_part[j]);
      j++;
    }
  }
  return results;
}

console.log(merge_sort([1, 3, 4], [3, 7, 9]));
