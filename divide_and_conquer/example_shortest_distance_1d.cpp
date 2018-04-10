#include <iostream>
#include <vector> // for std::vector
#include "shortest_distance_1d.hpp"

int main(){
    std::vector<int> v{2, 3, 3, 5, 7};
    size_t k = 4;

    std::cout << saber::kth_shortest_distance(v.begin(), v.end(), k)
              << std::endl;
    return 0;
}
