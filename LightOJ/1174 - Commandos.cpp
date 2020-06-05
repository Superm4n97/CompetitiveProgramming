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

vii graph[105];
int cost1[105],cost2[105];

void BFS1(int s)
{
    queue < int > q;
    q.push(s);
    cost1[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(cost1[v]>cost1[u]+1){
                cost1[v]=cost1[u]+1;
                q.push(v);
            }
        }
    }
}

void BFS2(int s)
{
    queue < int > q;
    q.push(s);
    cost2[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(cost2[v]>cost2[u]+1){
                cost2[v]=cost2[u]+1;
                q.push(v);
            }
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
            int a,b;
            scd(a),scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        for (int i=0;i<n+4;i++){
            cost1[i]=1000000;
            cost2[i]=1000000;
        }
        int s,d;
        scd(s),scd(d);
        BFS1(s);
        BFS2(d);
        int mx = 0;
        for (int i=0;i<n;i++){
            mx = max(mx,cost1[i]+cost2[i]);
        }
        printf("Case %d: %d\n",_t,mx);
        for (int i=0;i<105;i++)graph[i].clear();
    }

    return 0;
}

