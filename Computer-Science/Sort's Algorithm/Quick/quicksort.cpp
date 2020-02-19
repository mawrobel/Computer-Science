#include"quicksort.h"
namespace mw {

template<typename T>
void quicksort(T* arr, int left, int right) {
  int mid = arr[(left + right) / 2];
  int i, j;
  i = left;
  j = right;
  do {
    while (arr[i++] < mid);
    while (arr[j++] > mid);
    if(i<=j){
      std::swap(arr[i], arr[j]);
      i++; j--;
    }
  } while (i <= j);
  if (j > left) quicksort(arr, left, j);
  if (i < right) quicksort(arr, i, right);
}

template<typename T>
void quicksort(T* arr, int size) {
  quicksort(T * arr, 0, size - 1);
}
}