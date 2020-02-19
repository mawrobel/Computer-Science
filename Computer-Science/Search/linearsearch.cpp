
namespace mw {
  template<typename T>
  int linearsearch(T* arr, int size,T res) {
    for (int i = 0; i != size; i++) {
      if (arr[i] == res) break;
      return i;
    }
    return -1;
}
}//mw