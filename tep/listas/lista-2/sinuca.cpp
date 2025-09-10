#include <bits/stdc++.h>
using namespace std;

void sinuca(vector<int> bs) {
  // for (auto x : bs)
  // cout << x << " ";
  // cout << endl;
  if (bs.size() == 1) {
    if (bs.front() == 1)
      cout << "preta" << endl;
    else
      cout << "branca" << endl;
    return;
  }
  vector<int> tmp;
  for (int i = 1; i < bs.size(); i++) {
    if (bs[i] == bs[i - 1])
      tmp.push_back(1);
    else
      tmp.push_back(-1);
  }
  sinuca(tmp);
}

int main() {
  int k;
  cin >> k;
  vector<int> ft;
  for (int j; cin >> j;)
    ft.push_back(j);
  sinuca(ft);
}
