#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	size_t n;
	std::cin >> n;
	std::vector<int> v;


	int t;
	int64_t sum = 0;
	for (size_t i = 0; i < n; ++i)
	{
		std::cin >> t;
		v.push_back(t);
		sum += t;
	}
	int64_t avg = sum / static_cast<int64_t>(n);
	std::cout << std::count_if(v.begin(), v.end(), [avg](int x) {return x > avg; }) << std::endl;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] > avg)
			std::cout << i << " ";
	}
	return 0;
}