#include <bits/stdc++.h>
using namespace std;

int main() {
  int p1, c1, p2, c2;
  cin >> p1 >> c1 >> p2 >> c2;
  int ld = p1 * c1;
  int le = p2 * c2;
  if (ld > le)
    cout << "-1";
  else if (ld < le)
    cout << "1";
  else
    cout << "0";
  cout << endl;
}
