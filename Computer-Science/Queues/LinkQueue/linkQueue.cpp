
#include"linkQueue.h"

namespace mw {

template<typename T>
linkQueue<T>::~linkQueue() {
  Node<T>* temp = head_;
  Node<T>* next = nullptr;
  while (temp != nullptr) {
    next = temp->get_next();
    delete temp;
    temp = next;
  }
}

template<typename T>
void linkQueue<T>::enqueue(T value) {

  Node<T>* temp = new Node<T>(value);

  if (is_empty())
    head_ = temp;
  else
    tail_->set_next(temp);
  tail_ = temp;
}
  
template<typename T>
T linkQueue<T>::dequeue() {

  if (!(is_empty())) {

    Node<T>* temp = head_;
    T value = temp->get_value();
    head_ = head_->get_next();
    
    if (head_ == nullptr)
      tail_ = nullptr;

    delete temp;
    return value;
  }
}

template<typename T>
bool linkQueue<T>::is_empty() const {
  return head_ == nullptr; 
}
} //mw