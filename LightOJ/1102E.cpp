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

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vll v;
    inputll(v,n);
    map < ll , ll > mp;
    for (int i=0;i<n;i++)mp[v[i]]++;
    ll cnt=0;
    for (int i=n-1;i>=0;i--){
        if (mp[v[i]]==1)cnt++;
        else {
            for (int j=0;j<=n;j++){
                if (mp[v[j]]==1)cnt++;
                else break;
            }
            break;

        }
    }
    if (cnt==n)cnt--;
    ll tut = 1;
    for (int i=0;i<cnt;i++){
        tut*=2;
        tut%=998244353 ;
    }
    cout << tut << endl;

    return 0;
}
