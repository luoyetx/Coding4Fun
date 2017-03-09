#include "skiplist.h"
#include <iostream>

using namespace std;

namespace ds {

void TestSkipList() {
  cout << "Testing SkipList" << endl;
  SkipList<int, int> spl;
  SetRandomSeed();
  const int N = 10;
  std::vector<std::pair<int, int> > data(N);
  for (int i = 0; i < N; i++) {
    data[i] = make_pair(rand(), rand());
    spl.Insert(data[i].first, data[i].second);
  }
  int dummy;
  CHECK_EQ(spl.Length(), N);
  CHECK_EQ(spl.Delete(rand()), false);
  CHECK_EQ(spl.Search(rand(), dummy), false);
  int idx = rand() % N;
  CHECK_EQ(spl.Search(data[idx].first, dummy), true);
  CHECK_EQ(data[idx].second, dummy);
  spl.Print(cout);
  idx = rand() % N;
  CHECK_EQ(spl.Delete(data[idx].first), true);
  CHECK_EQ(spl.Length(), N - 1);
  spl.Print(cout);
}

}