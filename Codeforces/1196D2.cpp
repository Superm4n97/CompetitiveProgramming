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

string reff = "RGB";

int main()
{
    ll tc;
    scl(tc);
    while(tc--){
        ll n, k;
        scll(n,k);
        ll A[5][n+4];
        for (int i=0;i<4;i++){
            for (int j=0;j<=n;j++){
                A[i][j] = 0;
            }
        }

        string s;
        cin >> s;
        ll t1 = 0 , t2= 1 , t3= 2;

        for (int i=0;i<n;i++){
            t1 = (t1+1)%3;
            t2 = (t2+1)%3;
            t3 = (t3+1)%3;

            if (reff[t1]==s[i])A[1][i+1] = 0;
            else A[1][i+1] = 1;

            if (reff[t2]==s[i])A[2][i+1] = 0;
            else A[2][i+1] = 1;

            if (reff[t3]==s[i])A[3][i+1] = 0;
            else A[3][i+1] = 1;
        }


        for (int i=1;i<=3;i++){

            for (int j=1;j<=n;j++){
                A[i][j] += A[i][j-1];
            }
        }
        ll ans = inf8;
        for (int i=1;i<=3;i++){
            for (int j=k;j<=n;j++){
                ans = min(ans,A[i][j]-A[i][j-k]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
