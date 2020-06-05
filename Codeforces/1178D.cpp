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

vll G[3000];
map < ll , ll > mp;
ll n , total = 0 , A[3000];

int main()
{
    mp[1] = 2;
    for (int i=2;i<3000;i++){
        if (mp[i]==0){
            mp[i] = 1;
            ll tut = i+i;
            while(tut<3000){
                mp[tut] = 2;
                tut+=i;
            }
        }
    }
    for (int i=1;i<3000;i++)if (mp[i]==2)mp[i] = 0;


    scl(n);
    if (n==2){
        cout << -1 << endl;
        return 0 ;
    }
   // cout << "n "  << n << endl;
    for (int i=1;i<=n;i++){
        A[i] = 2;
        total += 2;
       // cout << "   total " << total << endl;

        if (i==1){
            G[i].pb(n);
            G[i].pb(i+1);
        }
        else if (i==n){
            G[i].pb(1);
            G[i].pb(n-1);
        }
        else {
            G[i].pb(i-1);
            G[i].pb(i+1);
        }
    }

        for (int i=1;i+2<=n;i++){
            if(mp[total/2])break;
            if (G[i].size()==2){
                A[i]++;
                A[i+2]++;
                total+=2;
                G[i].pb(i+2);
                G[i+2].pb(i);
            }
   //cout << " total " << total << endl;
        }


    cout << total/2 << endl;
    map < pll , ll> mm;

    for (int _i=1;_i<=n;_i++){
        for (int i=0;i<G[_i].size();i++){
            if (!mm[{_i,G[_i][i]}]){
                cout << _i << " " << G[_i][i] << endl;
                mm[{_i,G[_i][i]}]++;
                mm[{G[_i][i],_i}]++;
            }
        }
    }

    return 0;
}

