#include <iostream>
using namespace std;

int main(){
  
  int n; cin >> n; int num;
  string a = "##", b = "..";
  for(int i=0;i<n;i++){
    cin >> num;
    for(int j=0;j<num;j++){
      for(int w=0;w<num+num;w++){
        for(int z=1;z<=num+num;z++){
          if(z % 2 != 0) cout << a;
          else cout << b;
        }
        cout << endl;
      }
    }
  }
}




