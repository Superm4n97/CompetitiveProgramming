#include<bits/stdc++.h>
using namespace std;

int dp[500][500];

int f(int i, int j){
   if(i == n+1) return 0;
   if(j==0) return 0;
   int p=0;
   if(dp[i][j] != -1){
     return dp[i][j];
   }

   if(j-w[j] >=0) p=f(i+1, j-w[j]) + v[j];
   int q = f(i+1, j);
   int mx = max(p, q);

   return dp[i][j] = mx;
 }

int main()
{
  int n;
  cin >>n;

  int v[n], w[n];
  for(int i=0; i<n; i++){
    cin>>w[i]>>v[i];
  }
  int w;
  cin >>w;

  int a = f(1,w);


}
