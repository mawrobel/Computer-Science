#pragma once

namespace mw {
  template<typename T>
  class DblNode {
  public:
    DblNode(const T& value) : next_{ nullptr }, prev_{ nullptr }, value_{ value } {}
    ~DblNode() {}

    DblNode<T>* get_next() const { return this->next_; }
    DblNode<T>* get_prev() const { return this->prev_; }

    void set_next(DblNode<T>* next) { this->next_ = next; }
    void set_prev(DblNode<T>* prev) { this->prev_ = prev; }
    void set_value(T& value) { this->value_ = value; }

    const T& get_value() const { return this->value_; }

  private:
    DblNode<T>* next_;
    DblNode<T>* prev_;
    T value_;

  };

  template<typename T>
  class DoubleQueue {
  public:
    DoubleQueue();
    ~DoubleQueue();

    void pushfront(T value);
    void pushback(T value);

    T popfront();
    T popback();

    void show();
    void rshow();
    void remove(T value);
    bool is_empty();

  private:
    DblNode<T>* head_;
    DblNode<T>* tail_;
  };
}