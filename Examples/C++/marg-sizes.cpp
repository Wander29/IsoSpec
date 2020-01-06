#include <iostream>
#include <cassert>
#include "../../IsoSpec++/unity-build.cpp"

using namespace IsoSpec;

int main()
{
    IsoLayeredGenerator iso("C1000H1000O1000", true, true, true);

    double total = 0.0;

    while(iso.advanceToNextConfiguration() && total < 0.99)
    {
        total += iso.prob();
    }

    std::cout << "Rozmiary subizotopologow:" << std::endl;
    std::cout << "C: " << iso.marginalResultsUnsorted[0]->get_no_confs() 
	      << " H: " << iso.marginalResultsUnsorted[1]->get_no_confs() 
	      << " O: " << iso.marginalResultsUnsorted[2]->get_no_confs() << std::endl;


  // TODO: demonstrate other algorithms
}
