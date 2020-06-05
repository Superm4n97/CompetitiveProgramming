#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

struct data{
      ll mx,mn;
};

ll n,d , A[maxn];
data S[maxn*4];

data combine(data l , data r)
{
      data dt;
      dt.mn = min(l.mn,r.mn);
      dt.mx = max(l.mx,r.mx);

      return dt;
}

void build(ll node, ll b, ll e)
{
      if (b==e){
            S[node].mn = S[node].mx = A[b];
            return;
      }

      ll mid = (b+e)/2;

      build(node*2,b,mid);
      build(node*2+1,mid+1,e);

      S[node] = combine(S[node*2],S[node*2+1]);

      return;
}

data query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x){
            data dt;
            dt.mn = 100000000000009;
            dt.mx = -1;

            return dt;
      }

      if (b>=x && e<=y)return S[node];

      ll mid = (b+e)/2;

      return combine(query(node*2,b,mid,x,y),query(node*2+1,mid+1,e,x,y));
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%lld %lld",&n,&d);

            for (int i=1 ; i<=n;i++)scanf("%lld",&A[i]);

            build(1,1,n);

            ll ans = 0;

            for (int i=1 ; i+d-1<=n ; i++){
                  data dt = query(1,1,n,i,i+d-1);
                  ans = max(ans,dt.mx-dt.mn);
            }
            printf("Case %d: %lld\n",_t,ans);
      }



      return 0;
}
