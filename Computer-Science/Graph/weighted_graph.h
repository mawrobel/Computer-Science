
#include <unordered_map>
#include <utility>
#include <list>
#include <set>

namespace mw
{

  template <class T>
  class WeightedGraph
  {
  public:
    WeightedGraph(const T vertices[], unsigned int size);
    ~WeightedGraph() {}

    void add_edge(const T& src, const T& dest, const unsigned int weight);
    void remove_edge(const T& src, const T& dest);
    void find_shortest_path(const T& src, const T& dst) const;

  private:
    unsigned int vertices_;
    unsigned int edges_;  
    std::unordered_map<T, std::list<std::pair<T, unsigned int>>> adjancy_;

    T extract_min(const std::set<T>& Q,
      const std::unordered_map<T, unsigned int>& d) const;
    void print_shortest_path(const std::unordered_map<T, T>& p, const T& src,
      const T& dst) const;
  };

}  // namespace mw