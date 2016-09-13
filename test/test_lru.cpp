#include "gtest/gtest.h"
#include <vector>
#include "lru.h"

using namespace std;

class LRUTest: public ::testing::Test
{
    protected:
        void SetUp() {
            ivec = vector<int> {1, 2, 3, 4, 5, 1, 2, 5, 1, 2, 3, 4, 5};
            cache_size = 3;
        }
        int cache_size = 3;
        vector<int> ivec;
};

TEST_F(LRUTest, AccuracyTest)
{
    Cache<int> cache(cache_size);
    int count = 0;
    for(auto v : ivec) {
        if(!cache.push(v)) count ++;
        cache.print();
    }

    EXPECT_EQ(count, 10);
}
