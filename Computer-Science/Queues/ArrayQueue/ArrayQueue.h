#pragma once
#include<memory>

namespace mw {

  template<typename T>
  class ArrayQueue {
  public:
    ArrayQueue(int val) : top_{ 0 }, bottom_{ 0 }, capacity_{ val } {
      array_ = std::unique_ptr<T[]>(new T[capacity_]);
    }
    ~ArrayQueue() {}

    void enqueue(T value);
    T dequeue()

  private:
    int top_;
    int bottom_;
    int capacity_;
    std::unique_ptr<T[]> array_;
  };
}