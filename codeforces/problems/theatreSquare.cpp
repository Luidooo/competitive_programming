#include <iostream>
#include <cmath>

using namespace std;

int main(){

 long long int m,n,a; cin >> m >> n >> a;
  long long int bottomT = m/a; long long int leftT = n/a;
  bottomT = m%a != 0? ++bottomT : bottomT;
  leftT = n%a != 0? ++leftT : leftT;
  //if(leftT % a != 0) ++leftT;
  //if(bottomT % a != 0) ++bottomT;
  cout << bottomT*leftT << endl;

  

}

