#include"hashTable.h"
#include<functional>
#include<iostream>
namespace mw {

template<typename K,typename V  >
HashTable<K, V>::HashTable() {

  this->n_ = 0;
  this->m_ = 16;
  this->array_ =new HTNode<K, V>*[m_];
  for (int i = 0; i != m_; i++) 
    this->array_[i] = nullptr;
}

template<typename K, typename V>
void HashTable<K, V>::resize_() {
  HTNode<K, V>** node = new HTNode<K, V>*[m_*2] ;
  for (int i = 0; i != m_; i++) {
    if (this->array_[i] != nullptr)
      node[i] = std::move(this->array_[i]);
  }
  this->array_ = std::move(node);
  this->m_ *= 2;
}

template<typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {

  float ratio = this->n_ / static_cast<float>(this->m_);
  if (ratio > 0.6)
    void HashTable<K, V>::resize_();

  int h = hash_(key);

  while (this->array_[h] != nullptr) {
    h = (h + 1) % this->m_;
  }
  this->array_[h] = new HTNode<K,V>(key,value);
  this->n_++;
}

template<typename K, typename V>
int HashTable<K, V>::hash_(const K& key) const {
  return std::hash<K>()(key) % m_;
}
template<typename K, typename V>
K HashTable<K, V>::get(const K& key) const {

  int h = hash_(key);

  if (this->array_[h] != nullptr) {
    do {
      if (this->array_[h]->key == key) {
        return this->array_[h]->value;
      }
      h = (h + 1) % this->m_;
    } while (array_[h] != nullptr);
  }

}
template<typename K, typename V>
void HashTable<K, V>::remove(const K& key) {
  int h = hash_(key);

  if (this->array_[h] != nullptr) {
    do {
      if (this->array_[h]->key == key) {
        delete this->array_[h];
        this->array_[h] = nullptr;
        this->n_--;
        return;
      }
      h = (h + 1) % this->m_;
    } while (array_[h] != nullptr);
    return;
  }
}
}