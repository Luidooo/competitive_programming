#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  int min = s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s += x;
    min > s ? min = s : min = min;
  }
  cout << min << endl;
}
