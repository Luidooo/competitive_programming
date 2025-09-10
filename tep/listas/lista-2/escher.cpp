#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> xs;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    xs.emplace_back(k);
  }

  if (n % 2 == 0) {
    int end = n - 1;
    int sum = xs[0] + xs[n - 1];
    for (int i = 0; i < n / 2; i++) {
      if (xs[i] + xs[end] == sum) {
        end--;
        continue;
      } else {
        cout << "N" << endl;
        return 0;
      }
    }
    cout << "S" << endl;
    return 0;
  } else {
    // cout << "impar " << endl;
    int end = n - 1;
    int sum = xs[0] + xs[n - 1];
    for (int i = 0; i < n / 2; i++) {
      if (xs[i] + xs[end] == sum) {
        // cout << xs[i] << " " << xs[end] << endl;
        end--;
        continue;
      }
      cout << "N" << endl;
      return 0;
    }
    // cout << xs[n / 2] << " " << sum << endl;
    if ((!(sum % 2 == 0)) && (!(xs[n / 2] % 2 == 0)))
      cout << "N" << endl;
    else {
      2 * xs[n / 2] == sum ? cout << "S" : cout << "N";
      cout << endl;
    }
    return 0;
  }
}
