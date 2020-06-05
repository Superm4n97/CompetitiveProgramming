#include <bits/stdc++.h>
#define pb              push_back
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
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008

using namespace std;

int n,m,id = 1;
int L[100],D[100];
vector < int > G[100];

int bridge(int u , int p)
{
    cout << "     " << u << endl;
    L[u] = id;
    D[u] = id++;

    for (int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v==p)continue;
        if (D[v]==0){
            L[u] = min(bridge(v,u),L[u]);
            if (D[u]<L[v])cout << " " << u << " " << v << endl;
        }
        else {
            L[u] = min(L[u],D[v]);
        }
    }
    return L[u];
}

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    int tut = bridge(1,0);

    return 0;
}

