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
    int  tc;
    scd(tc);

    while(tc--){
        ll A[5][105] , MX[5];
        ll n,m;
        scll(n,m);

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++)scll(A[i][j]);
        }
        for (int i=0;i<n;i++)MX[i] = A[i][0];

        for (int j=1;j<m;j++){
            ll MX2[5] , TEMP[5];
            memset(MX2,0,sizeof(MX2));
            memset(TEMP,0,sizeof(TEMP));

            for (int ro = 0 ; ro<n; ro++){
                for (int i=0;i<n;i++){
                    int tut = i+ro;
                    tut%=ro;
                }
            }
        }
    }

    return 0;
}
