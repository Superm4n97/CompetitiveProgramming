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

vector < int > graph[100006];
map < pii , int > mp;
map < pii , int > mpp;
vector < pii > vp;
int n,m,k;
int cost[1000006];

void bfs()
{
    queue < int > q;
    q.push(1);
    cost[1]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if (cost[v]>cost[u]+1){
                cost[v]=cost[u]+1;
                q.push(v);
                vp.pb(mk(max(u,v),min(u,v)));
            }
            else{
                mp[mk(u,v)]=0;
                mp[mk(v,u)]=0;
            }
        }
    }
}

int listx[1000005],listy[1000005];

int main()
{
    scdd(n,m);
    scd(k);
    for (int i=0;i<n+5;i++)cost[i]=100000000;
    for (int i=0;i<m;i++){
        int a,b;
        ll c;
        scdd(a,b);
        scl(c);
        listx[i]=a,listy[i]=b;
        mp[mk(a,b)]=1;
        mp[mk(b,a)]=1;

        mpp[mk(a,b)]=i+1;
        mpp[mk(b,a)]=i+1;

        graph[a].pb(b);
        graph[b].pb(a);
    }
    bfs();
    vector < int > vv;
    int temp = vp.size();
    for (int i=0;i<min(temp,k);i++){
        int tut = mpp[vp[i]];
        vv.pb(tut);
    }
    //srt(vv);
    printf("%d\n",vv.size());
    for (int i=0;i<vv.size();i++)printf("%d ",vv[i]);
    printf("\n");

    return 0;
}
