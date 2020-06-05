
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
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

vii ans;
vii G[100005];
int n,m;
map < int , int > dd,mp;
priority_queue < int > pq;

void dfs(int node)
{
    ans.pb(node);
    dd[node]++;
    for (int i=0;i<G[node].size();i++){
        int v = G[node][i];
        if (!dd[v]){
            dfs(v);
        }
    }
}
void dfs2(int node)
{
    while(!pq.empty()){
        int u= pq.top()*-1;
        pq.pop();
        ans.pb(u);
        mp[u]++;
        for (int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (!mp[v]){
                pq.push(v*-1);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b;
        cin  >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    for (int i=1;i<=n;i++)srt(G[i]);
    pq.push(1*-1);
    dfs2(1);
    for (int i=0;i<n;i++)cout << ans[i] << " ";
    cout << endl;

    return 0;
}
