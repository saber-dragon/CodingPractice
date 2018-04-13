#include <iostream>
#include "search_rotated_sorted_array.hpp"
#include <vector>

using namespace std;

int main(){
    vector<int> v{10,100,1000,1, 4, 9};
    cout << *(saber::search_rotated_sorted_array(v.begin(), v.end(), 1000)) << endl;
    cout << *(saber::search_rotated_sorted_array(v.begin(), v.end(), 100)) << endl;
    cout << *(saber::search_rotated_sorted_array(v.begin(), v.end(), 10)) << endl;
    cout << *(saber::search_rotated_sorted_array(v.begin(), v.end(), 1)) << endl;
    cout << *(saber::search_rotated_sorted_array(v.begin(), v.end(), 4)) << endl;
    cout << *(saber::search_rotated_sorted_array(v.begin(), v.end(), 9)) << endl;

    vector<int> b{3,1};
    cout << (saber::search_rotated_sorted_array(b.begin(), b.end(), 5) == b.end()) << endl;
    return 0;
}
