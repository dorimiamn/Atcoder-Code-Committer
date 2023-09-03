#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,max=0;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)cin>>a[i];
    map<int,int> MAPA;
    for(int i=0;i<N;i++){
        MAPA[a[i]]++;
    }
    for(int X=0;X<=99999;X++){
        int z=MAPA[X]+MAPA[X+1]+MAPA[X+2];
        if(max<z) max=z;
    }
    cout<<max<<endl;
    return 0;
}