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

#define maxn            100005

using namespace std;

struct data{
      ll value ,
};

ll n,m,C[maxn] , A[maxn];
ll S[4*maxn];

void build(ll node, ll b, ll e)
{
      if (b==e)
}

void clearValue(ll node , ll b, ll e)
{
      if (b!=e){
            S[node*2] = S[node*2+1] = S[node];
      }
}

void update(ll node, ll b, ll e, ll x, ll y,ll color)
{
      if (b>y || e<x)return;
      if (b>=x && e<=y){
            S[node] = color;
            clearValue(node,b,e);

            return;
      }

      if (S[node])clearValue(node,b,e);

      ll mid = (b+e)/2;
      update(node*2,b,mid,x,y,color);
      update(node*2+1,mid+1,e,x,y,color);

      S[node] = 0;

      return;
}

ll query(ll node, ll b, ll e, ll id)
{
      if (b>id || e<id)return -1;
      if (b==e && b==id)return S[node];

      if (S[node])clearValue(node,b,e);
      S[node] = 0;

      ll mid = (b+e)/2;

      return max(query(node*2,b,mid,id),query(node*2+1,mid+1,e,id));
}

int main()
{
      cin >> n >> m;

      for (int i=1;i<=m;i++)cin >> C[i];

      for (int i=1;i<=m;i++){
            update()
      }



      return 0;
}
