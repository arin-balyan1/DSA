#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>v;
int dp[200];
int rec(int level){
    if(level<0){
        return 0;
    }
if(dp[level]!=-1){
    return dp[level];
}
    int ans=1;
    for(int prev=0;prev<level;prev++){
        if(v[prev]<v[level]){
            ans=max(ans,rec(prev)+1);
        }
    }
 dp[level]=ans;
    return ans;
}
int main(){
 cin>>n;
 memset(dp,-1,sizeof(dp));
 v.assign(n,-1);
 for(int i=0;i<n;i++){
    cin>>v[i];
 }
int best=1;
for(int i=0;i<n;i++){
    best=max(best,rec(i));
}
cout<<best<<endl;

    return 0;
}