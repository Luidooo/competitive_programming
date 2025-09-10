#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  vector<int> xs;
  int ft = 0, snd = 0;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    // cout << ft << " " << snd << " " << k << endl;
    if (ft > snd && k > snd) {
      cout << "S" << endl;
      return 0;
    }
    xs.push_back(k);
    ft = snd;
    snd = k;
  }
  cout << "N" << endl;
}
