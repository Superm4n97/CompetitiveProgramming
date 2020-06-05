#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define mk              make_pair

using namespace std;

ll n,m,k,cost[100005];
vector < ll > graph[100005],weight[100005];
map < pll , ll > mp;
vector < ll > ans;

void dijkstra()
{
    priority_queue < pair < ll , pair < ll , ll > > > pq;
    pq.push(mk(0,mk(1,-1)));
    cost[1]=0;
    while(!pq.empty()){
        ll u = pq.top().second.first , _u = pq.top().second.second , c = pq.top().first;
        pq.pop();
        if (_u!=-1)ans.pb(mp[mk(max(u,_u),min(u,_u))]);;

        for (int i=0;i<graph[u].size();i++){
            ll v = graph[u][i];
            if (cost[v]>cost[u]+weight[u][i]){
                cost[v]=cost[u]+weight[u][i];
                pq.push(mk(cost[v]*-1,mk(v,u)));
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i=0;i<n+5;i++)cost[i]=10000000000000000;
    for (int i=0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        graph[a].pb(b);
        graph[b].pb(a);
        weight[a].pb(c);
        weight[b].pb(c);
        mp[mk(max(a,b),min(a,b))]=i+1;
    }
    dijkstra();
    ll temp = ans.size();
    cout << min(k,temp) << endl;
    for (int i=0;i<min(k,temp);i++)cout << ans[i] << " ";
    cout << endl;

    return 0;
}
