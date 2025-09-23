#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;
  vector<char> s;
  for(char c; cin >> c;){ s.push_back(c); if(c == '1') sum++;}
  //for(auto x : s) cout << x;
  //cout << endl;
  cout << abs( n - (2*sum)) << endl;

}
