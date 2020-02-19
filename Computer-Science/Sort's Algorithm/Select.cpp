#include<algorithm>
namespace mw {

template<typename T>
void selection_sort(T* arr, int size) {
  T min;
  for (int i = 0; i != size-1; i++) {
    min = i;

    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min]) min = j;
    }
   std::swap(arr[min], arr[i]);
  } 
}

}