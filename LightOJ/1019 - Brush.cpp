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
#define inf         10000000

using namespace std;

vii graph[1000],weight[1000];
int cost[1000];

int BFS(int N)
{
    cost[1]=0;
    priority_queue < pii > q;
    q.push(mk(0,1));
    while(!q.empty()){
        int cc = q.top().first*-1, u = q.top().second;
        q.pop();
        if (u==N)return cc;
        for (int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if (cost[v]>cost[u]+weight[u][i]){
                cost[v] = cost[u]+weight[u][i];
                q.push(mk(cost[v]*-1,v));
            }
        }
    }
    return -1;
}

int main()
{
    int tc;
    scd(tc);
    for (int _t=1;_t<=tc;_t++){
        int n,m;
        scd(n),scd(m);
        for (int i=0;i<m;i++){
            int a,b,w;
            scd(a),scd(b),scd(w);
            graph[a].pb(b);
            graph[b].pb(a);
            weight[a].pb(w);
            weight[b].pb(w);
        }
        for (int i=0;i<105;i++)cost[i]=inf;
        int tut = BFS(n);
        //cout << "flag 1" << endl;
        if (tut==-1)printf("Case %d: Impossible\n",_t);
        else printf("Case %d: %d\n",_t,tut);
        for (int i=0;i<106;i++){
            graph[i].clear();
            weight[i].clear();
        }
    }

    return 0;
}
