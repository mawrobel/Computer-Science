#pragma once

#include <memory>

namespace mw {

 template<class T>
 class Stack {
   public:
     Stack(int val) : top_{ 0 }, capacity_{ val } {
     array_ = std::unique_ptr<T[]>(new T[capacity_]);
    }
    ~Stack() {}

    void push(T val);
    T pop();
    inline bool empty() const;

   private:
    int top_;
    int capacity_;
    std::unique_ptr<T[]> array_;
 };

}  // namespace mw
