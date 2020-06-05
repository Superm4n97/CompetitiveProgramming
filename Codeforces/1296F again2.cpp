#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl
#define maxn 5001

using namespace std;

struct edge
{
    ll vv, id;
};

ll P[maxn][maxn] , n, A[maxn];
vector < ll > G[maxn];
vector < ll > G[maxn];
vector < pair < ll , pair < ll , ll > > > Q;
//map < pair < ll , ll > , ll > mp;

void makeParent(ll u, ll p, ll id)
{
    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i].vv;
        if (v==p)continue;

        P[id][v] = u;
        makeParent(v,u,id);
    }
    return;
}

int main()
{
    memset(A,-1,sizeof(A));

    for (int i=0;i<maxn;i++){
        for (int j=0;j<maxn;j++)P[i][j] = j;
    }

    scanf("%lld",&n);
    for (int i=1;i<n;i++){
        ll a, b;
        scanf("%lld %lld",&a,&b);
        G[a].pb({b,i});
        G[b].pb({a,i});
    }
    for (int i=1;i<=n;i++){
        makeParent(i,0,i);
    }

    ll q;
    scanf("%lld",&q);

    for (int i=0;i<q;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);

        if (a>b)swap(a,b);

        Q.pb({c,{a,b}});
    }
    sort(Q.rbegin(),Q.rend());

    show(G[1]);

    for (int i=0;i<q;i++){
        ll a = Q[i].second.first , b = Q[i].second.second , c = Q[i].first;
        if (i>0 && Q[i]==Q[i-1])continue;

        ll temp = b , cnt = 0;
        while(temp != a){
            ll tut = P[a][temp];///*********

            if (A[G[temp][tut].id] == -1 || A[G[temp][tut].id]==c)A[G[temp][tut].id] = c , cnt++;

            show(tut);

            temp = tut;
        }
        if (cnt==0){
            printf("-1\n");
            return 0;
        }
    }


    for (int i=1;i<n;i++)printf("%lld ",max(A[i],1LL));
    printf("\n");


    return 0;
}

