#include <bits/stdc++.h>
using namespace std;

int main() {
  int vic = 0;
  for (int i = 0; i < 6; i++) {
    char v;
    cin >> v;
    if (v == 'V')
      vic++;
  }

  if (vic > 0) {
    if (vic > 2) {
      if (vic > 4) {
        cout << "1" << endl;
      } else {
        cout << "2" << endl;
      }
    } else {
      cout << "3" << endl;
    }
  } else {

    cout << "-1" << endl;
  }
}
