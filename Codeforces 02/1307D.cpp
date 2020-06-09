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
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            200006

using namespace std;

ll n,m,k;
ll A[maxn] , vis[maxn] , L[maxn] , D[maxn];
vector < ll > G[maxn] , vt;
map < ll , ll > mp;

int main()
{
    ll shortestPath = 0;
    cin >> n >> m >> k;
    for (int i=0;i<k;i++)cin >> A[i] , mp[A[i]]++;

    for (int i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
        if (mp[a] && mp[b])shortestPath = inf;
    }

    for (int i=0;i<n+4;i++)L[i] = inf, D[i] = inf;

    ///BFS
    queue < ll > q;
    q.push(1);
    L[1] = 0;
    vis[1] = 1;

    while(!q.empty()){
        ll u = q.front();
        q.pop();


        for (int i=0;i<G[u].size();i++){
            ll v = G[u][i];
            if (L[v]>L[u]+1){
                L[v] = L[u]+1;
                q.push(v);
            }
        }
    }

    priority_queue < pair < ll , ll > > pq;

    q.push(n);
    D[n] = 0;
    while(!q.empty()){
        ll u = q.front();
        q.pop();


        for (int i=0;i<G[u].size();i++){
            ll v = G[u][i];
            if (D[v]>D[u]+1){
                D[v] = D[u]+1;
                q.push(v);
            }
        }
    }

    for (int i=0;i<k;i++){
        pq.push({D[A[i]],A[i]});
    }

    ll ans = L[n];

    for (int i=0;i<k;i++){
        ll l1 = L[A[i]] ;
        ll l2 = pq.top().first , a = pq.top().second;

        if (a==A[i]){
            pair < ll , ll > pp = pq.top();
            pq.pop();
            l2 = pq.top().first;
            a = pq.top().second;
            pq.push(pp);
        }
//        show(A[i]);
//        show(l1);
//        show(l2);
//        show(a);
        if (L[a]<l1)continue;
        shortestPath = max(shortestPath,l1+l2+1);
    }

    //show(shortestPath);

    ans = min(ans,shortestPath);
    cout << ans << endl;

    return 0;
}
