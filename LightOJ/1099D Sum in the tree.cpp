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

vector < ll > G[100005];
ll A[100005];

bool dfs_val(ll node, ll from)
{
    if(A[node]==-1)A[node]=A[from];
    if (A[node]<A[from])return true;

    bool temp = false;
    for (int i=0;i<G[node].size();i++){
        ll v= G[node][i];
        if (v==from)continue;
        temp = temp|dfs_val(v,node);
    }
    return temp;
}

ll cnt = 0 , nn=0;

void dfs(ll node , ll from)
{
    //cout <<  node << " " << from << "   -  " <<  A[from]-A[node] << endl;
    cnt+=(A[node]-A[from]);

    for (int i=0;i<G[node].size();i++){
        ll v = G[node][i];
        if (v==from)continue;
        dfs(v,node);
    }
}

void dfs_tree(ll node, ll from)
{
    nn++;
    for (int i=0;i<G[node].size();i++){
        ll v = G[node][i];
        if (v==from)continue;
        dfs_tree(v,node);
    }
}

int main()
{
    ll n;
    cin >> n;
    for (int i=2;i<=n;i++){
        ll a;
        cin >> a;
        G[a].pb(i);
        G[i].pb(a);
    }
    for (int i=1;i<=n;i++){
        cin >> A[i];
    }
    A[0]=A[1];
    dfs_tree(1,0);
    //cout << nn << endl;
    if (dfs_val(1,0) || nn!=n)cout << -1 << endl;
    else {
        dfs(1,0);
        //for (int i=0;i<=n;i++)cout << A[i] << " ";
       // cout << endl;
        //cout << A[1]  << " " << cnt << endl;

        cout << cnt+A[1] << endl;
    }

    return 0;
}
