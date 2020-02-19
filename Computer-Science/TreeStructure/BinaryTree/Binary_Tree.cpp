#include"Binary_Tree.h"

namespace mw {

  template <typename T>
  BinTreeNode<T>* BinTreeNode<T>::add_left_child(const T& value) {
    left_ = new BinTreeNode<T>(value, this);
    return left_;
  }

  template <typename T>
  BinTreeNode<T>* BinTreeNode<T>::add_right_child(const T& value) {
    right_ = new BinTreeNode<T>(value, this);
    return right_;
  }

  template<typename T>
  void Binary_Tree<T>::insert(BinTreeNode<T>* node,const T& value) {
    if (node==nullptr) {
      this->root_ = new BinTreeNode<T>(value, nullptr);
      return;
    }
    while (true) {
      if (value < node->value_) {
        if (node->left_ == nullptr) {
          node->add_left_child(value);
          break;
        }
        node = node->left_;
      }
      else {
        if (node->right_ == nullptr) {
          node->add_right_child(value);
          break;
        }
        node = node->right_;
      }
    }
  }

  template<typename T>
  BinTreeNode<T>* Binary_Tree<T>::search(const T& value) {
    if (root_ != nullptr) {
      BinTreeNode<T>* node = root_;
      while (node->left_ != nullptr) {
        if (node->value_ == value) return node;
        else if (value < node->value_) {
          if (node->left_ != nullptr)
            node = node->left_;
          return 0;
        }
        else {
          if (node->right_ != nullptr)
            node = node->right_;
          return 0;
        }
      }
    }
  }

  template <typename T>
  int Binary_Tree<T>::height(BinTreeNode<T>* node)
  {
    if (node == nullptr) return -1;
    return std::max(height(node->left_), height(node->right_)) + 1;
  }

  template <typename T>
  int Binary_Tree<T>::count(BinTreeNode<T>* node)
  {
    if (node == nullptr) return 0;
    return count(node->left_) + count(node->right_) + 1;
  }

  template<typename T>
  BinTreeNode<T>* Binary_Tree<T>::get_min() {
    if (root_ == nullptr) return -1;
    BinTreeNode<T>* node = root_;
    while (node->left_ != nullptr)  node = node->left_;
    return node;
  }

  template<typename T>
  BinTreeNode<T>* Binary_Tree<T>::get_max() {
    if (root_ == nullptr) return -1;
    BinTreeNode<T>* node = root_;
    while (node->right_ != nullptr) node = node->right_;
    return node;
  }

  template<typename T>
  void Binary_Tree<T>::preorder(BinTreeNode<T>* node) {
    if (node == nullptr) return;
    std::cout << node->value_ << std::endl;
    preorder(node->left_);
    preorder(node->right_);
  }

  template<typename T>
  void Binary_Tree<T>::inorder(BinTreeNode<T>* node) {
    if (node == nullptr) return;
    preorder(node->left_);
    std::cout << node->value_ << std::endl;
    preorder(node->right_);
  }

  template<typename T>
  void Binary_Tree<T>::postorder(BinTreeNode<T>* node) {
    if (node == nullptr) return;
    preorder(node->left_);
    preorder(node->right_);
    std::cout << node->value_ << std::endl;
  }

  template<typename T>
  void Binary_Tree<T>::levelorder(BinTreeNode<T>* node) {
    if (root_ == nullptr) return;
    std::queue<BinTreeNode<T>*> temp;
    temp.push(node);
    while (!temp.empty()) {
      BinTreeNode<T>* current = temp.front();
      std::cout << current->value_ << std::endl;
      if (current->left_ != nullptr) temp.push(current->left_);
      if (current->right_ != nullptr) temp.push(current->right_);
      temp.pop();
    }
  }
  template<typename T>
  void Binary_Tree<T>::remove(BinTreeNode<T>* node, const T& value) {
    if (!root_) return;
    BinTreeNode<T>* current = this->search(value);
    if (current == nullptr) return;
    else {
      if (current->left_ == nullptr && current->right_ == nullptr) {
        delete current;
        current = nullptr;
      }
      else if (current->left_ == nullptr) {
        BinTreeNode<T>* temp = current;
        current = current->right_;
        delete temp;
      }
      else if (current->right_ == nullptr) {
        BinTreeNode<T>* temp = current;
        current = current->left_;
        delete temp;
      }
      else {
        BinTreeNode<T>* minimum = current->right_;
        while (current->left_ != nullptr)  minimum = minimum->left_;
        current->value_ = minimum->value_;
        return remove(current->right_, minimum->value_);
      }
    }
  }

  template<typename T>
  BinTreeNode<T>* Binary_Tree<T>::succesor(const T& value) const {
    BinTreeNode<T>* node = this->search(value);
    if (node == nullptr) return nullptr;
    if (node->right_ != nullptr) {
      BinTreeNode<T>* current = node->right_;
      while (current->left_ != nullptr)
        current = current->left_;
      return current;
    }
    BinTreeNode<T>* ancestor = node->parent_;
    while (ancestor != nullptr && node == ancestor->left_) {
      node = ancestor;
      ancestor = ancestor->parent_;
    }
    return ancestor;
  }

  template<typename T>
  bool Binary_Tree<T>::is_empty_tree() {
    return root_ == nullptr;
  }

}