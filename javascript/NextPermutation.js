/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
  var swap = function (i, j) {
    let temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  };

  var reverse = function (start) {
    let end = nums.length - 1;
    while (start < end) {
      swap(start, end);
      start++;
      end--;
    }
  };

  let i = nums.length - 1;
  while (i >= 0 && nums[i] <= nums[i - 1]) {
    i--;
  }

  let j = nums.length - 1;
  while (j >= 0 && nums[j] <= nums[i - 1]) {
    j--;
  }

  if (i == 0) {
    reverse(i);
  } else {
    swap(i - 1, j);
    reverse(i);
  }
};
