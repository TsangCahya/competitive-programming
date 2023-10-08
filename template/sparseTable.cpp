#include <bits/stdc++.h>
using namespace std;

const int MAX_N=200'005;
const int LOG=18;
int a[MAX_N];
int m[MAX_N][LOG]; //m[i][j] is mi nimum among a[i ,,, i+2^j-1];

int query(int L,int R){
    int length = R - L + 1;
    int k=0;
    while((1<<(k+1))<=length){
        k++;
    }
    return min(m[L][k],m[R-(1<<k)+1][k]);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    // 1) Read Input
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[i][0]=a[i];
    }
// 2) preprocessing, O(N*log(N))
    for(int k=1;k<LOG;k++){
        for(int i=0;i+(1<<k)-1<n;i++){
            m[i][k]= min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
        }
    }
  
    for(int i=0;i<q;i++){
        int L,R;
        cin>>L>>R;
        L--;
        R--;
        cout<<query(L,R)<<"\n";
    }
}
