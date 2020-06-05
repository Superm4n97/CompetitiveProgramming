#include <bits/stdc++.h>
#define pb           push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008
#define maxn            1004
#define mod             1000000007

using namespace std;


ll A[maxn][maxn] ;
string s;

ll dpFunction(ll l, ll r)
{
    if (l>r)return 0;
    if (l == r)return 1;
    if (A[l][r] != 0)return A[l][r];

    if (s[l]==s[r])return A[l][r] = dpFunction(l+1,r-1)+2;
    else return A[l][r] = max(dpFunction(l,r-1) , dpFunction(l+1,r));
}

int main()
{
    ll tc;
    scl(tc);
    for (int i=1;i<=tc;i++){
        cin >> s;
        ll n = s.size();
        memset(A,0,sizeof(A));

        cout << "Case "<< i << ": "<< n-dpFunction(0,n-1) << endl;
    }



    return 0;
}


