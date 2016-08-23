#include "gtest/gtest.h"
#include "permutation.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class PermutationTest: public ::testing::Test
{
    protected:
        void SetUp() {
            iv = vector<int>{1, 2, 3, 4, 5};
        }

        vector<int> iv;
};

template<class T>
struct display
{
    void operator()(const T& v)
    {
        cout << v << " ";
    }
};

TEST_F(PermutationTest, NextPermutationTest) {
    int count = 1;
    while(HughAlg::next_permutation(iv.begin(), iv.end()))
    {
        count ++;
    }
    EXPECT_EQ(count, 120);
}


