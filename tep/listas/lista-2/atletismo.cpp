#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> atlets;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    atlets.push_back(make_pair(k, i));
  }
  sort(atlets.begin(), atlets.end());
  for (auto x : atlets) {
    // cout << x.first << " - " << x.second << endl;
    cout << x.second << endl;
  }

  // tem que printar a posicao do atleta de numero x
  // n-esimo print = posicao do atleta n-esimo
}
