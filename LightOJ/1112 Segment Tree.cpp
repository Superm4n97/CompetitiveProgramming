#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;

ll A[maxn],S[4*maxn] , n , q;

void Clean()
{
      memset(A,0,sizeof A);
      memset(S,0,sizeof S);
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

      S[node] = S[node*2] + S[node*2+1];

      return;
}

void Update(ll node, ll b, ll e , ll id, ll val)
{
      if (b>id || e<id)return;

      if (b==e){
            A[b] += val;
            S[node] = A[b];
            return;
      }

      ll mid = (b+e)/2;

      Update(node*2,b,mid,id,val);
      Update(node*2+1,mid+1,e,id,val);

      S[node] = S[node*2]+S[node*2+1];

      return;
}

ll Query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x)return 0;

      if (b>=x && e<=y)return S[node];

      ll mid = (b+e)/2;

      return Query(node*2,b,mid,x,y)+Query(node*2+1,mid+1,e,x,y);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            Clean();

            scanf("%lld %lld",&n,&q);

            for (int i=0;i<n;i++)scanf("%lld",&A[i]);

            Build(1,0,n-1);

            printf("Case %d:\n",_t);

            while(q--){
                  int type;
                  scanf("%d",&type);

                  if (type==1){
                        ll x;
                        scanf("%lld",&x);
                        printf("%lld\n",A[x]);

                        Update(1,0,n-1,x,A[x]*-1);
                  }
                  else if (type==2){
                        ll id,x;
                        scanf("%lld %lld",&id,&x);

                        Update(1,0,n-1,id,x);
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
