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
#define mk              make_pair

using namespace std;

int color[1000000],ans[1000000];
vii graph[1000000];
bool mark[1000000];
map < int , int > mp;

int bfs(int u)
{
    //cout << "ok " << u << endl;
    mark[u]=true;
    int sum=0;

    for (int i=0;i<graph[u].size();i++){
        if (!mark[graph[u][i]])
            sum+=bfs(graph[u][i]);
    }
    if (mp[color[u]])sum+=0;
    else mp[color[u]]=1,sum += color[u];
    ans[u] = sum;
    if (sum==0)ans[u]=color[u];
    return sum;
}

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)cin >> color[i],mark[i]=false;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int a = bfs(1);
    for (int i=1;i<=n;i++)cout << ans[i] << " ";
    cout << endl;

    return 0;
}
