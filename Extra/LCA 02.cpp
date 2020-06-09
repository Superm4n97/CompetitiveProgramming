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

int n;
vector < int > G[100002];
int S[100002][22];
int P[100002],L[100002];

void dfs(int from, int node, int lvl)
{
    L[node]=lvl;
    for (int i=0;i<G[node].size();i++){
        int v = G[node][i];
        if (v==from)continue;
        P[v] = node;
        dfs(node,v,lvl+1);
    }
}

void makeSparseTable()
{
    P[1]=1;
    dfs(1,1,0);
    S[1][0]=-1;
    for (int i=2;i<=n;i++)S[i][0]=P[i];
    for (int j=1;(1<<j)<=n;j++){
        for (int i=1;i<=n;i++){
            S[i][j] = S[S[i][j-1]][j-1];
        }
    }
}

int query(int a, int b)
{
    if (L[a]<L[b])swap(a,b);

    int log = 0;
    while(1){
        if ((1<<log)>n)break;
        log++;
    }

    for (int i=log;i>=0;i--){
        if (L[a]-(1<<i)>=L[b])a = S[a][i];
    }
    if (a==b)return a;

    for (int i=log;i>=0;i--){
        if (S[a][i]!=-1 && S[a][i]!=S[b][i])
            a=S[a][i],b=S[b][i];
    }
    return P[a];
}

int main()
{
    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    makeSparseTable();
    cout << "\n" << endl;
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << query(a,b) << endl;
    }

    return 0;
}

