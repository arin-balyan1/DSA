#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[1001][1001];
int dp[1001][1001];
int done[1001][1001];
int rec(int r,int c){
    if(r<0 || c<0){
        return -1e9;
    }
    if(r==0&&c==0){
        return arr[0][0];
    }
    if(done[r][c]){
     return dp[r][c];   
    }
    int ans=-1e9;
    
    if(r!=0){
        ans=max(ans,rec(r-1,c)+arr[r][c])
    }
    if(c!=0){
        ans=max(ans,rec(r,c-1)+arr[r][c]);
    }
    done[r][c]=1;//This done array is used becoz the actually value of dp can also gives -1 so to deal with that edge case
    return dp[r][c]=ans;
}

int main() {
  cin>>n>>m;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cin>>arr[i][j];
          done[i][j]=0;
      }
  }
  cout<<rec(n-1,m-1)<<endl;
	return 0;
}


//Time complexity of dp problem-> O(no. of state)(1+avg transition cost per state)