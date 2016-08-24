#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "rotate_str.h"

using namespace std;

class RotateTest: public ::testing::Test
{
    protected:
        void SetUp() {
            iv = vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9};
        }

        vector<int> iv;
};

template<class T>
struct display
{
    void operator ()(const T& value)
    {
        cout << value << " ";
    }
};


TEST_F(RotateTest, AccuracyTest)
{
    vector<int> tmp = iv;
    vector<int> tmp2 = iv;
    HughAlg::rotate(iv.begin(), iv.begin()+3,  iv.end());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;
    rotate(tmp.begin(), tmp.begin()+3, tmp.end());
    for_each(tmp.begin(), tmp.end(), display<int>());
    cout << endl;
    EXPECT_EQ(iv, tmp);
    HughAlg::rotate_(tmp2.begin(), tmp2.begin()+3, tmp2.end());
    for_each(tmp2.begin(), tmp2.end(), display<int>());
    cout << endl;
    EXPECT_EQ(tmp2, tmp);
}

