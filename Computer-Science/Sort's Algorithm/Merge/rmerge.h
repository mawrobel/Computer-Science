#pragma once
#include<algorithm>
namespace mw {
  template<typename T>
  void merge(T arr[], T temp[], int min, int max);

  template<typename T>
  static void rsort(T arr[], T temp[], int min, int max);

  template<typename T>
  void sort(T arr[], int size);
}