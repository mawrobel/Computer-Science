namespace mw {

template<typename T>
void bubblesort(T arr[],int size) {
  for (int x = 0; x != size; x++) {
    for (int i = 0; i != size-1 ; i++) {
      if (arr[i] > arr[i + 1]) {
        T temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
}
}