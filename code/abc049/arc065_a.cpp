#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  string divide[4]={"dream","dreamer","erase","eraser"};
  string S;
  cin>>S;
  reverse(S.begin(),S.end());
  for(int i=0;i<4;i++) reverse(divide[i].begin(),divide[i].end());
  
  for(int i=0;i<S.length();){
    bool can2=false;
  	  for(int j=0;j<4;j++){
      	    string d=divide[j];
    		if(S.substr(i,d.size())==d){
        		can2=true;
        		i+=d.size();
        }
    }
      if(!can2){
      	cout<<"NO"<<endl;
        return 0;
      }
  }
  cout<<"YES"<<endl;
  return 0;
}