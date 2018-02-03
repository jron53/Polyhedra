#include"Graph.h"
#include"util.h"
namespace Ron
{
  void Graph::add_vertex(const std::string& name, const R& x, const R& y, const R& z)
  {
      Vertex *v = new Vertex(name, x, y, z);
      auto it = vertices.find(name);
      if (it != vertices.end())
      {
          panic("duplicate vertex name");
      }
      vertices[name] = v;
  }
  void Graph::add_edge(const std::string& from, const std::string& to)
  {
      auto it_1 = vertices.find(from);
      auto it_2 = vertices.find(to);
      if(it_1 == vertices.end() || it_2 == vertices.end() )
      {
          panic("no such vertex exists!!!");
      }

      Edge* e = new Edge (it_1->second, it_2->second);

      it_1->second->add_edge(e);
      it_2->second->add_edge(e);
  }
}
