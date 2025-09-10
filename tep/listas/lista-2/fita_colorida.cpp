#include <bits/stdc++.h>
using namespace std;

// eu tenho que printar de tras pra frente, afinal, o buffer de print é uma
// pilha

int main() {
  int n;
  cin >> n;
  vector<int> xs;
  vector<int> in;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k == 0)
      in.emplace_back(i + 1);
    xs.emplace_back(k);
  }

  // tenho que descobrir a distancia entre os zeros do meio
  // já tenho as um vetor com as distancia
  // agora verificar quem esta mais perto de quem

  vector<int> dists;
  dists.emplace_back(in[0]);
  for (int i = 1; i < in.size(); i++) {
    int d = in[i] - in[i - 1];
    dists.emplace_back(d);
  }
  cout << "distancias: " << endl;
  for (auto x : dists)
    cout << x << " ";
  cout << endl;

  for (int i = in[0]; i > 1; i--)
    cout << i << " ";
  for (int i = 1; i < in.size(); i++) {
    cout << "vendo dist: " << in[i] << endl;
    if (in[i] >= 18) {
      n = in[i];
      while (n--)
        cout << n << " ";
    }
  }
}
