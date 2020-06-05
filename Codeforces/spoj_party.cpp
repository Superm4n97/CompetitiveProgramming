#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define f first
#define s second


using namespace std;
vector< pair<int, int> >dp[505];

pair<int, int> knap(int pos, int moneyleft){
    if( pos == n +1 ) return mp(0,0);
    if(moneyleft == 0) return mp(0,0);

    int p = 0, paid = 0;
    if((dp[pos][moneyleft].f == -1) && (dp[pos][moneyleft].s == -1)){
        p = knap(i+1, moneyleft- pay[i]) + fun[i];

    }
    q = knap(i+1, moneyleft);

    if(p > q) paid += pay[i];
   dp[pos][moneyleft].f = max(p,q);
   dp[]
}



int main(){
   int mn, pr;

   while((cin >>mn >>pr) && ( (mn != 0) || (pr != 0)) ){
      for(int i=1; i<=pr; i++){
        cin >> pay[i] >> fun[i];
      }

   }
}
