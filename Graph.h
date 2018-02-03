#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <boost/multiprecision/gmp.hpp>

namespace Ron
{
    using R = boost::multiprecision::mpq_rational;

    class Vertex;
    class Edge;
    class Graph
    {
    public:
        Graph() {};
        ~Graph() {};
        void add_vertex (const std::string& name, const R& x, const R& y, const R& z);
        void add_edge (const std::string& from, const std::string& to);
        void read(const std::string& filename);
    private:

        std::unordered_map<std::string, Vertex*> vertices;
        std::vector<Edge*> edges;
    };

    class Vertex
    {
    public:
        Vertex(const std::string& label,const R& x, const R& y, const R& z) : label(label)
        {
            coord[0] = x;
            coord[1] = y;
            coord[2] = z;
        }
        void add_edge(Edge* e)
        {
            edges.push_back(e);
        }

    private:
        R coord[3];
        std::vector<Edge*> edges;
        std::string label;
    };

    class Edge
    {
    public:
        Edge(Vertex* p1, Vertex* p2) : p1(p1), p2(p2) {}
    private:
        Vertex *p1, *p2;
    };
}

#endif // GRAPH_H
