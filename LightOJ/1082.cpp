#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;
#define maxn 100005
#define inf 100000008

using namespace std;

ll n,q,A[maxn],S[maxn*4];

void clean()
{
      n = 0;
      q = 0;
      memset(A,0,sizeof(A));
      memset(S,0,sizeof(S));

      return;
}

void Build(ll node, ll b, ll e)
{
      if (b==e){
            S[node] = A[b];
            return;
      }

      ll mid = (b+e)/2;

      Build(node*2,b,mid);
      Build(node*2+1,mid+1,e);

      S[node] = min(S[node*2],S[node*2+1]);

      return;
}

ll Query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x)return inf;

      if (b>=x && e<=y)return S[node];

      ll mid = (b+e)/2;

      return min(Query(node*2,b,mid,x,y),Query(node*2+1,mid+1,e,x,y));
}

int main()
{
      int tc;
      scanf("%lld",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            scanf("%lld %lld",&n,&q);

            for (int i=1;i<=n;i++)scanf("%lld",&A[i]);

            Build(1,1,n);

            printf("Case %d:\n",_t);

            while(q--){
                  ll a, b;
                  scanf("%lld %lld",&a,&b);

                  printf("%lld\n",Query(1,1,n,a,b));
            }
      }


      return 0;
}
