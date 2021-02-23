#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(
    ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    auto maxIt = find_if(first, last, pred);
    auto it = maxIt;
    while (it != last) {
        it++;
        if (it != last) {
            it = find_if(it, last, pred);
            if (it!=last && (*it) > (*maxIt))
                maxIt = it;
        }
    }
    return maxIt;
}
