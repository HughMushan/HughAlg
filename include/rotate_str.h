#include "common.h"

namespace HughAlg
{
    template<class T>
        T gcd(T m, T n)
        {
            while(n != 0) {
                T tmp = m % n;
                m = n;
                n = tmp;
            }
            return m;
        }
    template<class RandomAccessIterator>
        void rotate(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
        {
            //三段翻转法
            HughAlg::reverse(first, middle);
            HughAlg::reverse(middle, last);
            HughAlg::reverse(first, last);
        }

    template<class RandomAccessIterator, class Distance>
        void __rotate_cycle(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator initial, Distance shift)
        {
            typedef typename RandomAccessIterator::value_type T;
            T value = *initial;
            RandomAccessIterator ptr1 = initial;
            RandomAccessIterator ptr2 = ptr1 + shift;
            while(ptr2 != initial)
            {
                *ptr1 = *ptr2;
                ptr1 = ptr2;
                if(last - ptr2 > shift)
                    ptr2 = ptr2 + shift;
                else
                    ptr2 = first + (shift - (last - ptr2));//不是很明白...

            }
            *ptr1 = value;
        }

    //random access iterator版本更有效率的实现
    template<class RandomAccessIterator>
        void rotate_(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
        {
            typedef typename RandomAccessIterator::difference_type Distance;
            //获取全长和前段长度的最大公因子
            Distance n = HughAlg::gcd(last - first, middle - first);
            while(n--) {
                __rotate_cycle(first, last, first + n, middle - first);
            }

        }

}
