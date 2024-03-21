#include <iostream>
using namespace std;
  

int main(){
  int x=0, w; cin >> w;
  for(int i=0;i<w;i++){
    string sinal; cin >> sinal;
    int j=0;
    while(j < 3){
      if(sinal[j] == '+' || sinal[j] == '-'){
        if(sinal[j] == '+'){
          x++; break; }
        else{
          x--; break; }
      } 
      j++;
    }
    j=0;
  }
  cout << x << endl;
}


