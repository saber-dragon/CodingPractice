#ifndef SHORTEST_DISTANCE_1D_HPP
#define SHORTEST_DISTANCE_1D_HPP
#include <iterator> // std::iterator_traints
#include <algorithm> // std::nth_element
#include <cassert> // assert

namespace saber {
    template <typename T>
    struct Min
    {
        Min() : min(std::numeric_limits<T>::max()){}
        void operator()(const T& n) {
            min = (n < min)?n:min;
        }
        T min;
    };
    template <typename T>
    struct Max
    {
        Max() : max(std::numeric_limits<T>::min()){}
        void operator() (const T& n){
            max = (n > max)?n:max;
        }
        T max;
    };
    template <typename It>
    auto shortest_distance(It first, It last) -> typename std::iterator_traits<It>::value_type
    {
         using T = typename std::iterator_traits<It>::value_type;
         auto d = std::distance(first, last);
         assert(d > 1);
         // base case
         if (d == 2) return std::abs(*(first + 1) - *(first));
         // divide and conquer
         auto n = first + d / 2;
         std::nth_element(first, n, last);
         auto m = std::for_each(first, n, Max<T>());
         auto gap = *n - m.max;
         auto shortestDistance1 = std::numeric_limits<T>::max();
         auto shortestDistance2 = std::numeric_limits<T>::max();
         if (std::distance(first, n) == 1) {
             // first part has only one element
             shortestDistance2 = shortest_distance(n, last);
         } else if (std::distance(n, last) == 1) {
             // second part has only one element
             shortestDistance1 = shortest_distance(first, n);
         } else {
             shortestDistance1 = shortest_distance(first, n);
             shortestDistance2 = shortest_distance(n, last);
         }
         return std::min({gap, shortestDistance1, shortestDistance2});
    }

}
#endif // SHORTEST_DISTANCE_1D_HPP
