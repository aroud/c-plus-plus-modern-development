#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;



int main() {
	size_t n;
	cin >> n;
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);
	reverse(v.begin(), v.end());

	do {
		for (auto el : v) {
			cout << el << ' ';
		}
		cout << '\n';
	} while (prev_permutation(v.begin(), v.end()));


	return 0;
}