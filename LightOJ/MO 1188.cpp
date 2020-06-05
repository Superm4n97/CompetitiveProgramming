#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;

struct data
{
      ll l,r;
      int id;
};

data Q[maxn];
ll n,block , ans[maxn],F[maxn] , distinct;
ll A[maxn];

void clean()
{
      distinct = 0;
      memset(ans,0,sizeof ans);
      memset(F,0,sizeof F);

      for (int i=0;i<maxn-1 ;i++){
            Q[i].l = 0;
            Q[i].r = 0;
            Q[i].id = 0;
      }
}

bool cmp(data a, data b)
{
      if (a.l/block != b.l/block)return a.l/block < b.l/block;
      return a.r<b.r;
}

void add(ll i)
{
      F[A[i]]++;
      if (F[A[i]]==1)distinct++;
}

void sub(ll i)
{
      if (F[A[i]]==1)distinct--;
      F[A[i]]--;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            clean();

            ll q;
            scanf("%lld %lld",&n,&q);

            for (int i=1;i<=n;i++){
                  scanf("%lld",&A[i]);
            }

            block = sqrt(n);

            for (int i=0;i<q;i++){
                  ll x,y;
                  scanf("%lld %lld",&x,&y);

                  Q[i].l = x;
                  Q[i].r = y;
                  Q[i].id = i;
            }

            sort(Q,Q+q,cmp);

            ll x = 0 , y = -1;

            for (int i=0;i<q;i++){
                  ll L = Q[i].l , R = Q[i].r , iid = Q[i].id;

                  while(L != x){
                        if (x<L){
                             sub(x);
                             x++;
                        }
                        if (x>L){
                              x--;
                              add(x);
                        }
                  }

                  while(R!=y){
                        if(y<R){
                              y++;
                              add(y);
                        }
                        if (y>R){
                              sub(y);
                              y--;
                        }
                  }

                  ans[iid] = distinct;
            }
            printf("Case %d:\n",_t);
            for (int i=0;i<q;i++){
                  printf("%lld\n",ans[i]);
            }
      }


      return 0;
}
