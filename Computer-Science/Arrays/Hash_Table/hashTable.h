#pragma once

#include<string>
namespace mw {
  template<typename K = std::string , typename V=int  >
  struct HTNode {
    HTNode(){}
    HTNode(const K k, const V v) :key{ k }, value{v} {}
    K key;  
    V value;
  };
  template<typename K = std::string,typename V=int >
  class HashTable {
  public:
    HashTable();
    ~HashTable() {};
 
    void insert(const K& key,const V& value);
    K get(const K& key) const;
    void remove(const K& key);
    
  private:
    int n_;
    int m_;
    HTNode<K,V> **array_;

    int hash_(const K& key) const;
    void resize_();

  };

}