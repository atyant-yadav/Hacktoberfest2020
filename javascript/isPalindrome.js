function isPalindrome(word) {
  const arrayWord = [...word];
  const wordReverse = arrayWord.reverse().join("");
  return word == wordReverse;
}

export default isPalindrome;
