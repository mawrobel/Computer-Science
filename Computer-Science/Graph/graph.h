#include<unordered_map>
#include<list>

namespace mw {

template<typename T>
class Graph{
public:

  Graph(const T vertices[], unsigned int size);
  ~Graph() {};

  void add_edge(const T& src,const T& dst);
  void remove_edge(const T& src, const T& dst);
 
  void breadth_first_search(const T& vertex);
  void depth_first_search(const T& vertex);

  void find_shortest_path(const T& src, const T& dest);

private:

  unsigned int vertices_;
  unsigned int edges_;
  std::unordered_map<T, std::list<T>> adjancy_;
  bool check(const T& src);
};

 }//mw