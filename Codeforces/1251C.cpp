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

#define maxn            100005

using namespace std;


int main()
{

    ll tc;
    scl(tc);
    while(tc--){
        string s , ans = "";
        cin >> s;
        vector < char > odd , even;
        for (int i=0;i<s.size();i++){
            if (s[i]%2)odd.pb(s[i]);
            else even.pb(s[i]);
        }
        ll ptrEVEN = 0 , ptrODD = 0;
        while(1){
            if (ptrODD==odd.size() && ptrEVEN==even.size())break;
            if (ptrODD==odd.size()){
                ans+=even[ptrEVEN];
                ptrEVEN++;
                continue;
            }
            if (ptrEVEN==even.size()){
                ans+=odd[ptrODD];
                ptrODD++;
                continue;
            }

            if (even[ptrEVEN]<odd[ptrODD]){
                ans+=even[ptrEVEN];
                ptrEVEN++;
            }
            else {
                ans+=odd[ptrODD];
                ptrODD++;
            }
        }
        cout << ans << endl;
    }





    return 0;
}
