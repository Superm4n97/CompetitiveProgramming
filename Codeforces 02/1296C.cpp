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
        ll n;
        cin >> n;
        string s;
        cin >> s;

        map < pll , ll > mp;
        ll L = 0 , U = 0, R =0 , D = 0;
        ll seg=inf ,x ,y;

        for (int i=0;i<n;i++){
            if (s[i]=='U')U++;
            if (s[i]=='D')D++;
            if (s[i]=='L')L++;
            if (s[i]=='R')R++;

            ll dl = L - R , dd = D - U;

            if (mp[{dl,dd}] || (dl == 0 && dd == 0)){
                ll len = 0;
                if (dl==0 && dd==0 && mp[{dl,dd}]==0)len = i+1;
                else {
                    len = i+1 - mp[{dl,dd}];
                }

                //show(len);

                if (len<seg){
                    seg = len;
                    x = mp[{dl,dd}]+1 , y = i+1;
                }
                mp[{dl,dd}] = i+1;
            }
            else {
                mp[{dl,dd}] = i+1;
            }
        }

        if (seg != inf){
            cout << x << " " << y << endl;
        }
        else cout << -1 << endl;
    }


    return 0;
}

