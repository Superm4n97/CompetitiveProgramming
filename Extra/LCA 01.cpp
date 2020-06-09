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

int n;
vii G[100];
int L[100] , MX[100] , S[100][10];

void bfs()
{
    queue < int > q;
    q.push(1);
    L[1] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (int i=0;i<G[u].size()){
            int v = q.pop();

            if (L[v]>L[u]+1){
                L[v] = L[u]+1;
                S[v][0] = u;
                MX[v] = max(A[v],MX[u]);
                q.push(v);
            }
        }
    }
}

int main()
{
    scd(n);
    for (int i=0;i<=n;i++)P[i] = i;

    for (int i=1;i<n;i++){
        int a,b;
        scdd(a,b);

        G[a].pb(b);
        G[b].pb(a);
    }
    bfs();
    for (int j=0;j<8;j++){
        for (int i=1;i<=n;i++){
            int tut = 1<<j;
            S[i][j+1] = S[S[i][j]][j];
        }
    }

    int q;
    scd(q);

    for (int t=0;t<q;t++){
        int a,b;
        scdd(a,b);

    }

    return 0;
}
