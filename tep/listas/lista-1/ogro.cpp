#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, e;
  cin >> d >> e;
  d > e ? cout << e + d : cout << abs(2 * (d - e));
  cout << endl;
}
