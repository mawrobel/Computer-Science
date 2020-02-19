#pragma once

#include<algorithm>
#include<iostream>
#include<queue>

namespace mw {

  template<typename T> class Binary_Tree;

  template<typename T>
  class BinTreeNode {
  public:
    BinTreeNode(const T& val, BinTreeNode* parent) :
      value_{ val }, left_{ nullptr },
      right_{ nullptr }, parent_{ parent } {};
    ~BinTreeNode() {};

    BinTreeNode<T>* add_left_child(const T& value);
    BinTreeNode<T>* add_right_child(const T& value);

    friend class Binary_Tree<T>;

  private:
    T value_;
    BinTreeNode<T>* left_;
    BinTreeNode<T>* right_;
    BinTreeNode<T>* parent_;

  };

  template<typename T>
  class Binary_Tree {
  public:
    Binary_Tree() :root_{ nullptr } {};
    Binary_Tree(const T& value) { root_ = new BinTreeNode<T>(value, nullptr); }
    ~Binary_Tree() {}

    bool is_empty_tree();
    int height() { return height(root_); };
    BinTreeNode<T>* get_root() { return root_; };
    void insert(const T& value) { return insert(root_, value); };
    int count(BinTreeNode<T>* node);
    BinTreeNode<T>* search(const  T& value);
    BinTreeNode<T>* get_min();
    BinTreeNode<T>* get_max();
    void preorder() { return preorder(root_); };
    void inorder() { return inorder(root_); };
    void postorder() { return postorder(root_); };
    void levelorder() { return levelorder(root_); };
    void remove(const T& value) { return remove(root_, value); };
    BinTreeNode<T>* succesor(const T& value) const;
  private:
    void insert(BinTreeNode<T>* node, const T& value);
    BinTreeNode<T>* root_;
    int height(BinTreeNode<T>* node);
    void preorder(BinTreeNode<T>* node);
    void inorder(BinTreeNode<T>* node);
    void postorder(BinTreeNode<T>* node);
    void levelorder(BinTreeNode<T>* node);
    void remove(BinTreeNode<T>* node, const T& value);

  };
}