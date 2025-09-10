#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p;
  cin >> n >> p;
  int d = 0, b = 1;

  // a cada dia cada bacteria vira p
  // ou seja, tenho b backterias, b * p
  while (b <= n) {
    if (b == n) {
      cout << d << endl;
      return 0;
    }
    b *= p;
    d++;
  }
  cout << d - 1 << endl;
}
