#include "common.h"

namespace HughAlg
{
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
