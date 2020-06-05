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
vector < int > tree[100002];
int sparseTable[100002][22];
int level[100002];
int parent[100002];

void buildlevel(int from, int node, int lvl)
{
    level[node] = lvl;
    for (int i=0;i<tree[node].size();i++){
        int v = tree[node][i];
        if (v==from)continue;
        parent[v] = node;
        buildlevel(node,v,lvl+1);
    }
}

void buildSparseTable()
{
    sparseTable[1][0]=-1;
    for (int i=1;i<=n;i++)sparseTable[i][0] = parent[i];

    for (int j=1;(1<<j)<=n;j++){
        for (int i=1;i<=n;i++){
            sparseTable[i][j] = sparseTable[sparseTable[i][j-1]][j-1];
        }
    }
}

int lcaQuery(int a, int b)
{
    if (level[a]<level[b])swap(a,b);
    int log = 0;
    while(1){
        if ((1<<log)>n)break;
        log++;
    }
    //cout << "log " << log << endl;
    for (int i=log;i>=0;i--){
        if (level[a]-(1<<i)>=level[b]){
            a = sparseTable[a][i];
        }
    }
    //cout << "ok 1" << endl;
    if (a==b)return a;
    //cout << "a = " <<a << "    b = " <<b <<  "    level[a] " << level[a] << "      level[b] " << level[b] << endl;

    for (int i=log;i>=0;i--){
        if (sparseTable[a][i]!=sparseTable[b][i] && sparseTable[a][i]!=-1){
            a = sparseTable[a][i] , b= sparseTable[b][i];
        }
    }
    return parent[a];
}

int main()
{
    cout << "Enter nodes of the tree : ";
    cin >> n;
    cout << "Enter n-1 edges :"<< endl;
    for (int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    parent[1]=1;
    buildlevel(1,1,0);
    buildSparseTable();

    cout << "Enter number of query : ";
    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        cout << lcaQuery(a,b) << endl;
    }

    return 0;
}
