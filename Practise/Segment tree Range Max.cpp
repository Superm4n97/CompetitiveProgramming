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

ll n , A[100005] , T[300005];

ll makeTree(ll node , ll b, ll e)
{
    if (b==e)return T[node] = A[b];

    ll mid = (b+e)/2;
    return T[node] = max(makeTree(node*2 , b , mid) , makeTree(node*2+1,mid+1 , e));
}

ll query(ll node , ll b, ll e)
{

}

int main()
{
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> A[i];
    }
    ll tut = makeTree(1,1,n);

    ll q;
    cin >> q ;
    while(q--){
        ll c , a,b;
        cin >> c >> a >> b ;

        if (c==1){

        }
    }

    return 0;
}

