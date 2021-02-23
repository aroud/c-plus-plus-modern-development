#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);

    RandomIt mid = elements.begin() + (elements.end() - elements.begin()) / 2;
    

    MergeSort(elements.begin(), mid);
    MergeSort(mid, elements.end());

    merge(elements.begin(), mid, mid, elements.end(), range_begin);
}


int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}