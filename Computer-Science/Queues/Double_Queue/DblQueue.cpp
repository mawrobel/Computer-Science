#include"DblQueue.h"
#include<iostream>
namespace mw {

  template<typename T>
  DoubleQueue<T>::DoubleQueue() {
    this->head_ = nullptr;
    this->tail_ = nullptr;
  }

  template<typename T>
  DoubleQueue<T>::~DoubleQueue() {
    DblNode<T>* node = this->head_;
    DblNode<T>* next = nullptr;
    while (node != nullptr) {
      next = node->get_next();
      delete node;
      node = next;
    }
  }

  template<typename T>
  void DoubleQueue<T>::pushback(T value) {
    DblNode<T>* node = new DblNode<T>(value);
    node->set_next(nullptr);
    if (this->tail_ == nullptr) {
      this->head_ = node;
      node->set_prev(nullptr);
    }
    else {
      this->tail_->set_next(node);
      node->set_prev(this->tail_);
    }
    this->tail_ = node;
  }

  template<typename T>
  void DoubleQueue<T>::pushfront(T value) {
    DblNode<T>* node = new DblNode<T>(value);
    node->set_prev(nullptr);
    if (this->head_ == nullptr) {
      this->tail_ = node;
      node->set_next(nullptr);
    }
    else {
      this->head_->set_prev(node);
      node->set_next(this->head_);
    }
    this->head_ = node;
  }

  template<typename T>
  T DoubleQueue<T>::popback() {
    if ((this->head_ != nullptr) && (this->tail_ != nullptr)) {
      T value = this->tail_->get_value();
      if (this->head_ == this->tail_) {
        this->head_ = nullptr;
        this->tail_ = nullptr;
        return value;
      }
      else {
        this->tail_ = this->tail_->get_prev();
        this->tail_->set_next(nullptr);
        return value;
      }
    }
  }

  template<typename T>
  T DoubleQueue<T>::popfront() {
    if ((this->head_ != nullptr) && (this->tail_ != nullptr)) {
      T value = this->head_->get_value();
      if (this->head_ == this->tail_) {
        this->head_ = nullptr;
        this->tail_ = nullptr;
        return value;
      }
      else {
        this->head_ = this->head_->get_next();
        this->head_->set_prev(nullptr);
        return value;
      }
    }
  }

  template<typename T>
  void DoubleQueue<T>::show() {
    DblNode<T>* node = this->head_;
    while (node!=nullptr){
      std::cout << node->get_value()<<", ";
      node = node->get_next();
    }
    std::cout << std::endl;
  }

  template<typename T>
  void DoubleQueue<T>::rshow() {
    DblNode<T>* node = this->tail_;
    while (node != nullptr)
    {
      std::cout << node->get_value() << ", ";
      node = node->get_prev();
    }
    std::cout << std::endl;
  }

  template<typename T>
  bool DoubleQueue<T>::is_empty() {
    return this->head_ == nullptr;
  }
}