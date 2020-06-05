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

ll T[1000006] , A[100005];
ll n;

ll makeTree(ll b, ll e, ll node)
{
    if (b<1 || e<1 ||b>n || e>n)return 0;
    if (b==e)return T[node] =A[b];
    ll mid = (b+e)/2;
    return T[node] = max(makeTree(b,mid,node*2),makeTree(mid+1,e,node*2+1));
}

ll update(ll b, ll e, ll node, ll ss, ll tt)
{
    if (b<1 || e<1 ||b>n || e>n)return 0;
    if(ss>e || tt<b)return 0;
    if (ss<=b && e<=tt)return T[node];

    ll mid = (b+e)/2;
    return max(update(b,mid,node*2,ss,tt),update(mid+1,e,node*2+1,ss,tt));
}

int main()
{
    int tc;
    scd(tc);
    for (int ii=1;ii<=tc;ii++){
        ll q;
        scll(n,q);
        for (int i=1;i<=n;i++)scl(A[i]);
        makeTree(1,n,1);
        printf("Case #%d:\n",ii);
        for (int i=0;i<q;i++){
            ll a,b;
            scll(a,b);
            printf("%lld\n",update(1,n,1,a,b));
        }
    }


    return 0;
}

