#include <bits/stdc++.h>
using namespace std;
string a,b;int n,m;
int dp[1001][1001];
int rec(int i,int j){
    if(i>=n || j>=m){
        return 0;
    }
   if(dp[i][j]!=-1){
    return dp[i][j];
   }
    int ans=0;
    ans=max(ans,rec(i+1,j));
    ans=max(ans,rec(i,j+1));
    if(a[i]==b[j]){
        ans=max(ans,1+rec(i+1,j+1));
    }
return dp[i][j]=ans;

}

int main(){
    cin>>n>>m;
cin>>a>>b;
memset(dp,-1,sizeof(dp));
cout<<rec(0,0)<<endl;
    return 0;
}