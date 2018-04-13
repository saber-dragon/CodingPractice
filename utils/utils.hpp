#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

namespace saber {
    const uint8_t PrintWidth = 12;
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& obj){
        for (const auto &v: obj) os << std::setw(PrintWidth) << v << " ";
        os << std::endl;
        return os;
    }

}

#endif // UTILS_HPP
