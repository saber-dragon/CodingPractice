#ifndef SEARCH_ROTATED_SORTED_ARRAY_HPP
#define SEARCH_ROTATED_SORTED_ARRAY_HPP

#include <iterator>

namespace saber {
    template <typename It>
    It search_rotated_sorted_array(It first, It last, typename std::iterator_traits<It>::value_type key) 
    {
        using T = typename std::iterator_traits<It>::value_type;
        auto d =std::distance(first, last);
        if (d == 1) return (*first == key)?first:last;
        
        auto l = first;
        auto u = last - 1;
        if (key > *u && key < *l) return last;

        while (l != u){
            auto mid = l + std::distance(l, u) / 2;

            if (*l > *u) {
                if (key == *u) return u;
                else if (key < *u) {// key is located in the second half
                    if (key == *mid) return mid;
                    else if (key < *mid) {
                        if (*mid > *l) l = mid + 1;
                        else u = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                } else {
                    if (key == *mid) return mid;
                    else if (key > *mid) {
                        if (*mid > *l) l = mid + 1;
                        else u = mid - 1;
                    }
                    else u = mid - 1;
                }
            } else {// [i, u] is sorted
                if (key == *mid) return mid;
                else if (key > *mid) l = mid + 1;
                else u = mid - 1;
            }
        }
        return ((*l == key)?l:last);
    }
}
#endif // SEARCH_ROTATED_SORTED_ARRAY_HPP
