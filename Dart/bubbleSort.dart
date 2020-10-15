main() {
  bubbleSort([173, 657, 1, 0]);
}

void bubbleSort(List list) {
  if (list == null || list.length == 0) return;

  int n = list.length;
  int i, step;
  for (step = 0; step < n; step++) {
    for (i = 0; i < n - step - 1; i++) {
      if (list[i] > list[i + 1]) {
        swap(list, i);
      }
    }
  }
  print(list);
}

void swap(List list, int i) {
  int temp = list[i];
  list[i] = list[i + 1];
  list[i + 1] = temp;
}
