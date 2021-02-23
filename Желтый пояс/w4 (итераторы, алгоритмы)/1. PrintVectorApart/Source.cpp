#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    auto it = find_if(numbers.begin(), numbers.end(), [](int x) {return x < 0; });
   
        reverse_copy(numbers.begin(), it, ostream_iterator<int>(cout, " "));
   
}


int main() {
    PrintVectorPart({ 6, 1, 8, -5, 4 });
    cout << endl;
    PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
    cout << endl;
    PrintVectorPart({ 6, 1, 8, 5, 4 });
    cout << endl;
    return 0;
}