#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define pb   push_back
#define maxn 400005

#include<bits/stdc++.h>

using namespace std;

ll color[maxn] , eulerColor[15*maxn] , segTree[15*maxn] , X[maxn*5] , Y[maxn*5];
vector < ll > G[maxn] , eulerArray;
ll n,m , lazy[15*maxn];

void makeEulerTour(ll u , ll p)
{
    eulerArray.pb(u);
    X[u] = eulerArray.size() - 1;
    eulerColor[X[u]] = color[u];

    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (v==p)continue;
        makeEulerTour(v,u);
    }

    eulerArray.pb(u);
    Y[u] = eulerArray.size() - 1;
}

void makeTree(ll node , ll b, ll e)
{
    if (b<0 || e>=n)return;
    if (b==e){
        ll temp = 0;
        ll shift = eulerColor[b];
        if (eulerColor[b] != 0){
            temp = 1;
            for (int i=0;i<shift;i++)temp*=2;
            //temp = (ll)(1 << shift);
        }
        //cout << "   b " << b << "   node " << node << "    temp " << temp << "   shift " << shift << endl;
        segTree[node] = temp;
        return;
    }

    ll mid = (b+e)/2;
    makeTree(node*2 , b , mid);
    makeTree(node*2+1 , mid+1 , e);

    segTree[node] = segTree[node*2] | segTree[node*2+1];
    return;
}

void update(ll node , ll b, ll e , ll st, ll ed , ll val)
{
    if (b<0 || e>=n)return;
    if (lazy[node]){
        segTree[node] = lazy[node];
        lazy[node*2] = lazy[node];
        lazy[node*2+1] = lazy[node];
        lazy[node] = 0;
    }

    if (b>=st && e<=ed){
        ///kaj baki
        if (1){///no if check
            lazy[node*2] = val;
            lazy[node*2+1] = val;
        }
        lazy[node] = 0;
        segTree[node] = val;
        return;
    }
    if (b>ed || e<st)return;

    ll mid = (b+e)/2;
    update(node*2,b,mid,st,ed,val);
    update(node*2+1,mid+1,e,st,ed,val);

    segTree[node] = segTree[node*2] | segTree[node*2+1];
    return;
}

ll query(ll node, ll b, ll e, ll st , ll ed)
{
    if (b<0 || e>=n)return 0;
    if (lazy[node]){
        segTree[node] = lazy[node];
        lazy[node*2] = lazy[node];
        lazy[node*2+1] = lazy[node];

        lazy[node] = 0;
    }

    if (st<=b && ed>=e)return segTree[node];
    if (b>ed || e<st)return 0;

    ll mid = (b+e)/2;

    return query(node*2,b,mid,st,ed) | query(node*2+1,mid+1,e,st,ed);
}

int main()
{
    memset(eulerColor,0,sizeof(eulerColor));
    memset(segTree,0,sizeof(segTree));
    memset(lazy,0,sizeof(lazy));

    scanf("%I64d %I64d",&n,&m);

    for (int i=1;i<=n;i++)scanf("%I64d",&color[i]);

    for (int i=1;i<n;i++){
        ll a,b;
        scanf("%I64d %I64d",&a,&b);
        G[a].pb(b);
        G[b].pb(a);
    }

    makeEulerTour(1 , 0);

    n = eulerArray.size();
    makeTree(1,0,n-1);

//    cout << "color" << endl;
//    for (int i=0;i<n;i++){
//        show(eulerColor[i]);
//    }

    while(m--){
        ll type;
        scanf("%I64d",&type);

        if (type==1){
            ll a,b;
            scanf("%I64d %I64d",&a,&b);
            ll val = 1;
            for (int i=0;i<b;i++)val*=2;
            ll st = X[a] , ed = Y[a];
            update(1,0,n-1,st,ed,val);
        }
        else {
            ll u;
            scanf("%I64d",&u);
            ll st = X[u] , ed = Y[u];
            ll temp = query(1,0,n-1,st,ed);
            ll ans = 0;
            //show(temp);///
            while(temp){
                if (temp%2)ans++;
               // cout << temp%2 ;///
                temp/=2;
            }
            //cout << endl;///

            printf("%I64d\n",ans);
        }
    }

    return 0;
}
