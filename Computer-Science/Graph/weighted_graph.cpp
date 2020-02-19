#include <iostream>
#include "weighted_graph.h"

namespace mw
{

template <class T>
WeightedGraph<T>::WeightedGraph(const T vertices[], unsigned int size)
:vertices_(size), edges_(0){
  for (unsigned int i = 0; i < vertices_; i++)
    adjancy_[vertices[i]] = std::list<std::pair<T, unsigned int>>();
}

template <class T>
void WeightedGraph<T>::add_edge(const T& src, const T& dst,const unsigned int weight){
  adjancy_[src].push_back(std::make_pair(dst, weight));
  edges_++;
}

template <class T>
void WeightedGraph<T>::remove_edge(const T& src, const T& dest)
{
  adjancy_[src].earse(dest);
  edges_--;
}

template <class T>
T WeightedGraph<T>::extract_min(const std::set<T>& SetOfV,
                                const std::unordered_map<T, unsigned int>& distance) const
{
  T min_v; unsigned int min = std::numeric_limits<unsigned int>::infinity();
  for (auto v : SetOfV) {
    if (distance.at(v) < min) {
      min = distance.at(v); min_v = v;
    }
  }
  return min_v;
}

template <class T>
void WeightedGraph<T>::print_shortest_path(const std::unordered_map<T, T>& path, 
                                           const T& src, const T& dst) const
{
  T i = dst;
  while (i != src) {
    std::cout << i << " ";
    i = path.at(i);
  }
  std::cout << i << std::endl;
}

template <class T>
void WeightedGraph<T>::find_shortest_path(const T& src, const T& dst) const{
  std::set<T> SetOfV;
  std::unordered_map<T, unsigned int> distance;
  std::unordered_map<T, T> path;
 
  for (auto const& [key, _] : adjancy_) {
    distance[key] = std::numeric_limits<unsigned int>::infinity();
    SetOfV.insert(key);
  }
  distance[src] = 0;

  while (!SetOfV.empty()) {
    T v = extract_min(SetOfV, distance);
    SetOfV.erase(v);
    for (auto u : adjancy_.at(v)) {
      if (distance[u.first] > distance[v] + u.second) {
        distance[u.first] = distance[v] + u.second;
        path[u.first] = v;
      }
    }
  }
  print_shortest_path(path, src, dst);
}

}  // namespace mw