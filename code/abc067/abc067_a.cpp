#include <iostream>
 
using namespace std;
 
int main(){
  int A,B;
  cin>>A>>B;
  if(A%3==0){
    cout<<"Possible";
  }else if(B%3==0){
  	cout<<"Possible";
  }else if((A+B)%3==0){
  cout<<"Possible";
  }else{
  cout<<"Impossible";
  }
  return 0;
}
