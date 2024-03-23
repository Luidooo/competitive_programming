#include <iostream>
using namespace std;

int main(){

  int ans=0,a,b; 
  cin >> a >> b;
  if(a == b)
    cout << "1" << endl;
  else{
    while(b >= a){
      a = a * 3;
      b = b * 2;
      ans++;
    }
    cout << ans << endl;
  }
}
