#include <iostream>
using namespace std;

int main(){
  int loops; cin >> loops;
  for(int i=0;i<loops;i++){
    string in; cin >> in;
    if(in[0] == '0' && in[1] != '0') cout << in << " AM" << endl;
    else{
      if(in[0] == '0' && in[1] == '0') cout << "12:" << in[3] << in[4] << " AM" << endl;
      if(in[0] >= 1) cout << "0" << in[1]-2 << ":" << in[3] << in[4] << " PM"<< endl; }
  }
    
}
