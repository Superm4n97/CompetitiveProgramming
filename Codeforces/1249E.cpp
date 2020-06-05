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
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf8            100000008

#define maxn            200005

using namespace std;

ll n,c;
ll A[maxn] , B[maxn] , ans[maxn] , L[maxn];

int main()
{
    scll(n,c);

    for (int i=1;i<n;i++){
        scl(A[i]);
    }
    for (int i=1;i<n;i++){
        scl(B[i]);
    }
    L[0] = c;
    for (int i=1;i<n;i++){
        L[i] = min(L[i-1]+B[i] , ans[i-1]+c+B[i]);
        ans[i] = min(ans[i-1]+A[i],L[i]);
    }
    for (int i=0;i<n;i++)cout << ans[i] << " ";
    cout << endl;



    return 0;
}

