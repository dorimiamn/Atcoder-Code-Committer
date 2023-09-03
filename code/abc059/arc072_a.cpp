#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int n,sum=0;
    long long ans=0,ans2=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    bool check1=true,check2=false;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(sum+a[i]>0){
                sum+=a[i];
            }else{
                sum+=a[i];
                for(int j=1; ;j++){
                    sum++;
                    ans++;
                    if(sum>0){
                        break;
                    }
                }
            }
        }else{
            if(sum+a[i]<0){
                sum+=a[i];
            }else{
                sum+=a[i];
                for(int j=1; ;j++){
                    sum--;
                    ans++;
                    if(sum<0){
                        break;
                    }
                }
            }
        }
    }
    sum=0;
    for(int i=0;i<n;i++){
        if(i%2==1){
            if(sum+a[i]>0){
                sum+=a[i];
            }else{
                sum+=a[i];
                for(int j=1; ;j++){
                    sum++;
                    ans2++;
                    if(sum>0){
                        break;
                    }
                }
            }
        }else{
            if(sum+a[i]<0){
                sum+=a[i];
            }else{
                sum+=a[i];
                for(int j=1; ;j++){
                    sum--;
                    ans2++;
                    if(sum<0){
                        break;
                    }
                }
            }
        }
    }
    if(ans>ans2) cout<<ans2;
    else cout<<ans;
    return 0;
}