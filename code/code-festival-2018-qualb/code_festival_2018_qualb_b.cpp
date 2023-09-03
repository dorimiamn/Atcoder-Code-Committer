#include <iostream>
#include <string>

using namespace std;

int main(){
  int N,X,a[101],b[101],max=0,num;
  cin>>N>>X;
  for(int i=0;i<N;i++){
  cin>>a[i]>>b[i];
    if(max<b[i]){
      max=b[i];
      num=i;
    }
  }
  a[num]+=X;
  num=0;
  for(int i=0;i<N;i++){
    num+=a[i]*b[i];
  }
  cout<<num;
  return 0;
}