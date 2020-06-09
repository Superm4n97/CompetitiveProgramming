#include<bits/stdc++.h>
#define ll long long int
#define inf9    10000000000009
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m,k,q;
ll A[505][505];
ll dp[505][505];
ll S[505][4*505];
ll S2[505][4*505];

void build(ll j, ll node, ll b, ll e)
{
    if (b==e){
        S[j][node] = A[b][j];
        return;
    }

    ll mid = (b+e)/2;

    build(j, node*2, b, mid);
    build(j, node*2+1, mid+1,e);

    S[j][node] = max(S[j][node*2] , S[j][node*2+1]);
}

void build2(ll j, ll node, ll b, ll e)
{
    if (b==e){
        S2[j][node] = dp[j][b];
        return;
    }

    ll mid = (b+e)/2;

    build2(j, node*2, b, mid);
    build2(j, node*2+1, mid+1,e);

    S2[j][node] = max(S2[j][node*2] , S2[j][node*2+1]);
}

ll query(ll j , ll node, ll b, ll e, ll x, ll y)
{
    if (b>y || e<x)return -1;
    if (b>=x && e<=y)return S[j][node];

    ll mid = (b+e)/2;
    return max(query(j,node*2,b,mid,x,y), query(j,node*2+1,mid+1,e,x,y));
}

ll query2(ll j , ll node, ll b, ll e, ll x, ll y)
{
//    show(j);
//    show(node);
//    show(b);
//    show(e);
//    show(x);
//    show(y);
//    cout << endl;

    if (b>y || e<x)return -1;
    if (b>=x && e<=y)return S2[j][node];

    ll mid = (b+e)/2;
    return max(query2(j,node*2,b,mid,x,y), query2(j,node*2+1,mid+1,e,x,y));
}

ll check(ll i , ll j)
{
    if (i<k)return inf9;

    return query(j,1,1,n,i-k+1,i);
}

ll check2(ll i, ll j)
{
    if (j<k)return inf9;

    return query2(i,1,1,m,j-k+1,j);
}

int main()
{
    cin >> n  >> m >> k >> q;
    for (int i=0;i<n+3;i++){
        for (int j=0;j<m+3;j++)A[i][j] = inf9;
    }

    while(q--){
        ll x,y,a;
        cin >> x >> y >> a;
        A[x][y] = a;
    }

    for (int j=1;j<=m;j++)build(j,1,1,n);

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j] = check(i,j);
        }
    }

    for (int i=1;i<=n;i++)build2(i,1,1,m);

    ll ans = inf9;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ll temp = check2(i,j);
            if (temp!=inf9)ans = min(ans,temp);
        }
    }
    //show(ans);
    if (ans==inf9)ans = -1;
    cout << ans << endl;




//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++)cout << A[i][j] << " ";
//        cout << endl;
//    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++)cout << dp[i][j] << " ";
//        cout << endl;
//    }



    return 0;
}
