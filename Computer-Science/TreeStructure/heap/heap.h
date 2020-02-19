#pragma once

#include<limits>
#include<iostream>

namespace mw {
template<typename T> class heap;

template<typename T>
class heapnode {
public:
  heapnode(const T& value, heapnode<T>* parent) :value_{ value },
    parent_{ parent }, left_{ nullptr }, right_{ nullptr }, index_{ 0 }{}
  ~heapnode(){}

  heapnode<T>* add_left_child(const T& value);
  heapnode<T>* add_right_child(const T& value);
private:
  T value_;
  heapnode<T>* parent_;
  heapnode<T>* left_;
  heapnode<T>* right_;
  int index_;
  friend class heap<T>;
  
};
template<typename T>
class heap {
public:
  heap();
  ~heap() {};
 
  T get_max();
  bool is_empty();
  T Extract_max();
  void show();
  void insert(const T& value);
  void heapsort();
private:
  int size_;
  int Maxsize_;
  heapnode<T>* root_;
  
  std::unique_ptr<T[]> array_;
  void ShiftUp(int index);
  void Shiftdown(int index);
};
}// namespace mw