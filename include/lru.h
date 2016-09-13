#include <iostream>

using namespace std;

template<class T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode(T v):val(v), next(NULL) {}
};


template<class T>
class Cache
{
    typedef ListNode<T>*  element_type;

public:
    explicit Cache(int cache_size):_cache_size(cache_size), elements(NULL) {}

    bool push(T element)
    {
        element_type curr;
        element_type prev = NULL;
        int count = 0;
        if(elements == NULL) {
          elements = new ListNode<int>(element);
          return false;
        }
        for(curr = elements; count < _cache_size;  count ++) {
            if(curr->val == element) {
                if(prev != NULL) {
                    prev->next = curr->next;
                    curr->next = elements;
                    elements = curr;
                }
                return true;
            }
            if(curr->next == NULL) break;
            prev = curr;
            curr = curr->next;
        }

        element_type temp = new ListNode<int>(element);
        temp->next = elements;
        elements = temp;
        count ++;

        if(count < _cache_size) {
            return false;
        }
        else {
            if(prev == NULL) {
                elements->next = NULL;
                delete curr;
            }
            else {
                prev->next = NULL;
                delete curr;
            }
            return false;
        }

    }

    void print()
    {
        element_type curr = elements;
        while(curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;

    }
private:
    element_type elements;
    int _cache_size;
};

