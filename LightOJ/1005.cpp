#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008

using namespace std;

ll ncr[32][32];

ll NCR(ll n, ll r)
{
    if (ncr[n][r] != -1)return ncr[n][r];
    if (r==0)return ncr[n][r] = 1;
    if (r==1)return ncr[n][r] = n;
    if (r==n)return ncr[n][r] = 1;

    return ncr[n][r] = NCR(n-1,r) + NCR(n-1,r-1);
}

int main()
{
    for (int i=0;i<32;i++){
        for(int j=0;j<=32;j++)ncr[i][j]=-1;
    }

    int tc;
    scd(tc);
    for (int _t=1;_t<=tc;_t++){
        ll n,k;
        scll(n,k);

        if (k>n){
            printf("Case %d: 0\n",_t);
            continue;
        }
        ll sum = 1 , temp = NCR(n,n-k);
        for (ll i=n; i>n-k ; i--)sum*=i;
        //cout << sum << " " << temp << endl;
        printf("Case %d: %lld\n",_t,sum*temp);
    }

    return 0;
}

