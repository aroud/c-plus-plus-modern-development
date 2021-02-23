#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational();
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }

};
void Test() {
    Rational r0;
    AssertEqual(r0.Numerator(), 0);
    AssertEqual(r0.Denominator(), 1);

    Rational r1(0,9);
    AssertEqual(r1.Numerator(), 0);
    AssertEqual(r1.Denominator(), 1);

    Rational r2(0,-9);
    AssertEqual(r2.Numerator(), 0);
    AssertEqual(r2.Denominator(), 1);


    Rational r3(1,2);
    AssertEqual(r3.Numerator(), 1);
    AssertEqual(r3.Denominator(), 2);

    Rational r4(2,4);
    AssertEqual(r4.Numerator(), 1);
    AssertEqual(r4.Denominator(), 2);

    Rational r5(-2,4);
    AssertEqual(r5.Numerator(), -1);
    AssertEqual(r5.Denominator(), 2);

    Rational r6(2,-4);
    AssertEqual(r6.Numerator(), -1);
    AssertEqual(r6.Denominator(), 2);

    Rational r7(-2,-4);
    AssertEqual(r7.Numerator(), 1);
    AssertEqual(r7.Denominator(), 2);

    Rational r8(2,-1);
    AssertEqual(r8.Numerator(), -2);
    AssertEqual(r8.Denominator(), 1);

    Rational r9(-2, -1);
    AssertEqual(r9.Numerator(), 2);
    AssertEqual(r9.Denominator(), 1);



}

int main() {
  TestRunner runner;
  runner.RunTest(Test,"test");
  return 0;
}
