#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define pb push_back
#define maxn 50004

using namespace std;

vector < ll > G[maxn] , R[maxn] , T[maxn];
stack < ll > st;
ll n , P[maxn] , counter , vis[maxn] , sz[maxn] , inDegree[maxn] , A[maxn];

void dfs1(ll u)
{
    vis[u] = 1;

    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (!vis[v])dfs1(v);
    }
    st.push(u);
}

void dfs2(ll u)
{
    vis[u] = 1;
    P[u] = counter;
    sz[counter]++;

    for (int i=0;i<R[u].size();i++){
        ll v = R[u][i];

        if (!vis[v]){
            dfs2(v);
        }
    }
}

void dfs3(ll u)
{
    vis[u] = 1;
    ll temp = sz[u];
    show(u);

    for (int i=0;i<T[u].size();i++){
        ll v = T[u][i];

        if (vis[v]==0)dfs3(v);

        temp+=A[v];
    }
    A[u] = temp;
}

int main()
{
    int tc;
    scanf("%lld",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){
        scanf("%lld",&n);

        for (int i=0;i<=n;i++){
            G[i].clear();
            R[i].clear();
            T[i].clear();
        }
        counter = 0;
        memset(P,0,sizeof(P));
        memset(sz,0,sizeof(sz));
        memset(inDegree,0,sizeof(inDegree));


        for (int i=0;i<n;i++){
            ll a, b;
            scanf("%lld %lld",&a,&b);

            G[a].pb(b);
            R[b].pb(a);
        }

        memset(vis,0,sizeof(vis));

        for (ll i=1;i<=n;i++){
            if (!vis[i])dfs1(i);
        }

        memset(vis,0,sizeof(vis));

        while(!st.empty()){
            ll u = st.top();
            st.pop();

            if (!vis[u]){
                counter++;
                dfs2(u);
            }
        }

        map < pair < ll , ll > , ll > mp;

        for (ll u=1;u<=n;u++){
            for (ll i = 0 ; i<G[u].size();i++){
                ll v = G[u][i];

                ll a = P[u] , b = P[v];

                if (a!=b && mp[{a,b}]==0){

                    cout << "a : " << a << " b : " << b << " u : " << u << " v : " << v << endl;

                    mp[{a,b}] = 1;
                    T[a].pb(b);
                    inDegree[b]++;
                }
            }
        }

        memset(vis,0,sizeof(vis));
        memset(A,0,sizeof(A));

        ll ans = 0 , index = 1;

        queue < ll > q;

        for (int i=1;i<=counter;i++){
            if (inDegree[i]==0)q.push(i);
            A[i] = sz[i];
        }

        while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (int i=0;i<T[u].size();i++){
                ll v = T[u][i];

                inDegree[v]--;
                if (inDegree[v]==0)q.push(v);

                if (A[v]<A[i])/// matha kaj kore na
            }
        }

        printf("Case %d: %lld\n",_t,ans);

    }

    return 0;
}
