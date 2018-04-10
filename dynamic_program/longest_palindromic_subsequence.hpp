#ifndef LONGEST_PALINDROMIC_SUBSEQUENCE_HPP
#define LONGEST_PALINDROMIC_SUBSEQUENCE_HPP
#include <string>
#include <vector>

#include "utils.hpp"

namespace saber {


    bool is_palindromic(const std::string& s){
        size_t n = s.size();
        if (s.size() <= 1) return true;
        size_t i = 0, j = n - 1;
        while (i < j && s[i] == s[j]) {
            ++ i; -- j;}

        return (i >= j);
    }
    size_t longest_palindromic_subsequence(const std::string& s){
        auto n = s.size();
        if (n <= 1) return n;
        std::vector<std::vector<size_t> > T(n, std::vector<size_t>(n, 1));

        for (size_t d = 1;d < n; ++ d){
            for (size_t i = 0, e = n - d;i < e;++ i){
               if (s[i] == s[i + d]) {
                   T[i][i + d] = (d > 1)?(T[i + 1][i + d - 1] + 2):2;
               }
               else {
                   T[i][i + d] = std::max(T[i][i + d - 1], T[i + 1][i + d]);
               }
            }
        }
        //std::cout << T << std::endl;
        return T[0][n - 1];
    }
}
#endif // LONGEST_PALINDROMIC_SUBSEQUENCE_HPP
