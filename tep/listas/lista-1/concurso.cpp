#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, c;
  cin >> k >> c;
  vector<int> xs;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    xs.emplace_back(x);
  }
  sort(xs.begin(), xs.end(), greater<int>());
  cout << xs[c - 1] << endl;
}
