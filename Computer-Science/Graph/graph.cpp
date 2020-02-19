#include"graph.h"
#include <vector>
#include<list>
#include<iostream>
#include<stack>
#include<queue>

namespace mw {

  template<typename T>
  Graph<T>::Graph(const T vertices[], unsigned int size) : vertices_{ size }, edges_{ 0 } {
    for (unsigned int i = 0; i != vertices_; i++)
      adjancy_[vertices[i]] = std::list<T>();
  }

  template<typename T>
  bool Graph<T>::check(const T& src) {
    if (adjancy_.find(src) != adjancy_.end())  return true;
    return false;
  }

  template<typename T>
  void Graph<T>::add_edge(const T& src, const T& dst) {
    if (!check(src) || !check(dst)) return;
    adjancy_[src].push_back(dst);
    edges_++;
  }

  template<typename T>
  void Graph<T>::remove_edge(const T& src, const T& dst) {
    if (!check(src) || !check(dst)) return;
    adjancy_[src].erase(dst);
    edges_--;
  }

  template<typename T>
  void Graph<T>::breadth_first_search(const T& vertex) {

    std::unordered_map<T, bool> visited;
    std::list<T> l;

    visited[vertex] = true;
    l.push_back(vertex);

    while (!l.empty()) {

      T value = l.front();
      l.pop_front();
      std::cout << value << std::endl;

      for (auto x : adjancy_[value]) {
        if (visited[x]) continue;
          visited[x] = true;
          l.push_back(x);

      }
    }
  }

  template<typename T>
  void Graph<T>::depth_first_search(const T& vertex) {

    std::unordered_map<T, bool> visited;
    std::stack<T> s;

    visited[vertex] = true;
    s.push(vertex);

    while (!s.empty()) {

      T value = s.top(); s.pop();
      std::cout << value << std::endl;
      for (auto x : adjancy_[value]) {
        if (visited[x]) continue;
        visited[x] = true;
        s.push(x);
      }
    }
  }
    template<typename T>
    void Graph<T>::find_shortest_path(const T & src, const T & dst) {
      if (!check(src) || !check(dst)) return;
      std::unordered_map<T, T> visited;
      std::queue<T> q;

      visited[src] = src;
      q.push(src);

      while (!q.empty()) {
        T val = q.front();
        q.pop();
        for (auto u : adjancy_[val]) {
          if (check(visited[u])) continue;
          visited[u] = val;
          q.push(u);
          if (u == dst) {
            val = u;
            while (val != src) {
              std::cout << val << std::endl;
              val = visited[val];
            }
            std::cout << val << std::endl;
            return;
          }
        }
      }
    }

}//mw