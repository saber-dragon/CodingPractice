#ifndef MAXIMUM_SUM_OF_TWO_NON_OVERLOPPING_SUBARRAYS_HPP
#define MAXIMUM_SUM_OF_TWO_NON_OVERLOPPING_SUBARRAYS_HPP

#include <vector>
#include <array>
#include <limits>
#include <algorithm>
#include <functional>

namespace saber {
    template <typename T>
    inline T get_sum_of_subarrary(std::vector<T>& partial_sum, size_t s, size_t k){
        size_t t = s + k - 1;
        return partial_sum[t] - (s == 0?0:partial_sum[s - 1]);
    }
    template <typename T>
    std::array<size_t, 2> maximum_sum_of_two_non_overlapping_subarrays(std::vector<T>& A, size_t k){

        auto n = A.size();
        std::vector<T> B(n, 0);

        std::partial_sum(A.begin(), A.end(), B.begin());

        auto max_sum = get_sum_of_subarrary(B, n - 2 * k, 2 * k);
        auto second_max_subarray = std::make_pair(n - k, get_sum_of_subarrary(B, n - k, k));
        std::array<size_t, 2> p;
        p[0] = n - 2 * k;
        p[1] = n - k;
        for (int i = n - 2 * k - 1;i >= 0;-- i) {
            T cur_sum = get_sum_of_subarrary(B, i + k, k);
            if (cur_sum >= second_max_subarray.second) {
                second_max_subarray.first = i + k;
                second_max_subarray.second = cur_sum;
            }
            cur_sum = get_sum_of_subarrary(B, i, k) + second_max_subarray.second;
            if (cur_sum >= max_sum){
                max_sum = cur_sum;
                p[0] = i;
                p[1] = second_max_subarray.first;
            }
        }
        return p;
    }
}


#endif // MAXIMUM_SUM_OF_TWO_NON_OVERLOPPING_SUBARRAYS_HPP
