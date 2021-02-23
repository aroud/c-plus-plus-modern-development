#include <iostream>
using namespace std;

int main() {
	unsigned long long n , ro;
	cin >> n >> ro;
	unsigned long long W, H, D;
	unsigned long long weight = 0ull;
	for (unsigned long long i = 0ull; i < n; ++i) {
		cin >> W >> H >> D;
		weight += W * H * D * ro;
	}
	cout << weight;
	return 0;
}