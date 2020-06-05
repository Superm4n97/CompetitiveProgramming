#include<bits/stdc++.h>
#define long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

struct data
{
      ll x,id;
};

ll n,q, A[maxn] , insertIndex, N = maxn-5;
data S[4*maxn];

void Clean()
{
      memset(A,0,sizeof A);
      memset(S,0,sizeof S);
}

data makeData(ll a)
{
      data dt;
      dt.id = b;
      dt.x = 1;

      return dt;
}

data CombineData(data l, data r)
{
      data dt;
      dt.x = l.x+r.x;
      dt.id = r.id;

      return dt;
}

void Build(ll node, ll b, ll e)
{
      if (b==e){
            if (A[b])S[node] = makeData(b);
            return;
      }

      ll mid = (b+e)/2;

      Build(node*2,b,mid);
      Build(noode*2+1,mid+1,e);

      S[node] = CombineData(S[node*2],S[node*2+1]);

      return;
}

ll Query(ll node, ll b, ll e, ll idx)
{
      if (S[node].x<)
}

int main()
{
      int tc;
      scanf("%lld",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            Clean();

            scanf("%lld %lld",&n,&q);
            insertIndex = n+1;

            for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);

            Build();

            printf("Case %d:\n",_t);

            while(q--){
                  char ch;
                  ll x;
                  scanf("%c %lld",&ch,&x);

                  if (ch=='c'){
                        Query();
                  }
            }
      }


      return 0;
}
