/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  nums.sort((a, b) => a - b);
  let j;
  let r;
  let result = [];
  for (let i = 0; i < nums.length - 2; i++) {
    j = i + 1;
    r = nums.length - 1;
    while (j < r) {
      let sum = nums[i] + nums[j] + nums[r];
      if (sum == 0) {
        result.push([nums[i], nums[j], nums[r]]);
        j = j + 1;
        r = r - 1;
        while (nums[j] == nums[j - 1] && j < r) j++;
        while (nums[r] == nums[r + 1] && j < r) r--;
      } else if (sum < 0) {
        j = j + 1;
      } else {
        r = r - 1;
      }
    }
    while (i < nums.length - 1 && nums[i] == nums[i + 1]) {
      i++;
    }
  }

  return result;
};
