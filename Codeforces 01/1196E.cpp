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
#define inf8            2000004

using namespace std;
int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
int main()
{
    ll tc;
    scl(tc);

    while(tc--){
        ll b,w;
        vector < pll > v;
        scll(b,w);
        queue < pll > white , black;
        map < pll , ll > mp;
        white.push({inf8,inf8});
        mp[{inf8,inf8}]++;

        while(!white.empty() || !black.empty()){
            if (b==0 && w == 0)break;
            if (b==0 && white.empty())break;
            if (w==0 && black.empty())break;
            if (!white.empty() && w){
                v.pb({white.front().first , white.front().second});///
                ll  x = white.front().first , y =white.front().second;

                for (int i=0;i<4;i++){
                    if (!mp[{x+del_x[i],y+del_y[i]}]){
                        black.push({x+del_x[i],y+del_y[i]});
                        mp[{x+del_x[i],y+del_y[i]}] = 1;
                    }
                }

                white.pop();
                w--;
            }
            if (!black.empty() && b){
                v.pb({black.front().first,black.front().second});
                ll  x = black.front().first , y =black.front().second;

                for (int i=0;i<4;i++){
                    if (!mp[{x+del_x[i],y+del_y[i]}]){
                        white.push({x+del_x[i],y+del_y[i]});
                        mp[{x+del_x[i],y+del_y[i]}] = 1;
                    }
                }

                black.pop();
                b--;
            }
        }
        if (w || b){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for (int i=0;i<v.size();i++){
                cout << v[i].first << " " << v[i].second << endl;
            }
        }
    }

    return 0;
}
