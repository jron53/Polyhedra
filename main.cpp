#include <iostream>

#include <boost/multiprecision/gmp.hpp>

#include "Graph.h"


using namespace std;

using R = boost::multiprecision::mpq_rational;

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        Ron::Graph g;
        g.read(argv[i]);
    }
    return 0;
}
