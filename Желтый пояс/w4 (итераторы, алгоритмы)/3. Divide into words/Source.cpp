#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<std::string> SplitIntoWords(const std::string& s)
{
    std::vector<std::string> result;

    auto left_border = std::begin(s);
    auto right_border = std::begin(s);

    while (right_border != s.end())
    {
        left_border = right_border;
        right_border = std::find(left_border, s.end(), ' ');

        result.push_back({ left_border, right_border });

        if (right_border != s.end())
        {
            ++right_border;
        }
    }

    return result;
}


int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}