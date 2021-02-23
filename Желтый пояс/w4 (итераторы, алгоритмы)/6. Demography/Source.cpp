#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};


template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
        begin(range_copy), middle, end(range_copy),
        [](const Person& lhs, const Person& rhs) {
            return lhs.age < rhs.age;
        }
    );
    return middle->age;
}

void PrintStats(vector<Person> v) {
    cout << "Median age = " << ComputeMedianAge(v.begin(), partition(v.begin(), v.end(), [](Person& p) {return true; })) << '\n';
    cout << "Median age for females = " << ComputeMedianAge(
        v.begin(), 
        partition(
            v.begin(), v.end(), 
            [](Person& p) {return p.gender==Gender::FEMALE; }
        )
    ) << '\n';
    cout << "Median age for males = " << ComputeMedianAge(
        v.begin(),
        partition(
            v.begin(), v.end(),
            [](Person& p) {return p.gender == Gender::MALE; }
            )
        ) << '\n';
    cout << "Median age for employed females = " << ComputeMedianAge(
        v.begin(),
        partition(
            v.begin(), v.end(),
            [](Person& p) {return p.gender == Gender::FEMALE && p.is_employed; }
            )
        ) << '\n';
    cout << "Median age for unemployed females = " << ComputeMedianAge(
        v.begin(),
        partition(
            v.begin(), v.end(),
            [](Person& p) {return p.gender == Gender::FEMALE && !p.is_employed; }
        )
    ) << '\n';
    cout << "Median age for employed males = " << ComputeMedianAge(
        v.begin(),
        partition(
            v.begin(), v.end(),
            [](Person& p) {return p.gender == Gender::MALE && p.is_employed; }
        )
    ) << '\n';
    cout << "Median age for unemployed males = " << ComputeMedianAge(
        v.begin(),
        partition(
            v.begin(), v.end(),
            [](Person& p) {return p.gender == Gender::MALE && !p.is_employed; }
        )
    ) << '\n';

}

int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
