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
#define inf8            100000008

using namespace std;

vii G[100];
int mark[100];
int n , ed;

void DFS(int u)
{

    mark[u] = 1;
    for (int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (!mark[v])DFS(v);
    }
    cout << u << " ";
}

int main()
{
    cout << "Input number of node and edge ";
    cin >> n >> ed;

    cout << "Insert the edges " << endl;

    for (int i=0;i<ed;i++){
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    int source ;
    cout << "Input source :";
    cin >> source;
    DFS(source);
    cout << endl;

    return 0;
}
