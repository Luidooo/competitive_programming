#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> xs;
  for (int i = 0; i < n; i++) {
    int ni;
    cin >> ni;
    xs.emplace_back(ni);
  }

  int p;
  cin >> p;
  vector<int> ps;
  for (int i = 0; i < p; i++) {
    int ni;
    cin >> ni;
    ps.emplace_back(ni);
  }

  /*
  for (auto x : xs)
    cout << x << " ";
  cout << endl;
  for (auto x : ps)
    cout << x << " ";
  cout << endl;
  */

  int sell = 0;
  for (auto x : ps) {
    if (xs[x - 1]) {
      xs[x - 1]--;
      sell++;
    }
  }
  cout << sell << endl;
}
