#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int A,B,C,D,E,F,Msum=0,MG=0;
    double per=0.0,max=0.0;
    cin>>A>>B>>C>>D>>E>>F;
    if(A<B){
        int a=A;
        A=B;
        B=a;
    }
    A*=100;
    B*=100;
    bool check=true;
    for(int i=0;i<=F/A+1;i++){
        check=true;
        for(int j=0;j<=F/C+1;j++){
            for(int k=0;k<=F/B+1;k++){
                for(int l=0;l<=F/D+1;l++){
                    int a=A*i;
                    int b=B*k;
                    int c=C*j;
                    int d=D*l;
                    double e=(c+d);
                    int f=((a+b)/100)*E;
                    double sum=a+b+c+d;
                    if(F>=sum&&sum!=0&&f>=e){
                        per=double(e/sum)*100;
                        if(per>max){
                            max=per;
                            Msum=sum;
                            MG=e;
                        }
                    }
                }
            }
        }
    }
    if(Msum==0&&F>=B){
        Msum=B;
    }
    cout<<Msum<<endl<<MG;
    return 0;
}