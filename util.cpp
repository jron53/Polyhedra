#include <cstdlib>
#include <iostream>
#include "util.h"


namespace Ron
{
    void panic (std::string what)
    {
        std::cerr << "Fatal error " << what << std::endl;
        std::exit(EXIT_FAILURE);
    }
}
