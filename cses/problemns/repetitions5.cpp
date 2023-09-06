#include <bits/stdc++.h>
using namespace std;
#define max 1000001

int main()
{


    int tam,count=1, ans=0;
    string v;

    cin >> v;
    tam = v.size() -1;

    for(int i=1; i < tam; i++){
        if(v[i-1] == v[i]){
            count++;
        }
        else{
            if(count > ans){
                ans = count;
                count = 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
