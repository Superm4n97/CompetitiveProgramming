#include <bits/stdc++.h>
#define pb(a)           push_back(a)
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
#define mk              make_pair
#define inf8            100000008

using namespace std;

ll h,n;
ll A[200005] , C[200005] , mn=0;

int main()
{
    cin >> h >> n;
    for (int i=1;i<=n;i++)scl(A[i]) , C[i] = C[i-1]+A[i] , mn = min(mn,C[i]);
    if (mn == 0 || (mn*-1<h && C[n]>=0)){
        cout << -1 << endl;
        return 0;
    }

    for (int i=1;i<=n;i++)cout << C[i] << " ";
    cout << endl;

    ll temp = h + mn  , ans =0 , tut = 0, t = C[n];

    cout << "    " << temp << endl;
    if (temp < 0) temp = 0;
    if (t < 0)t*=-1;
    if (C[n] != 0) tut = temp/t;
    if (tut*t != temp)tut++;
    h -= temp;

    cout << h << endl;
    for (int i=1;i<=n;i++){
        ans++;
        if (h+C[i] <= 0)break;
    }
    cout << "   " << ans << " " << tut << endl;
    cout << ans+tut*n << endl;


    return 0;
}

