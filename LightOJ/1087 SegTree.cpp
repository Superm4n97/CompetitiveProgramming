#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

struct data
{
      ll value;
};

ll A[maxn] , N = maxn-5, n , q;
data S[maxn*4];

void clean()
{
      memset(A,0,sizeof A);
      memset(S,0,sizeof S);
}

data combine(data l , data r)
{
      data dt;
      dt.value = l.value+r.value;

      return dt;
}

void build(ll node, ll b, ll e)
{
      if (b==e)
      {
            if (A[b])S[node].value = 1;

            return;
      }

      ll mid = (b+e)/2;

      build(node*2, b,mid);
      build(node*2+1,mid+1,e);

      S[node] = combine(S[node*2],S[node*2+1]);

      return;
}

void Insert(ll node, ll b, ll e, ll id , ll val)
{
      if (b>id || e<id)return;

      if (b==e){
            A[id] = val;

            if (val)S[node].value = 1;
            else S[node].value = 0;

            return;
      }

      ll mid = (b+e)/2;

      Insert(node*2,b,mid,id,val);
      Insert(node*2+1,mid+1,e,id,val);

      S[node] = combine(S[node*2],S[node*2+1]);

      return;
}

ll query(ll node, ll b, ll e, ll total, ll k)
{
      if (b==e)return b;

      ll mid = (b+e)/2;

      if (S[node*2].value+total < k){
            total+=S[node*2].value;
            return query(node*2+1,mid+1,e,total,k);
      }
      else {
            return query(node*2,b,mid,total,k);
      }
}

int main()
{
      int tc;
      scanf("%lld",&tc);

      for (int _t = 1 ; _t<=tc; _t++){
            clean();

            scanf("%lld %lld",&n,&q);

            for (int i=1 ; i<=n;i++)scanf("%lld",&A[i]);

            build(1,1,N);

            printf("Case %d:\n",_t);

            ll insertingPosition = n+1;

            while(q--){
                  char ch;
                  ll x;
                  cin >> ch;
                  scanf("%lld",&x);

                  if (ch=='a'){
                        Insert(1,1,N,insertingPosition,x);
                        insertingPosition++;
                  }
                  else {
                        if (S[1].value<x)printf("none\n");
                        else {
                              ll id = query(1,1,N,0,x);
                              printf("%lld\n",A[id]);
                              Insert(1,1,N,id,0);
                        }
                  }
            }
      }

      return 0;
}
