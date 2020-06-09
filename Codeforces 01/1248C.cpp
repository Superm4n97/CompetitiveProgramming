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

#define mod             1000000007

using namespace std;

ll n,m;
ll F[maxn];

ll fibo(ll x)
{
    if (F[x] != -1)return F[x];
    if (x==0 || x==1){
        return F[0] = F[1] = 1;
    }
    F[x] = fibo(x-1)+fibo(x-2);
    F[x]%=mod;
    ll tt = F[x];
    tt%=mod;
    return tt;
}

int main()
{
    memset(F,-1,sizeof(F));
    scll(n,m);

    //cout << fibo(1)<< fibo(2)<< fibo(3) << fibo(4) << endl;

    if (n>m)swap(n,m);
    ll temp = fibo(m)*2;
    temp%=mod;
    if (n==1)cout << temp << endl;
    else if (n==2){
            temp+=2;
    temp%=mod;
        cout << temp << endl;
    }
    else if (n==3){
        temp+=4;
        temp%=mod;
    cout << temp << endl;
    }
    else {
        temp+=4;
        ll a = 2 ,b = 2;
        for (int i=4;i<=n;i++){
            ll tt = a+b;
            tt%=mod;

            temp+=tt;
            temp%=mod;

            a = b;
            b = tt;
        }
        cout << temp << endl;
    }




    return 0;
}
