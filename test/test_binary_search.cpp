#include "gtest/gtest.h"
#include "binary_search.h"
#include <vector>
#include <algorithm>
using namespace std;

class BinarySearchTest: public  ::testing::Test
{
    protected:
        void SetUp()
        {
            ivec = vector<int> {1, 2, 3, 4, 5, 6, 7};
        }

        vector<int> ivec;
};

TEST_F(BinarySearchTest, AccuracyTest)
{
    auto iter = HughAlg::binary_search(ivec.begin(), ivec.end(), 4);
    EXPECT_EQ(*iter, 4);
}



