#include <bits/stdc++.h>
#define ll long long int
#define pb          push_back
#define srt(v)      sort(v.begin(),v.end())
#define rsrt        sort(v.rbegin(),v.rend())
#define vii         vector < int >
#define input(v,n)  for (int i=0;i<n;i++){int a;cin >>a;v.pb(a);}
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define scd(a)      scanf("%d",&a)
#define scl(a)      scanf("%lld",&a)
#define mk          make_pair
#define inf         1000000

using namespace std;

vii graph[505],weight[505];
int cost[505];

void BFS(int s)
{
    cost[s]=0;
    priority_queue < pii > q;
    q.push(mk(0,s));
    while(!q.empty()){
        int u = q.top().second;
        //cout << "flag 1 " << u << endl;
        int cc = q.top().first*-1;
        q.pop();
        if (cost[u]<cc)continue;
        cost[u] = cc;
        for (int i=0;i<graph[u].size();i++){
            int v = graph[u][i],cst = weight[u][i];
            if (cost[v]!=inf)continue;
            if (cst<=cc){
                q.push(mk(cc*-1,v));
            }
            else q.push(mk(cst*-1,v));
        }
    }
}

int main()
{
    int tc;
    scd(tc);
    for (int _t=1;_t<=tc;_t++){
        int n,m;
        scd(n),scd(m);
        for (int i=0;i<m;i++){
            int a,b,c;
            scd(a),scd(b),scd(c);
            graph[a].pb(b);
            graph[b].pb(a);
            weight[a].pb(c);
            weight[b].pb(c);
        }
        for (int i=0;i<n;i++)cost[i]=inf;
        int source;
        scd(source);
        BFS(source);
        printf("Case %d:\n",_t);
        for (int i=0;i<n;i++){
            if (cost[i]==inf)printf("Impossible\n");
            else printf("%d\n",cost[i]);
        }
        for (int i=0;i<505;i++){
            graph[i].clear();
            weight[i].clear();
        }
    }

    return 0;
}
