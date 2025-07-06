#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1001][1001];
int rec(int l,int r){

    if(l+1<=r){
        return 0;
    }
   if(dp[l][r]!=-1){
    return dp[l][r];
   }
    int ans=1e9;

    for(int i=l+1;i<r;i++){
     ans=min(ans,x[r]-x[l]+rec(l,i)+rec(i,r));
    }
    return dp[l][r]=ans;
}
int main(){
 cin>>n;
  cout<<rec(0,n)<<endl;
    return 0;
}