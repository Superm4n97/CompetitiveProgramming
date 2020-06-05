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

int main()
{
    ll n,m;
    cin >> n >> m;
    ll a1=0,a2=0,b1=0,b2=0;
    for(int i=0;i<n;i++){
        ll a;
        cin >> a;
        if (a%2)a1++;
        else b1++;
    }
    for (int i=0;i<m;i++){
        int a;
        cin >> a ;
        if (a%2)a2++;
        else b2++;
    }
    cout << min(a1,b2)+min(b1,a2);

    return 0;
}

