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

string s  , ss = "";
ll k,n;
ll tc;

int main()
{
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        cin >> s;
        ss = "";
        ll tot = n/2;
        tot -= (k-1);
        //cout << ss << endl;
        for (int i=0;i<tot;i++)ss = ss+"(";
        for (int i=0;i<tot;i++)ss = ss+")";
        for (int i=0;i<k-1;i++)ss = ss+"()";

        vector < pll > ans;
        for (int i=0;i<n;i++){
            if (s[i]!=ss[i]){
                ll temp = 0;
                for (int j = i+1;j<n;j++){
                    if (s[j]!=s[i]){
                        temp = j;
                        break;
                    }
                }
                char ch1 = s[i] , ch2 = s[temp];
                s[i] = ch2;
                for (int j=i+1;j<=temp;j++)s[j] = ch1;
                ans.pb({i,temp});
            }
        }

//        cout << s << endl;
//        cout << ss << endl;

        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++){
            cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
        }
    }



    return 0;
}
