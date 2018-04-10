#include <iostream>

#include "longest_palindromic_subsequence.hpp"


int main(){
    std::cout << saber::longest_palindromic_subsequence("bbbab") << std::endl;
    std::cout << saber::longest_palindromic_subsequence("cbbd") << std::endl;
    std::cout << saber::longest_palindromic_subsequence("abba") << std::endl;
    std::cout << saber::longest_palindromic_subsequence("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa") << std::endl;
    std::cout << saber::longest_palindromic_subsequence("abcba") << std::endl;

    return 0;
}
