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
    ll tc;
    scl(tc);

    while(tc--){
        ll b,w , i = 4;
        scll(b,w);
        vector < pll > ans;
        queue < ll > black , white;

        while(b&&w){
            if (i%2)black.push(i) , ans.pb({i,4}) , b--;
            else white.push(i) , ans.pb({i,4}) , w--;
            i++;
            if (!w && b){
                black.push(i) , ans.pb({i,4}) , b--;
                i++;
            }
        }
        //cout << "     1. "  << b << " " << w << endl;
        if (w)ans.pb({i,4}) , w--;
        if (b)ans.pb({3,4}) , b--;
        //cout << "     2. "  << b << " " << w << endl;

        while(w){
            if (black.empty())break;
            ans.pb({black.front() , 3});
            w--;

            if (!w)break;

            ans.pb({black.front() , 5});
            black.pop();
            w--;
           // cout << "     3. "  << b << " " << w << endl;
        }
        while(b){
            if (white.empty())break;
            ans.pb({white.front() , 3});
            b--;

            if (!b)break;

            ans.pb({white.front() , 5});
            white.pop();
            b--;
            //cout << "     4. "  << b << " " << w << endl;
        }

        if (b||w)cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i=0;i<ans.size();i++)cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    return 0;
}
