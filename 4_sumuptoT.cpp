#include <bits/stdc++.h>
using namespace std;
vector<int>st;
int n,t;
int dp[100][100];
int rec(int level,int left) {
 if(left==0)
{
    return 1;
}
if(level==n){
  return 0;  
}
if(dp[level][left]!=-1){
    return dp[level][left];
}
int ans=0;
//not to take
 if(rec(level+1,left)==1){
     ans=1;
 }
 
 //take
 if(rec(level+1,left-st[level])==1){
     ans=1;
 }
 dp[level][left]=ans;
 return ans;    
 }

int main() {
    int q;
cin>>n>>q;	
st.resize(n);int a;

for(int i=0;i<n;i++){
    cin>>a;
    st[i]=a;
}
memset(dp,-1,sizeof(dp));//Time complexity hack->O(no.of states)(DP) number of times memset occur we have to this complexity becoz of recomputing and resaving the dp array
while(q--){
cin>>t;
cout<<rec(0,t)<<endl;//assume this as O(1)
}
	return 0;
}


//Time complexity of dp problem-> O(no. of state)(1+avg transition cost per state)