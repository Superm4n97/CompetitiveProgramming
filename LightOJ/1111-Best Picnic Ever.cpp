#include <bits/stdc++.h>
#define ll long long int
#define pb          push_back
#define srt(v)      sort(v.begin(),v.end())
#define rsrt        sort(v.rbegin(),v.rend())
#define vii         vector < int >
#define input(v,n)  for (int i=0;i<n;i++){int a;cin >>a;v.pb(a);}
#define pii         pair<int,int>
#define pll         pair<ll,ll>

using namespace std;

int n,k,m;
vector < int > graph[10003];
int kkkkarr[100005],mark[100005],vis[100005];

int DFS(int u)
{
    vis[u]=1;
    mark[u]=1;
    int tut =0;
    if (kkkkarr[u])tut++;
    for (int i=0;i<graph[u].size();i++){
        if (vis[graph[u][i]]==0)
            tut+=DFS(graph[u][i]);
    }
    return tut;
}

int main()
{
    int tc;
    cin >> tc;
    for (int _t=1;_t<=tc;_t++){
        cin >> k >> n >> m;
        for (int i=0;i<100003;i++)kkkkarr[i]=0;
        for (int i=0;i<k;i++){
            int a;
            cin >> a;
            kkkkarr[a]=1;
        }
        for (int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            graph[a].pb(b);
        }
        int mx =0;
        for (int i=0;i<n+5;i++){
            mark[i]=0;
            vis[i]=0;
        }
        for (int i=1;i<=n;i++){
            if (mark[i]==0){
                mx=max(mx,DFS(i));
            }
        }
        cout << mx << endl;
    }


    return 0;
}
