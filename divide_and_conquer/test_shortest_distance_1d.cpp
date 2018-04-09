#include <iostream>
#include "shortest_distance_1d.hpp"
#include <utility> // for std::pair
#include <vector>  // for std::vector
#include <gtest/gtest.h>

TEST(ShortestDistanceTest, ReturnAbsDifferenceInBaseCase){
    int A[]={1,2};
    EXPECT_EQ(1, saber::shortest_distance(A, A+2));
    int B[]={1,90};
    EXPECT_EQ(89, saber::shortest_distance(B, B+2));
    int C[]={1000, -10};
    EXPECT_EQ(1010, saber::shortest_distance(C, C+2));
}

TEST(ShortestDistanceTest, ReturnZeroWhenAllEqual){
    std::vector<int> A(2, 1);
    EXPECT_EQ(0, saber::shortest_distance(A.begin(), A.end()));
    std::vector<int> B({2,2,2,2,2,2,2,2,2,2,2,2,2,2,2});
    EXPECT_EQ(0, saber::shortest_distance(B.begin(), B.end()));
    std::vector<int> C(10000, 10);
    EXPECT_EQ(0, saber::shortest_distance(C.begin(), C.end()));
}

TEST(ShortestDistanceTest, ReturnSameValueWhenOrderChanges){
    std::vector<int> A{1,3,7,9,10000};
    std::vector<int> B(A);
    std::random_shuffle(B.begin(), B.end());
    EXPECT_EQ(saber::shortest_distance(A.begin(), A.end()),
              saber::shortest_distance(B.begin(), B.end()));
    A.push_back(213);
    B.push_back(213);
    std::random_shuffle(A.begin(), A.end());
    std::random_shuffle(B.begin(), B.end());
    EXPECT_EQ(saber::shortest_distance(A.begin(), A.end()),
              saber::shortest_distance(B.begin(), B.end()));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
