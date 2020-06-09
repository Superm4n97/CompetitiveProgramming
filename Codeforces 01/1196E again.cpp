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
#define inf8            1000000

using namespace std;

ll del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};

int main()
{
    ll tc;
    scl(tc);

    while(tc--){
        map < pll , ll > mp;
        vector < pll > ans;
        queue < pll > white , black;

        ll w,b;
        scll(b,w);
        white.push({inf8,inf8});
        mp[{inf8,inf8}] = 1;

        while(b>0 || w>0){

            if (!b && white.empty())break;
            if (!w && black.empty())break;

            if (w){
                ans.pb({white.front().first,white.front().second});
                w--;
                ll x = white.front().first , y = white.front().second;
                white.pop();

                for (ll i=0;i<4;i++){
                    if (!mp[{ x+del_x[i] , y+del_y[i] }]){
                        black.push({x+del_x[i] , y+del_y[i] });
                        mp[{x+del_x[i] , y+del_y[i]}] = 1;
                    }
                }
            }

            if (!b && white.empty())break;
            if (!w && black.empty())break;

            if (b){
                ans.pb({black.front().first , black.front().second});
                b--;
                ll x = black.front().first , y = black.front().second;
                black.pop();

                for (ll i=0;i<4;i++){
                    if (!mp[{x+del_x[i],y+del_y[i]}]){
                        white.push({x+del_x[i] , y+del_y[i]});
                        mp[{x+del_x[i] , y+del_y[i]}] = 1;
                    }
                }
            }
        }
        if (w || b)cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            for (int i=0;i<ans.size();i++){
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
    }

    return 0;
}
