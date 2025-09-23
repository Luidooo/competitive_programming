#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  stack<char> q;
  for (char k; cin >> k;) {
    q.push(k);
  }
  while (!q.empty()) {
    if (q.top() == ')') {
      cout << "(";
      q.pop();
    } else {
      cout << q.top();
      q.pop();
    }
  }
  cout << endl;
}
