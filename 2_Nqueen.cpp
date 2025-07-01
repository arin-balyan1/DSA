#include <bits/stdc++.h>
using namespace std;
int queen[100];
int check(int col,int row){
 for(int i=0;i<col;i++){
     int prerow=queen[i];
     if(prerow==row || (abs(prerow-row)==abs(i-col) )){
         return 0;
     }
 }
 return 1;
}
int rec(int level,int n){
if(level>n){
    return 0;
}
if(level==n){
    return 1;
}
int ans=0;
for(int i=0;i<n;i++){
    if(check(level,i)){
      queen[level]=i;
      ans+=rec(level+1,n);
      queen[level]=0;
    }
}
return ans;
}

int main() {
    memset(queen,0,sizeof(queen));
int n;
cin>>n;
 int s=rec(0,n);
 cout<<s<<endl;
    return 0;
}

//Compilation time 0.005s