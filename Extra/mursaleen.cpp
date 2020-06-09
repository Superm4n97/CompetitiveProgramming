#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " : " << x << endl
const int M = 1e4+1;
int color[M], d[M], f[M], t = 0;
bool pos = true;
vector < bool > vis;
vector < int > adj[M];
vector < pair < int, int > > v;

bool cmp(pair < int, int > p1, pair < int, int > p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

void dfs(int s)
{
    d[s] = ++t;
    vis[s] = true;
    for(auto it : adj[s])
    {
        if(!vis[it]) dfs(it);
    }
    f[s] = ++t;
    v.push_back({s, f[s]});
}
int main ()
{
    int node, edge, i, a, b;
    cin >> node >> edge;
    for(i = 1; i <= edge; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vis.assign(node + 1, false);
    for(i = 1; i <= node; i++)
    {
        dfs(i);
        if(pos == false)
        {
            cout << "Sandro fails." << endl;
            return 0;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it : v) cout << it.first << ' ' << it.second << endl;
}
