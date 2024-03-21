#include <iostream>
using namespace std;

int main(){
  int numberJ, numberI;
  int plane[5][5];

  for(int i=0; i < 5;i++){
    for(int j=0; j < 5; j++){
      cin >> plane[i][j];
    }
  }

  for(int i=0; i < 5;i++){
    for(int j=0; j < 5; j++){
        if(plane[i][j] != 0){
          numberJ = j; numberI = i;
        }
    }
  }
  
  int aux=0;
    while(numberJ != 2 || numberI != 2){
    if(numberJ < 2){
      numberJ++; aux++; }
    if(numberJ > 2){
      if(numberJ == 2)
        numberJ = numberJ;
      numberJ--; aux++; }
    if(numberI < 2){
      numberI++; aux++; }
    if(numberI > 2){
      if(numberI == 2)
        numberI = numberI;
      numberI--; aux++; }
    //cout << numberI << " " << numberJ << endl;
  }
  cout << aux << endl;
}
