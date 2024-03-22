#include <iostream>
using namespace std;

int main(){

  int aux=0,n; cin >> n;
  char colors[n]; cin >> colors;
  for(int i=0;i<n;i++){
    if(colors[i] == colors[i+1]) aux++;
  }
  cout << aux << endl;
  

  return 0;
}
