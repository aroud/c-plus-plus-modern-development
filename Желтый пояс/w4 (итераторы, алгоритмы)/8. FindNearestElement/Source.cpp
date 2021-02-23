#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {

    if (!numbers.size())
        return numbers.begin();

    auto it = numbers.lower_bound(border);

    if (it == end(numbers))
        return prev(it);

    if ((*it) == border){
        return it;
    }
    else {
        if (it == begin(numbers)) {
            return it;
        }
        else {
            auto itp = prev(it);
            if (
                abs((*itp) - border) >
                abs((*it) - border)
                )
            {
                return it;
            }
            else {
                return itp;
            }

        }
    }
}


int main() {
    set<int> numbers = { 1, 4, 6 };
    cout <<
        *FindNearestElement(numbers, 0) << " " <<
        *FindNearestElement(numbers, 3) << " " <<
        *FindNearestElement(numbers, 5) << " " <<
        *FindNearestElement(numbers, 6) << " " <<
        *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}