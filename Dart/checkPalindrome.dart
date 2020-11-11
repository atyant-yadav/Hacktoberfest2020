main() {
  print(checkPalindrome('aabaa'));
}

bool checkPalindrome(String inputString) {
  String reverseStr = inputString.split('').reversed.join();
  print(reverseStr);
  if (reverseStr == inputString) {
    return true;
  }
  return false;
}
