#include <iostream>
 
using namespace std;
 
int main(){
  int A,B;
  cin>>A>>B;
  if(A<B){
  	int a=A;
    A=B;
    B=a;
  }//A>B
  for(int k=0;A-k>0;k++){
  	int a=A-k;
    int b=B-k;
    if(a<0){a=a*-1;}
    if(b<0){b=b*-1;}
    if(a==b){
      cout<<k;
      return 0;
    }
  }
  cout<<"IMPOSSIBLE";
  return 0;
}