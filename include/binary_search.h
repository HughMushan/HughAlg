namespace HughAlg {
    template<class RandomAccessIterator, class T>
        RandomAccessIterator binary_search(RandomAccessIterator first, RandomAccessIterator last, T target)
        {
            if(first == last) return last;

            RandomAccessIterator start = first;
            RandomAccessIterator end = last - 1;
            while(start + 1 < end) {
                RandomAccessIterator mid = start + (end - start) / 2;
                if(*mid == target) {
                    start = mid;
                }
                else if(*mid < target) {
                    start = mid;
                }
                else {
                    end = mid;
                }
            }

            if(*start == target) return start;

            if(*end == target) return end;

            return last;

        }

}
