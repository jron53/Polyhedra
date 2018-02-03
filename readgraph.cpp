#include <iostream>
#include <sstream>
#include <fstream>
#include "Graph.h"
#include "util.h"

namespace Ron {

void Graph::read (const std::string& filename)
{
    std::ifstream input (filename.c_str());
    if (!input)
    {
        panic ("Could not open input file");
    }

    std::string line;

    enum state { vertices, edges };

    while (std::getline(input, line))
    {
        state st = vertices;
        if (line == "")
            continue;
        else if (line == "Vertices")
            st = vertices;
        else if (line == "Edges")
            st = edges;
        else if (st == vertices)
        {
            std::istringstream is{line};
            std::string name;
            R x, y, z;
            if (is >> name >> x >> y >> z)
            {
                add_vertex(name, x, y, z);
            }
            else
            {
                panic ("Error reading vertex");
            }
        }
        else
        {
            std::istringstream is{line};
            std::string name1, name2;

            if (is >> name1 >> name2)
            {
                add_edge(name1, name2);
            }
            else
            {
                panic ("Error reading edge");
            }
        }
    }

}

} // Ron
