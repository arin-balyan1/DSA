#include <bits/stdc++.h>
using namespace std;
int dp[100010];
int rec(int level,int n){
    int ways=0;
if(level>n){
return 0;
}
if(level==n){
    return 1;
}
if(dp[level]!=-1){
    return dp[level];
}
for(int i=1;i<=3;i++){
    if(level+i<=n){
        int ans=rec(level+i,n);
        ways+=ans;
    }
}
dp[level]=ways;
return ways;
}

int main() {
int n;
memset(dp,-1,sizeof(dp));
cin>>n;
int w=rec(0,n);
cout<<w<<endl;
    
    return 0;
}

//Compilation time 0.005s