#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> xs;
  for (int i = 0; i < 3; i++) {
    int id;
    cin >> id;
    xs.emplace_back(id);
  }
  sort(xs.begin(), xs.end());
  cout << xs[1] << endl;
}
