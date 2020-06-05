#include<bits/stdc++.h>
using namespace std;

int dp[5001], arr[5000], n;

int f(int i){
    if(i > n) return 10000000;
    if(i == n) {
        return arr[n];
    }
     int p=0, q=0;
     if(dp[i] != -1) return dp[i];
     p = f(i+2) + arr[i];
     q = f(i+3) + arr[i];

     return dp[i] = min(p,q);
 }


int main(){
  cin >>n;
  for(int j=0; j<500; j++){ dp[j] = -1; }

  for(int i=1; i<=n; i++) cin>>arr[i];
  //for (int i=1;i<=10;i++) cout << arr[i] <<  " ";

  int ans = f(1);
  cout<<ans<<endl;
}
