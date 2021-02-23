#include "test_runner.h"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

template <typename T>
class Table {
public:
    Table(size_t _n, size_t _m) : n(_n), m(_m) {
        if (!n || !m) {
            n = 0;
            m = 0;
        }
        else {
            v.resize(n);
            for (auto& el : v) {
                el.resize(m);
            }
        }
    }
    void Resize(size_t _n, size_t _m) {
        if (!_n || !_m) {
            n = 0;
            m = 0;
            v.clear();
        }
        else {
            v.resize(_n);
            for (auto& el : v) {
                el.resize(_m);
            }
            n = _n;
            m = _m;
        }
    }
    vector<T>& operator[](int index) {
        return v[index];
    }
    const vector<T>& operator[] (int index) const {
        return v[index];
    }
    pair<size_t, size_t> Size() const{
        return { n,m };
    }
private:
    vector<vector<T>> v;
    size_t n;
    size_t m;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
