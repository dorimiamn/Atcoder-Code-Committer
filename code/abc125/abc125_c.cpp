#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF = 1e13 + 7;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T, class Y>
T GCD(T a, Y b)
{
    if(a<b){
        int c=a;
        a=b;
        b=c;
    }
    if (a % b == 0)
    {
        return b;
    }
    return GCD(b, a % b);
}

#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int N,max=0;
    cin >> N;
    int A[N + 2];
    int L[N + 2], R[N + 2];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    L[0] = A[0], R[N] = A[N - 1];
    for (int i = 1; i <= N; i++)
    {
        L[i] = GCD(L[i - 1], A[i-1]);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        R[i] = GCD(R[i + 1], A[i]);
    }
    int M[111111];
    for (int i = 0; i < N; i++)
    {
        if(i==0){
            M[i]=R[i+1];
        }else if(i==N-1){
            M[i]=L[i];
        }else{
            M[i] = GCD(L[i], R[i + 1]);
        }
    }
    for(int i=0;i<N;i++)if(max<M[i])max=M[i];
    cout << max << endl;
    return 0;
}

//a=97,z=122