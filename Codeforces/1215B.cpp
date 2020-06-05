#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008
#define maxn            200005

using namespace std;

ll A[maxn] , E[maxn] , O[maxn];

int main()
{
    ll n;
    cin >> n;
    ll odd = 0 , even = 0;
    for (int i=1;i<=n;i++){
        scl(A[i]);
        if (A[i]<0){
            O[i] = E[i-1]+1;
            E[i] = O[i-1];
        }
        else {
            O[i] = O[i-1];
            E[i] = E[i-1]+1;
        }
       // cout << "  " << O[i]<< " " << E[i] << endl;
        odd+=O[i];
        even+=E[i];
    }
    cout << odd << " " << even << endl;

    return 0;
}
