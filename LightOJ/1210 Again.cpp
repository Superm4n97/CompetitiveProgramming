#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define pb push_back
#define inf 100000000000000
#define maxn 200005

using namespace std;

vector < ll > G[maxn] , R[maxn], T[maxn];
ll n,m,P[maxn],M[maxn],IN[maxn], OUT[maxn] , mark;
stack < ll > st;
map < pair < ll , ll > , ll > mp;

void dfs(ll u)
{
    //show(u);
    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (!M[v]){
            M[v] = 1;
            dfs(v);
        }
    }
    st.push(u);

    return;
}

void dfs2(ll u)
{
    M[u] = 1;
    P[u] = mark;

    for (int i=0;i<R[u].size();i++){
        ll v = R[u][i];
        if (!M[v])dfs2(v);
    }

    return;
}

int main()
{
    ll tc;
    scanf("%lld",&tc);

    for (int _t=1;_t<=tc;_t++){
        scanf("%lld %lld",&n,&m);
        mark = 0;

        for (int i=0;i<m;i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            G[a].pb(b);
            R[b].pb(a);
        }

        memset(M,0,sizeof(M));
        memset(P,0,sizeof(P));

       // show(_t);///
        for (int i=1;i<=n;i++){
            if (M[i]==0){
                M[i] = 1;
                dfs(i);
            }
        }
        //show(_t);///*
        memset(M,0,sizeof(M));


        while(!st.empty()){
            int u = st.top();
            st.pop();
            if (M[u]==0){
                mark++;
                dfs2(u);
            }
        }

        memset(IN,0,sizeof(IN));
        memset(OUT,0,sizeof(OUT));

        for (int u=1;u<=n;u++){

            for (int i = 0;i<G[u].size();i++){
                ll v = G[u][i];

                ll a = P[u] , b = P[v];

                if (a!=b && mp[{a,b}]==0){
                    mp[{a,b}] = 1;
                    T[a].pb(b);

//                    show(a);
//                    show(b);

                    IN[b]++,OUT[a]++;
                }
            }
        }

        if (mark==1){
            printf("Case %d: 0\n", _t);
            for (int i=0;i<=n+1;i++){
                G[i].clear();
                R[i].clear();
            }
            for (int i=0;i<=n+1;i++)T[i].clear();
            mp.clear();
                continue;
        }

        ll in = 0 , out = 0;

        for (int i=1;i<=mark;i++){
            if (IN[i]==0)in++;
            if (OUT[i]==0)out++;
        }

        printf("Case %d: %lld\n",_t,max(in,out));

        for (int i=0;i<=n+1;i++){
            G[i].clear();
            R[i].clear();
        }
        for (int i=0;i<=n+1;i++)T[i].clear();
        mp.clear();
    }


    return 0;
}

