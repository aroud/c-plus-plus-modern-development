#include <map>
#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
T2& GetRefStrict(map<T1, T2>& m, T1 k) {
	if (m.find(k) == m.end())
		throw runtime_error("");
	else
		return m.at(k);
}

int main() {
	map<int, string> m = { {0, "value"} };
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}