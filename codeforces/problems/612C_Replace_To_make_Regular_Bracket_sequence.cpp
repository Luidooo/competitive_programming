#include <bits/stdc++.h>
using namespace std;

/*
 * pode substituir um aberto por um fechados, mas o contrario nao
 * o algoritmo já indetinfica se a quant de aberto e fechado é a mesma
 * mas nao verifica quantos precisamos mudar, podemos usar 3 pilhas diferentes para resolver isso
*/
 
int main(){
  stack<char> q;
  for(char k; cin >> k;){
    if(k == '<' || k == '(' || k == '{' || k == '[')
      q.push(k);
    else{
      if(!(q.empty())) {
        q.pop();
        continue;
      }
      else{
        cout << "impossible" << endl;
        return 0;
      }
    }

  }

  cout << q.size() << endl;
   
}
