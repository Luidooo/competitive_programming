#include <bits/stdc++.h>
using namespace std;
#define INF 10001

int main() {
  int n;
  cin >> n;
  vector<int> xs;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    xs.emplace_back(k);
  }

  vector<int> dx;
  int d = 0;
  bool zero = true;
  for (int i = 0; i < xs.size(); i++) {
    d++;
    if (xs[i] == 0) {
      d = 0;
      zero = false;
    }
    if (zero) {
      dx.emplace_back(INF);
      continue;
    }
    dx.emplace_back(d);
  }

  d = 0;
  vector<int> ex(n);
  zero = true;
  for (int i = xs.size() - 1; i >= 0; i--) {
    d++;
    if (xs[i] == 0) {
      d = 0;
      zero = false;
    }
    if (zero) {
      ex[i] = INF;
      continue;
    }
    ex[i] = d;
  }
  /*
  for (auto x : xs)
    cout << x << " ";
  cout << endl;
  for (auto x : dx)
    cout << x << " ";
  cout << endl;
  for (auto x : ex)
    cout << x << " ";
  cout << endl;

  cout << endl;
  */
  for (int i = 0; i < n; i++) {
    xs[i] = min(dx[i], ex[i]);
    if (xs[i] > 9)
      xs[i] = 9;
    cout << xs[i] << " ";
  }
  cout << endl;
}
