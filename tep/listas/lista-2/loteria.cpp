#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> in;
  vector<int> out;
  for (int i = 0; i < 6; i++) {
    int k;
    cin >> k;
    in.push_back(k);
  }
  for (int i = 0; i < 6; i++) {
    int k;
    cin >> k;
    out.push_back(k);
  }
  sort(in.begin(), in.end());
  sort(out.begin(), out.end());
  int i = 0;
  for (auto x : in) {
    for (auto y : out) {
      if (x == y)
        i++;
    }
  }

  // cout << "i: " << i << endl;
  if (i < 3)
    cout << "azar";
  if (i == 3)
    cout << "terno";
  if (i == 4)
    cout << "quadra";
  if (i == 5)
    cout << "quina";
  if (i == 6)
    cout << "sena";
  cout << endl;
  return 0;
}
