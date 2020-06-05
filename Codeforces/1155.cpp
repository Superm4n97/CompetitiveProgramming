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

ll n,m,x[300006],p[300006];
map < ll ,ll > mp;
vll v,divisors;

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++)cin >> x[i];
    for (int i=1;i<n;i++){
        ll dif = x[i]-x[0];
        ll lim = sqrt(dif)+1;

        for (int i=2;i<=lim;i++){
            if (dif%i==0){
                while(dif%i==0)dif/=i;
                mp[i]++;
                if (mp[i]==1)v.pb(i);
            }
        }
        if (dif>2){
            mp[dif]++;
            if (mp[dif]==1)v.pb(dif);
        }
    }
    for (int i=0;i<v.size();i++){
        if (mp[v[i]] == n-1)divisors.pb(v[i]]);
    }



    return 0;
}
