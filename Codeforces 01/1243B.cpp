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
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        vector < pll > ans;
        bool sol = true;
        for (int i=0;i<n;i++){
            if (s[i]!=t[i]){
                for (int j=i+1;j<n;j++){
                    if (s[i]==s[j]){
                        ans.pb({j,i});
                        swap(s[j],t[i]);
                        break;
                    }
                }
                if (s[i]!=t[i]){
                    for (int j=i+1;j<n;j++){
                        if (s[i] == t[j]){
                            ans.pb({j,j});
                            swap(s[j],t[j]);
                            ans.pb({j,i});
                            swap(s[j],t[i]);
                            break;
                        }
                    }
                }
                if (s[i]!=t[i])sol = false;
            }
        }
        if (!sol || s!=t){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
//            cout << s << endl;
//            cout << t << endl;

            if(ans.empty()){
                cout << 1 << endl;
                cout <<"1 1" << endl;
                continue;
            }
            cout << ans.size() << endl;
            for (int i=0;i<ans.size();i++){
                cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
            }
        }
    }



    return 0;
}
