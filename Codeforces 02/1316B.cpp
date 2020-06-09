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
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n , ans= 1;
        string s , sst;

        cin >> n;
        cin >> s;

        //vector < pair < string , ll > > vp;
        //vp.pb({s,1});
        sst = s;

        for (int i=2;i<=n;i++){
            string st = s.substr(i-1,n-i+1);
            //for (int j= i-1 ; j<n;j++)st = st+s[j];
            ll temp = n-i+1;
            if (temp%2){
                string ss = s.substr(0,i-1);
                reverse(ss.begin(),ss.end());
                st = st+ss;
            }
            else st = st+s.substr(0,i-1);

            if (st<sst){
                sst = st;
                ans = i;
            }
            //vp.pb({st,i});
        }
        cout << sst << endl;
        cout << ans << endl;
    }



    return 0;
}
