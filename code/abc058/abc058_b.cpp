#include <iostream>
#include <string>

using namespace std;

int main(){
  string a,b,ans;
  int i=0,j=0;
  cin>>a>>b;
  int A=a.length();
  int B=b.length();
  for(int k=0;k<A+B;k++){
    if(k%2==0){
      ans.push_back(a[i]);
      i++;
    }else if(k%2==1){
      ans.push_back(b[j]);
      j++;
    }
  }
  cout<<ans;
  return 0;
}