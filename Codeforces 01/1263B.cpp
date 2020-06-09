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

        ll A[15];
        memset(A,0,sizeof(A));
        map < string , ll > mp;
        vector < string > vs;

        for (int i=0;i<n;i++){
            string s;
            cin >> s;
            vs.pb(s);
            if (mp[s]==0){
                mp[s] = 1;
            }
            else A[i] = 1;
        }
        ll cnt = 0;
        for (int i=0;i<n;i++){
            string s = vs[i];
            if (A[i]==1){
                for (int j = 0;j<4;j++){
                    bool solve = false;
                    for (char c = '0' ; c<='9';c++){
                        s[j] = c;
                        if (mp[s]==0){
                            vs[i] = s;
                            mp[s]++;
                            solve = true;
                            cnt++;
                            break;
                        }
                    }
                    if (solve)break;
                }
            }
        }
        cout << cnt << endl;
        for (int i=0;i<n;i++){
            cout << vs[i] << endl;
        }
    }


    return 0;
}
