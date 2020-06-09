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

vii G[100005];
int C[100005] , A[100005];
map < int , int > mp;
map < pair < int , int > , int > mmpp;

void dfs(int u)
{
    //cout << "ok " << u << endl;
    A[u] = 1;
    for (int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (C[v] != C[u] && mmpp[mk(C[u],C[v])]==0)mp[C[u]]++ , mmpp[mk(C[u],C[v])] = 1;
        if (A[v]==0)dfs(v);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)scd(C[i]),A[i]=0;
    for (int i=0;i<m;i++){
        int a,b;
        scdd(a,b);
        G[a].pb(b);
        G[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        if (A[i] == 0)dfs(i);
    }
    int mx = 0 , index=1;
    for (int i=1;i<=n;i++){
        //cout << "   "<< mp[C[i]] ;
        if (mx<=mp[C[i]]){
            if (mx<mp[C[i]]){
                mx = mp[C[i]];
                index = i;
            }
            else if (C[index] > C[i])index = i;
        }
    }
    cout << C[index] << endl;

    return 0;
}
