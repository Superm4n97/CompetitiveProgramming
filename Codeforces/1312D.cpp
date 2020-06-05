#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define pb              push_back
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
#define printCaseAnsInt(t,ans)  printf("Case %d: %d",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld",t,ans)
#define mod             998244353
#define maxn            2000005;

using namespace std;

ll n,m;
ll F[200005] , P[200005];

ll bigmod(ll a, ll p)
{
    if (p==0)return 1;
    if (p==1)return a%mod;

    ll temp = bigmod(a,p/2);

    temp*=temp;
    temp%=mod;

    if (p%2){
        temp*=a;
        temp%=mod;
    }

    return temp;
}

int main()
{
    cin >>n >> m;

    F[0] = 1;

    for (int i=1;i<200005;i++){
        F[i] = F[i-1]*i;
        F[i]%=mod;
    }
    //for (int i=0;i<6;i++)cout << F[i] << endl;

    for (int i=2;i<200005 ; i++){
        P[i] = (i-2)*(n-i-1)+1;
        //show(P[i]);
        P[i]%=mod;
        P[i]+=P[i-1];
        P[i]%=mod;
    }

    ll ans = 0;

    for (int i=2;i<=m;i++){
        if (i-1<n-2)continue;
        ll t1 = F[i-1-n+2]*F[n-2];
        t1%=mod;
        ll temp = bigmod(t1,mod-2);

        temp*=F[i-1];
        temp%=mod;

        //show(temp);

        temp*=(n-2);
        temp%=mod;

        temp*=(n-2);
        temp%=mod;

        if (n>3){
            temp*=P[n-1];
//            show(P[n-1]);
            temp%=mod;
        }

//        show(i);
//        show(temp);

        ans+=temp;
        ans%=mod;
    }
    cout << ans << endl;


    return 0;
}
