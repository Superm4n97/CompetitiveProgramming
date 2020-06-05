#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define mkp(a,b) make_pair(a,b)
#define scf2(a,b) scanf("%d%d",&a,&b)
#define scf(a) scanf("%d",&a)
using namespace std;
vector < int > v[500100];

int vis[500100],in[500100],kop[500100];


int cnt,i,j,u,w,tc,a,b,m,n,joss;
vector < int > ans;
queue < int > q;
void bfs(int a)
{
    //cout << a << endl;
    cnt=1;
    q.push(a);
    vis[a]=1;
    ans.pb(a);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        joss=v[u].size();
        for(int i=0;i<joss;i++)
        {
            w=v[u][i];
            if(vis[w]==0)
            {
                vis[w]=1;
                ans.pb(w);
                q.push(w);
                cnt++;
            }
        }
    }
    joss=ans.size();
    for(int i=0;i<joss;i++)kop[ans[i]]=cnt;
    ans.clear();
}
int main()
{
    scanf("%d%d",&tc,&m);
    memset(vis,0,sizeof(vis));
    //memset(kop,0,sizeof(kop));
    while(m--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&in[i]);
        }
        for(int i=1;i<n;i++)
        {
            a=in[i];
            b=in[i-1];
            v[a].pb(b);
            v[b].pb(a);
        }
    }
    //cout << tc << endl;
    for(int i=1;i<=tc;i++)
    {
        if(vis[i]==0)bfs(i);
        printf("%d ",kop[i]);
    }
    printf("\n");
}
