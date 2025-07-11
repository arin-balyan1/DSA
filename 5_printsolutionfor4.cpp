#include <bits/stdc++.h>
using namespace std;
vector<int>st;
vector<int>v;
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
 void print(int level,int left){
     if(level==n){
         return;
     }
     if(rec(level+1,left)==1){
         print(level+1,left);
     }
     else if(rec(level+1,left-st[level])==1){
         cout<<st[level]<<endl;
         print(level+1,left-st[level]);
     }
     
 }

int main() {
cin>>n>>t;	
st.resize(n);int a;
memset(dp,-1,sizeof(dp));
for(int i=0;i<n;i++){
    cin>>a;
    st[i]=a;
}
if(rec(0,t)){
    print(0,t);
}
	return 0;
}


//Time complexity of dp problem-> O(no. of state)(1+avg transition cost per state)

//void printall(int level,int left,vector<int>&cur){
//      if(level==n){
//     for(auto v:cur){
 //     cout<<v<<" ";}
 //     cout<<endl;
//          return;
//      }
//      if(rec(level+1,left)==1){
//          print(level+1,left);
//      }
//      else if(rec(level+1,left-st[level])==1){
//          cur.push_back(st[level]);
//          printall(level+1,left-st[level]);
//          cur.pop_back();
//      }
     
//  }