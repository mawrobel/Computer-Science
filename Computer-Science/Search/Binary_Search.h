namespace mw {

  bool binary_search_rec(int key, int arr[], int min, int max) {
    if (min > max)
      return false;
    else {
      int midpoint = (low + high) / 2;

      if (arr[midpoint] < key)
        binary_search(key, arr, min, midpoint);
      else if (arr[midpoint] > key)
        binary_search(key, arr, midpoint, max);
      else
        return true;
    }
    return false;
  }

  bool binary_search(int key, int arr[], int size) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
      int mid = (low + high) / 2;

      if (arr[mid] > key)
        low = ++mid;
      else if (arr[mid] < key) {
        high = --mid;
      }
      else
        return true;
    }
    return false;
  }

}