#include "stack.h"

namespace mw {

 template<typename T>
 void Stack<T>::push(T val) {
   if (top_ != capacity_)
     array_[top_++] = val;
 }

 template<typename T>
 T Stack<T>::pop() {
   if (!top_ )
    return array_[--top_];
 }

 template<typename T>
  inline bool Stack<T>::empty() const {
   return !top_;
 }

}  // namespace mw