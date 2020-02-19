#include"rmerge.h"

namespace mw {

template<typename T>
void merge(T arr[], T temp[], int min,int mid, int max) {

  for (int i = min; i <= max; i++)
    temp[i] = arr[i];

  int i = min;
  int j = mid + 1;
  for (int k = min; k <= max; k++) {
    if (i > mid)                    arr[k] = temp[j++];
    else if (j > max)               arr[k] = temp[i++];
    else if (temp[i] <= temp[j])    arr[k] = temp[i++];
    else                            arr[k] = temp[j++];
  }
}

template<typename T>
static void rsort(T arr[], T temp[], int min, int max){
  if (max <= min) return;
  int mid = min + (max - min) / 2;
  rsort(arr, temp, min, mid);
  rsort(arr, temp, mid + 1, max);
  merge(arr, temp, min, mid, max);
}

template<typename T>
void sort(T arr[], int size) {
  T* temp = new T[size];
  rsort(arr, temp, 0,size-1);
}

}