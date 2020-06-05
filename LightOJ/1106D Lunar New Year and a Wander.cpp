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

int A[100005],n,m;
vii G[100005],ans;
priority_queue < int > pq;

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    pq.push(-1);
    A[1]=1;

    while(!pq.empty()){
        int v = pq.top() *-1;
        pq.pop();
        ans.pb(v);
        //cout << "ok " << v << endl;

        for (int i=0;i<G[v].size();i++){
            int u = G[v][i];
            if (!A[u]){
                A[u]=1;
                pq.push(u*-1);
            }
        }
    }
    for (int i=0;i<ans.size();i++)cout << ans[i] << " ";
    cout << endl;


    return 0;
}

