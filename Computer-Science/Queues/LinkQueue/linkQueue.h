
#pragma once

#include<optional>

namespace mw {
template<typename T>
class Node {
public:
  Node(const T& value) : value_{ value }, next_{ nullptr }{}
  ~Node() {}
  
  void set_value(const T& value) { value_ = value; }
  void set_next(Node<T>* next) { next_ = next; }
  
  Node<T>* get_next() const { return next_; }

  const T& get_value() const { return value_; }

private:
  T value_;
  Node<T>* next_;
};

template<typename T>
class linkQueue {
public:
  linkQueue() :head_{ nullptr }, tail_{ nullptr } {}
  ~linkQueue();
  void enqueue(T value);
  T dequeue();
  bool is_empty() const;
private:
  Node<T>* head_;
  Node<T>* tail_;
};
}// mw