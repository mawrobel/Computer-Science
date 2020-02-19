#include"Dynamic_Array.h"
#include<memory>

namespace mw {

template<typename T>
Array<T>::Array() {
  this->size_ = 0;
  this->capacity_ = 16;
  this->array_ = std::unique_ptr<T[]>{ new T[this->capacity_] };
}

template<typename T>
void Array<T>::push(T value) {
  if (this->size_ >= this->capacity_)
    this->resize();
  this->array_[(this->size_)++] = value;
}

template<typename T>
void Array<T>::is_empty() {
  return !(this->size_);
}

template<typename T>
void Array<T>::resize() {
  std::unique_ptr<T[]> temp{ new T[this->capacity_ * 2] };
  for (int i = 0; i < this->size_; i++) {
    temp[i] = this->array_[i];
  }
  this->array_ = std::move(temp);
  this->capacity_ = this->capacity_ * 2;
}

template<typename T>
void Array<T>::show() {
  for (int i = 0; i != this->size_; i++)
    std::cout << this->array_[i];
}

template<typename T>
void Array<T>::insert(int position, T value) {
  if (position > 0 && position < this->size_)
    this->array_[position] = value;
}

template<typename T>
void Array<T>::delete_index(int position) {
  for (int i = position; i < this->size_; i++) {
      this->array_[i] = this->array_[i + 1];
  }
  this->size_--;
}

template<typename T>
void Array<T>::remove(T value) {
  for (int i = 0; i <= this->size_; i++) {
    if (this->array_[i] == value)
      Array<T>::delete_index(i);
  }
}

template<typename T>
T Array<T>::at(int position) {
  if (position > 0 || position < size_)
    return this->array_[position];
}

template<typename T>
T Array<T>::pop() {
  return this->array_[--(this->size_)];
}

template<typename T>
int Array<T>::find(T value) {  
  for (int i = 0; i != size_; i++)
    if (this->array_[i] == value)
      return i;
}
}