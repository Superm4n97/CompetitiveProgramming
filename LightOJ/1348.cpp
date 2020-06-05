#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;
#define maxn 30004
#define inf 1000000000012

using namespace std;

vector < ll > G[maxn];
ll n , A[maxn] , L[maxn] , vis[maxn] , P[maxn];
ll S[maxn][30] , Eular[2*maxn];
ll indexx = 0LL;
ll START[2*maxn] , END[2*maxn] , SEG[maxn*8];

void BuildLCA()
{
    queue < ll > q;
    q.push(0);
    L[0] = 0;
    vis[0] = 1;
    P[0] = 0;

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        for (int i=0;i<G[u].size();i++){
            ll v = G[u][i];
            if (!vis[v]){
                L[v] = L[u]+1;
                vis[v] = 1;
                P[v] = u;
                q.push(v);
            }
        }
    }

    for (int i=0;i<n;i++)S[i][0] = P[i];

    for (int j = 1 ; j<28 ; j++){
        for (int i=0;i<n;i++)S[i][j] = S[S[i][j-1]][j-1];
    }
}

ll LCA(ll a, ll b)
{
    if (L[a]>L[b])swap(a,b);

    for (int i=27;i>=0 ; i--){
        if (L[b] - (1<<i) >= L[a])b = S[b][i];
    }
    if (a==b)return a;
    for (int i=27;i>=0;i--){
        if (S[a][i] != S[b][i]){
            a = S[a][i];
            b = S[b][i];
        }
    }

    return S[a][0];
}

void BuildEular(ll u)
{
    indexx++;
    Eular[indexx] = A[u];
    START[u] = indexx;

    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (!vis[v]){
            vis[v] = 1;
            BuildEular(v);
        }
    }

    indexx++;
    Eular[indexx] = A[u]*-1;
    END[u] = indexx;
}

void buildSegTree(ll node, ll b, ll e)
{
    if (b==e){
        SEG[node] = Eular[b];
        return;
    }
    ll mid = (b+e)/2;

    buildSegTree(node*2 , b , mid);
    buildSegTree(node*2+1 , mid+1 , e);

    SEG[node] = SEG[node*2]+SEG[node*2+1];

    return;
}

void updateSegTree(ll node , ll b, ll e , ll ind , ll value)
{
    if (b>ind || e<ind){
        return;
    }
    if (b==e){
        SEG[node] = Eular[b] = value;
        return;
    }

    ll mid = (b+e)/2;

    updateSegTree(node*2 , b , mid , ind,value);
    updateSegTree(node*2+1,mid+1,e,ind,value);

    SEG[node] = SEG[node*2] + SEG[node*2+1];
}

ll querySegTree(ll node, ll b, ll e, ll x, ll y)
{
    if (b>=x && e<=y)return SEG[node];
    if (b>y || e<x)return 0LL;

    ll mid = (b+e)/2;
    return querySegTree(node*2,b,mid,x,y)+querySegTree(node*2+1,mid+1,e,x,y);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll tc;
    scanf("%lld",&tc);

    for (int _t=1;_t<=tc;_t++){

        ///**initialization
        for (int i=0;i<maxn;i++){
            G[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(P,0,sizeof(P));
        memset(L,0,sizeof(L));
        memset(A,0,sizeof(A));
        memset(Eular,0,sizeof(Eular));
        memset(START,0,sizeof(START));
        memset(END,0,sizeof(END));
        memset(SEG,0,sizeof(SEG));
        memset(S,-1,sizeof(S));
        indexx = -1;
        ///*********

        scanf("%lld",&n);
        for (int i=0;i<n;i++)scanf("%lld",&A[i]);
        for (int i=1;i<n;i++){
            ll a, b;
            scanf("%lld %lld",&a,&b);
            G[a].pb(b);
            G[b].pb(a);
        }

        BuildLCA();

        memset(vis,0,sizeof(vis));

        vis[0] = 1;
        BuildEular(0);

        //for (int i=0;i<=index;i++)cout << Eular[i]<< " " ;
        //cout << endl;
        buildSegTree(1,0,indexx);

        printf("Case %d:\n",_t);
        ll query ;
        scanf("%lld",&query);

        while(query--){
            ll type;
            scanf("%lld",&type);

            if (type==0){
                ll x,y;
                scanf("%lld %lld",&x,&y);
                ll lc = LCA(x,y);

                if (lc==x || lc == y){
                    ll a = START[x] , b = START[y];
                    if (a>b)swap(a,b);

                    printf("%lld\n",querySegTree(1,0,indexx,a,b));
                }
                else {
                    ll a = START[x] , b = START[lc];
                    if (a>b)swap(a,b);
                    ll temp = querySegTree(1,0,indexx,a,b);

                    a = START[y] , b = START[lc];
                    if (a>b)swap(a,b);
                    temp+=querySegTree(1,0,indexx,a,b);
                    temp-=Eular[START[lc]];

                    printf("%lld\n",temp);
                }
            }
            else {
                ll ind, value;
                scanf("%lld %lld",&ind,&value);

                updateSegTree(1,0,indexx,START[ind],value);
                updateSegTree(1,0,indexx,END[ind],value*-1);
            }
        }

    }
    return 0;
}
