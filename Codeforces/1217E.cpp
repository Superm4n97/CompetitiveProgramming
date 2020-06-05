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

ll segTree[6*100000+4][11] , X[6*100000+4][11] , Y[6*100000+4][11];
ll n, m , A[200005];

void buildTree(ll node, ll beg, ll ed)
{
    if (beg == ed){
        ll val = A[beg];
        for (int i=1;;i++){
            if (!val)break;
            ll temp = val%10;
            val/=10;
            if (temp){
                segTree[node][i] = A[beg];
            }
        }
        return;
    }

    ll mid = (beg+ed) / 2;
    buildTree(node*2, beg, mid);
    buildTree(node*2+1, mid+1, ed);

    for (int i=1;i<10;i++){
        vll v;
        v.pb(segTree[node*2][i])
    }

}

int main()
{
    scll(n,m);
    for (int i=1;i<=n;i++)scl(A[i]);

    buildTree(1,1,n);


    return 0;
}
