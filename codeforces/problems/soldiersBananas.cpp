#include <iostream>
using namespace std;

int main(){

  int k, n, w;
  cin >> k >> n >> w;
  int price=0, sum=0;
  for(int i=0;i<w;i++){
    price += k;
    sum += price;
  }
  
  if(sum-n < 0) 
    cout << "0" << endl;
  else
    cout << sum-n << endl;

  return 0;
}
