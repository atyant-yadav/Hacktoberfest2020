main() {
  List array = [15, 56, 43, 11, 30];
  int x = 56;
  int result = linearSearch(array, x);

  result == 0
      ? print("Element is not present in array")
      : print("Element is present at index " + result.toString());
}

int linearSearch(List list, int x) {
  for (int i = 0; i < list.length; i++) {
    if (list[i] == x) {
      return i;
    }
  }
  return 0;
}
