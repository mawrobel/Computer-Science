#pragma once

#include<memory>

namespace mw {
  template<typename T>
  class Array {
  public:
    Array();
    ~Array() {};

    void push(T value);
    void is_empty();
    void resize();
    void show();
    void insert(int, T);
    void delete_index(int position);
    void remove(T value);

    T at(int);
    T pop();

    int get_size() { return size_; };
    int get_capacity() { return capacity_; };
    int find(T value);

  private:
    int size_;
    int capacity_;
    std::unique_ptr<T[]> array_;
  };
}