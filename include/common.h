
namespace HughAlg
{
    template<class Iterator>
        void iter_swap(Iterator first, Iterator second)
        {
            typedef typename Iterator::value_type T;
            T tmp = *first;
            *first = *second;
            *second = tmp;
        }


    template<class RandomAccessIterator>
        void reverse(RandomAccessIterator first, RandomAccessIterator last)
        {
            while(first < --last)
            {
                HughAlg::iter_swap(first, last);
                first++;
            }
        }

}
