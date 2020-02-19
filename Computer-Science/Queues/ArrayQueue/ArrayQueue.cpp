#include"ArrayQueue.h"

namespace mw {
  
  template<typename T>
  void ArrayQueue<T>::enqueue(T value) {
    if ((bottom_ + 1) % capacity_ != top_) {
      array_[bottom_] = value;
      bottom_ = (bottom_ + 1) % capacity_;
    }
  }

  template<typename T>
  T ArrayQueue<T>::dequeue() {
    if (top_ != bottom_) {
      T temp = array_[top_];
      top_ = (top_ + 1) % capacity_;
      return temp;
    }
  }
}//mw