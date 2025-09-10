#include <bits/stdc++.h>
using namespace std;

int dist(vector<int> is, int number, int index) {
  if (number + 1) {
    int is_m = binary_search(is.begin(), is.end(), index);
    return is_m;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> xs;
  vector<int> is;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    xs.emplace_back(k);
    if (k == 0)
      is.emplace_back(i);
  }

  for (int i = 1; i < is.size(); i++) {
    int dist = ((is[i] - is[i - 1]) - 1);
    for (int ii = 0; ii < dist; ii++) {
      if (ii < 9 || ii < (dist - 9)) {
        cout << ii % (dist - 9) << " ";
      } else
        cout << 9 << " ";
    }
  }
  cout << endl;
}
