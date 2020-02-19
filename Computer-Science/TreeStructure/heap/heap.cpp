#include"heap.h"

namespace mw {

template<typename T>
heap<T>::heap(){
  this->size_=0;
  this->Maxsize_ = 256;
  this->root_= nullptr ;
  this->array_ = std::unique_ptr<T[]>{ new T[this->Maxsize_] };
}

template<typename T>
void heap<T>::ShiftUp( int index) {
  while (index > 0 && array_[(index - 1) / 2] < array_[index]) {
    std::swap(array_[index],array_[((index - 1) / 2)]);
    index = (index - 1) / 2;
  }
}

template<typename T>
void heap<T>::Shiftdown(int index) {
  int maxindex = index;
  int left = index * 2+1;
  if (left<size_ && array_[left] > array_[maxindex])
    maxindex = left;
  int right = index * 2 + 2;
  if (right <= size_ && array_[right]>array_[maxindex])
    maxindex = right;
  if (index != maxindex) {
    std::swap(array_[index], array_[maxindex]);
    Shiftdown(maxindex);
  }
}

template<typename T>
heapnode<T>* heapnode<T>::add_left_child(const T& value) {
  left_ = new heapnode<T>(value, this);
}

template<typename T>
heapnode<T>* heapnode<T>::add_right_child(const T& value) {
  right_ = new heapnode<T>(value, this);
}

template<typename T>
void heap<T>::insert(const T& value) {
  if (this->size_ + 1 == this->Maxsize_)  return;
  this->array_[size_++] = value;
  this->ShiftUp(this->size_ - 1);
}


template<typename T>
T heap<T>::Extract_max() {
  if (!this->is_empty()) {
    T result = array_[0];
    array_[0] =array_[--size_];
    Shiftdown(0);
    return result;
  }
}

template<typename T>
void heap<T>::show(){
for (int i = 0; i != this->size_; i++)
 std::cout << this->array_[i] <<std::endl;
}

template<typename T>
T heap<T>::get_max() { 
  if (this->size_ != 0) {
    return array_[0];
  }
}

template<typename T>
bool heap<T>::is_empty() {
  return this->size_ == 0;
}
template<typename T>
void heap<T>::heapsort() {
  int n = this->size_;
  std::unique_ptr<T[]>sorted_= std::unique_ptr<T[]>{ new T[this->Maxsize_] };
  for(int i=0;i != n;i++)
    sorted_[i] = heap<T>::Extract_max();
  for (int i = 0; i != n; i++)
    array_[i] = std::move(sorted_[i]);
  this->size_ = n;
}
} //namespace mw