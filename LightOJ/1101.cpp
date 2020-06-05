#include <bits/stdc++.h>
#define ll long long int
#define pb              push_back
#define show(x) cout << #x << " : " << x << endl
#define inf             10000000000000016
#define maxn            50004

using namespace std;

vector < ll > G[maxn] , W[maxn];
vector < pair < ll , pair < ll , ll > > > E;
ll n,m , P[maxn] , L[maxn] , S[maxn][30] , C[maxn][30];

ll findParent(ll a)
{
    if (P[a]==a)return a;
    return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
    a = findParent(a);
    b = findParent(b);
    if (a!=b)P[a] = b;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){

        ///initialize******************
        for (int i=0;i<maxn;i++){
            G[i].clear();
            P[i] = i;
            L[i] = inf;
        }
        E.clear();
        memset(S,-1,sizeof(S));
        memset(C,-1,sizeof(C));
        map < pair < ll , ll > , ll > costMap;
        ///******************


        scanf("%lld %lld",&n,&m);
        for (int i=0;i<m;i++){
            ll a,b,c;
            scanf("%lld %lld %lld",&a,&b,&c);
            if (costMap[{a,b}]==0){
                costMap[{a,b}] = c;
                costMap[{b,a}] = c;
            }
            else {
                costMap[{a,b}] = min(costMap[{a,b}],c);
                costMap[{b,a}] = min(costMap[{b,a}],c);
            }
            E.pb({c,{a,b}});
        }
        sort(E.begin(),E.end());

        for (int i=0;i<m;i++){

            ll a = E[i].second.first , b = E[i].second.second, c = E[i].first;

            if (findParent(a) != findParent(b)){

                G[a].pb(b);
                G[b].pb(a);

                W[a].pb(c);
                W[b].pb(c);

                makeParent(a,b);
            }
        }

        for (int i=0;i<maxn;i++)P[i] = i;

        queue < ll > q;
        q.push(1);
        L[1] = 0;
        P[1] = 1;

        while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (int i=0;i<G[u].size();i++){
                ll v = G[u][i];

                if (L[u]+1<L[v]){
                    L[v] = L[u]+1;
                    q.push(v);
                    P[v] = u;
                }
            }
        }

        for (int i=1;i<=n;i++){
            S[i][0] = P[i];
            C[i][0] = costMap[{i,P[i]}];

        }
        for (int j=1 ; j<27;j++){
            for (int i=1;i<=n;i++){
                S[i][j] = S[S[i][j-1]][j-1];
                C[i][j] = max(C[i][j-1] , C[S[i][j-1]][j-1]);
                //if (j==1)cout << "i: " << i << "   C[i][j]: " << C[i][j] << endl;
            }
        }

        printf("Case %d:\n",_t);

        ll query;
        scanf("%lld",&query);
        while(query--){
            ll a, b;
            scanf("%lld %lld",&a, &b);

            if (L[a]>L[b])swap(a,b);

            ll mx1 = 0 , mx2 = 0;

            for (int i=25;i>=0;i--){
                if (L[b]-(1<<i)>=L[a]){
                    mx1 = max(mx1,C[b][i]);
                    b = S[b][i];
                }
            }

            if (a==b){
                printf("%lld\n",mx1);
                //show(a);
                continue;
            }

            for (int i =25 ; i>=0 ;i--){
                if (S[a][i] != S[b][i]){
                    mx1 = max(mx1, C[a][i]);
                    mx1 = max(mx1, C[b][i]);
                    a = S[a][i];
                    b = S[b][i];
                }
            }
            mx1 = max(mx1,max(C[a][0],C[b][0]));
            printf("%lld\n" , mx1);
        }

    }


    return 0;
}
