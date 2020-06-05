#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;

struct data
{
      ll lazy, one , two, zero;
};

ll n, q;
data S[maxn*4];

void lazyClear(ll node, ll b, ll e)
{

      ll lz = (S[node].lazy)%3;
      if (lz==1){
            ll temp = S[node].one;
            S[node].one = S[node].zero;
            S[node].zero = S[node].two;
            S[node].two = temp;
      }
      else if (lz == 2){
            ll temp = S[node].one;
            S[node].one = S[node].two;
            S[node].two = S[node].zero;
            S[node].zero = temp;
      }
      if (b!=e){
            S[node*2].lazy += S[node].lazy;
            S[node*2+1].lazy += S[node].lazy;
      }

      S[node].lazy = 0;

      return;
}

data combine(data l, data r)
{
      data dt;
      dt.lazy = 0;
      dt.one = l.one + r.one;
      dt.two = l.two + r.two;
      dt.zero = l.zero + r.zero;

      return dt;
}

void Update(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x)return;

      lazyClear(node,b,e);

      if (b>=x && e<=y){
            S[node].lazy++;
            return;
      }

      ll mid = (b+e)/2;

      Update(node*2,b,mid,x,y);
      Update(node*2+1,mid+1,e,x,y);

      S[node] = combine(S[node*2],S[node*2+1]);

      return;
}

data Query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x){
            data dt;
            dt.lazy = dt.one = dt.two = dt.zero = 0;

            return dt;
      }

      lazyClear(node,b,e);

      if (b>=x && e<=y)return S[node];

      ll mid = (b+e)/2;

      return combine(Query(node*2,b,mid,x,y),Query(node*2+1,mid+1,e,x,y));
}

void Build(ll node, ll b, ll e)
{
      if (b==e){
            S[node].lazy = S[node].one = S[node].two = 0;
            S[node].zero = 1;

            return;
      }

      ll mid = (b+e)/2;

      Build(node*2,b,mid);
      Build(node*2+1,mid+1,e);

      S[node] = combine(S[node*2],S[node*2+1]);

      return;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t= 1 ; _t<=tc ; _t++){
            scanf("%lld %lld",&n,&q);

            Build(1,0,n-1);

            printf("Case %d:\n",_t);

            while(q--){
                  ll type , x,y;
                  scanf("%lld %lld %lld",&type,&x,&y);

                  if (type == 0)Update(1,0,n-1,x,y);
                  else printf("%lld\n",Query(1,0,n-1,x,y).zero);
            }
      }


      return 0;
}
