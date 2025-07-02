#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>st;
int w,c,n;
int dp[101][101][101];
int rec(int level,int time_taken,int count) {
	if(level==n) {
		return 0;
	}
	if(dp[level][time_taken][count]!=-1){
	    return dp[level][time_taken][count];
	}
	//not take
	int ans=rec(level+1,time_taken,count);

	//take
	if(time_taken+st[level].second<=w && count+1<=c) {
		ans= max(ans,(st[level].first+rec(level+1,time_taken+st[level].second,count+1)));
	}

  dp[level][time_taken][count]=ans;
	return ans;
}
int main() {
	
	int a,b;
	cin>>n>>w>>c;
	memset(dp,-1,sizeof(dp));
	st.resize(n);
	for(int i=0; i<n; i++) {
		cin>>a>>b;
		st[i] = {a, b};
	}
	int k=rec(0,0,0);
	cout<<k<<endl;

	return 0;
}


//Time complexity of dp problem-> O(no. of state)(1+avg transition cost per state)