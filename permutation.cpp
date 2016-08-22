#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

namespace HughAlg
{
    template<class Iterator>
        void iter_swap(Iterator f, Iterator l)
        {
            typedef typename Iterator::value_type T;
            T tmp = *f;
            *f = *l;
            *l = tmp;
        }

    template<class RandomAccessIterator>
        void reverse(RandomAccessIterator first, RandomAccessIterator last)
        {
            while(first < --last)
            {
                HughAlg::iter_swap(first, last);
                first ++;
            }

        }

    template<class RandomAccessIterator>
        bool next_permutation(RandomAccessIterator first, RandomAccessIterator last)
        {
            typedef typename RandomAccessIterator::value_type T;
            if(first == last) return false;
            if(first+1 == last) return false;
            RandomAccessIterator i = last;
            --i;
            while(true)
            {
                RandomAccessIterator ii = i;
                --i;
                if(*i < *ii) {
                    RandomAccessIterator j = last;
                    while(!(*(--j)> *i));
                    HughAlg::iter_swap(i, j);
                    HughAlg::reverse(ii, last);
                    return true;
                }

                if(i == first) {
                    HughAlg::reverse(i, last);
                    return false;
                }
            }
        }
}

template<class T>
struct display
{
    void operator()(const T&value)
    {
        cout << value << " ";
    }
};


int main()
{
    display<int> d;
    int a[] = {1, 2, 3, 4, 5, 6};
    vector<int> iv(a, a + 6);
    for_each(iv.begin(), iv.end(), d);
    cout << endl;
    while(HughAlg::next_permutation(iv.begin(), iv.end()))
    {
        for_each(iv.begin(), iv.end(), d);
        cout << endl;
    }
}
