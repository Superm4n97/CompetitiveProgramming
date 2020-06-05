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
        ll x = 0 , n,a, b , cnt = 0;
        string s;
        scl(n);
        scll(a,b);
        cin >> s;
        ll ans = n*a + (n+1)*b , pillers = 0;

       // cout << "  " << ans << endl;
        for (int i=0;i<n-1;i++){
            if (s[i]=='0' && s[i+1]=='0')cnt++;
            if (s[i]=='0' && s[i+1]=='1'){
                if (x==0){
                    ans+=a;
                    x = 1;
                    cnt = 0;
               // cout << "   3  " << ans << endl;
                    continue;
                }


                ll tut = 2*a;
                //if (x==0)tut -= a;

                if (cnt*b < tut){
                    ans+=cnt*b;
                }
                else {
                    ans+=tut;
                }
                x = 1;
                cnt = 0;
            }
        }
        if (x==1)ans+=a;

        //cout << "  " << ans << endl;

        for (int i=0;i<n;i++){
            if (s[i]=='1')pillers++;
            else {
                if (pillers!=0){
                    pillers++;
                    ans+=(pillers)*b;

                }
                pillers = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
