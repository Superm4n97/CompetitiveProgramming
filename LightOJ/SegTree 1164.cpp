#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;

struct data
{
      ll sum , lazy;
};

ll n,q;
data S[maxn*4];

data combine(data l, data r)
{
      data dt;
      dt.lazy = l.lazy+r.lazy;
      dt.sum = l.sum+r.sum;

      return dt;
}

void lazyClear(ll node, ll b, ll e)
{
      S[node].sum += (e-b+1)*S[node].lazy;

      if (b!=e){
            S[node*2].lazy += S[node].lazy;
            S[node*2+1].lazy += S[node].lazy;
      }
      S[node].lazy = 0;

      return;
}

void Build(ll node, ll b, ll e)
{
      if (b==e){
            S[node].sum = 0;
            S[node].lazy = 0;

            return;
      }

      ll mid = (b+e)/2;

      Build(node*2, b, mid);
      Build(node*2+1,mid+1,e);

      S[node] = combine(S[node*2],S[node*2+1]);

      return;
}

void Update(ll node, ll b, ll e, ll x, ll y, ll v)
{
      if (S[node].lazy)lazyClear(node,b,e);

      if (b>y || e<x)return;

      if (b>=x && e<=y){
            S[node].lazy += v;
            lazyClear(node,b,e);

            return;
      }

      ll mid = (b+e)/2;

      Update(node*2,b,mid,x,y,v);
      Update(node*2+1,mid+1,e,x,y,v);

      S[node] = combine(S[node*2],S[node*2+1]);

      return;
}

data Query(ll node, ll b, ll e, ll x, ll y)
{
      if (S[node].lazy)lazyClear(node,b, e);

      if (b>y || e<x){
            data dt;
            dt.lazy = dt.sum = 0;

            return dt;
      }

      if (b>=x && e<=y)return S[node];

      ll mid = (b+e)/2;

      return combine(Query(node*2,b,mid,x,y),Query(node*2+1,mid+1,e,x,y));
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            scanf("%lld %lld",&n,&q);

            Build(1,0,n-1);

            printf("Case %d:\n",_t);
            while(q--){
                  int type;
                  scanf("%d",&type);

                  if (type==0){
                        ll x,y,v;
                        scanf("%lld %lld %lld",&x,&y,&v);
                        Update(1,0,n-1,x,y,v);
                  }
                  else {
                        ll x,y;
                        scanf("%lld %lld",&x,&y);

                        printf("%lld\n",Query(1,0,n-1,x,y));
                  }
            }
      }


      return 0;
}
