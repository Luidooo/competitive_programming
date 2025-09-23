#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  vector<int> nts;
  for (int i = 0; i < 5; i++) {
    int k;
    cin >> k;
    nts.push_back(k);
  }
  int m = 0, s=0, snd=0;
  bool acho=true;
  for (auto x : nts) {
    if (x == nts[0]){
      m++;
    }
    else{
      if(acho){
        snd = x;
        acho = false;
      }
      if(x == snd) s++;
    }
  }
  cout << m << " " << s << endl;
}
