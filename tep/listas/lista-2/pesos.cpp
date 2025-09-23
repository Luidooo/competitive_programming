#include <bits/stdc++.h>
using namespace std;

int main() {
  int c;
  cin >> c;
  vector<int> cxs;
  for (int k; cin >> k;) cxs.push_back(k);
  int cont=0;
  for(auto x : cxs){
    if((x-cont) > 8){
      cout << "N" << endl;
      return 0;
    }
    cont = x;
  }
  cout << "S" << endl;

}
