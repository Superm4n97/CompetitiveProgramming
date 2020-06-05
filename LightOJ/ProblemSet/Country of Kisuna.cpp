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

using namespace std;

vii graph[100005];
int cost[100005],cost2[100005];
int mx;

int BFS(int s)
{
    cost[s]=0;
    queue < int > q;
    q.push(s);
    mx=0;
    int node;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if (cost[u]>mx){
            mx = cost[u];
            node=u;
        }
        for (int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if (cost[v]>cost[u]+1){
                cost[v]=cost[u]+1;
                q.push(v);
            }
        }
    }
    return node;
}

int main()
{
    int n;
    scd(n);
    //cout << n << endl;
    for (int i=1;i<n;i++){
        int a,b;
        scd(a),scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for (int i=0;i<100005;i++)cost[i]=1000005;
    int a = BFS(1);
    for (int i=0;i<100005;i++)cost[i]=1000005;
    int b = BFS(a);
    printf("%d\n",mx);

    return 0;
}
