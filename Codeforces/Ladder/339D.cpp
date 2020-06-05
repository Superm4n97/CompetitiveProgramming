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

ll n,m,index,val;
ll T[600000],A[200000];

ll makeTree(ll b, ll e, ll node)
{
    if (b==e){
        T[node] = A[b];
        return T[node];
    }

    ll temp=n+2;
    while(temp){
        if ((1<<temp) <= node)break;
        temp--;
    }

    ll mid = (b+e)/2;
    ll t1 = makeTree(b,mid,node*2);
    ll t2 = makeTree(mid+1,e,node*2+1);
    if (n%2 == temp%2)return T[node] = t1^t2;
    else return T[node] = t1|t2;
}
ll updateTree(ll b, ll e, ll node)
{
    //cout << "ok " << node << endl;
    if(b==e && b==index){
        A[b] = val;
        return T[node] = A[b];
    }
    if (b > index || e < index)return T[node];

    ll temp = n+2;
    while(temp){
        if (node >= (1<<temp))break;
        temp--;
    }

    ll mid = (b+e)/2;
    ll t1 = updateTree(b,mid,node*2);
    ll t2 = updateTree(mid+1,e,node*2+1);
    if (temp%2 == n%2)return T[node] = t1^t2;
    else return T[node] = t1|t2;
}

int main()
{
    cin >> n >> m;
    for (int i=1;i<=1<<n;i++)cin >> A[i];
    makeTree(1,1<<n,1);
    for (int i=0;i<m;i++){
        cin >> index >> val;
        cout << updateTree(1,1<<n,1) << endl;
    }

    return 0;
}
