#include <bits/stdc++.h>
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
#define printCaseAnsInt(t,ans)  printf("Case %d: %d\n",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld\n",t,ans)
#define mod             1000000007
#define maxn            2000005
                        //1000000
using namespace std;

ll F[maxn];

ll bigMod(ll a, ll r)
{
    if(r==1)return a;
    ll temp = bigMod(a,r/2);
    temp*=temp;
    temp%=mod;
    if(r%2)temp*=a;
    temp%=mod;

    return temp;
}

ll inverseMod(ll a)
{
    ll temp = bigMod(a,mod-2);
    return temp;
}

ll calculation(ll n, ll k)
{
    ll ans = F[n+k-1]*inverseMod(F[n]);
    //cout << F[n+k-1] << " " << inverseMod(F[n]) << endl;
    ans%=mod;
    ans*=inverseMod(F[k-1]);
    ans%=mod;
    return ans;
}

int main()
{
    ll tc;
    scl(tc);
    F[0] = 1;
    for (int i=1;i<2000003;i++){
        F[i]=F[i-1]*i;
        F[i]%=mod;
    }

    for (ll t=1;t<=tc;t++){
        ll n,k;
        scll(n,k);
        ll temp = calculation(n,k);
        temp%=mod;
        printCaseAnsLL(t,temp);
        //cout << calculation(n,k) << endl;
    }

    return 0;
}

