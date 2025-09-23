#include <bits/stdc++.h>
using namespace std;

int compops(char k, char kop) {
  if (k == '<' && kop == '>')
    return 0;
  if (k == '(' && kop == ')')
    return 0;
  if (k == '{' && kop == '}')
    return 0;
  if (k == '[' && kop == ']')
    return 0;
  return 1;
}

int main() {
  stack<char> q;
  int sum = 0;
  for (char k; cin >> k;) {
    if (k == '<' || k == '(' || k == '{' || k == '[') {
      q.push(k);
    } else {
      if (!(q.empty())) {
        char w = q.top();
        sum += compops(w, k);
        q.pop();
      } else {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }

  if (!q.empty()) {
    cout << "Impossible" << endl;
  } else {
    cout << sum << endl;
  }
}
