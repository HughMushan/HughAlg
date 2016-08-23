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

