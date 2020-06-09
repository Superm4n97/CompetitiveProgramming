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

using namespace std;

int main()
{
    ll a1,a2,k2,k1,n , b1,c1;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    b1 = (k1-1)*a1 + (k2-1)*a2;
    ll temp = n-b1;
    if (temp<0)temp = 0;
    b1 = min( temp, a1+a2);

    if (k1>k2){
        c1 = min(n/k2,a2);
        ll tut = n-c1*k2;
        c1+=min(tut/k1,a1);
    }
    else {
        c1 = min(n/k1,a1);
        ll tut = n-c1*k1;
        c1+=min(tut/k2,a2);
    }
    cout << b1 << " "<< c1 << endl;

    return 0;
}
