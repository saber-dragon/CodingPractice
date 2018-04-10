#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <vector>
#include <utility>

namespace saber {
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& obj){
        for (const auto &v: obj) os << v << " ";
        os << std::endl;
        return os;
    }

}

#endif // UTILS_HPP
