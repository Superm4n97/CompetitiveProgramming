#include <bits/stdc++.h>
#define ll              long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn            1000006

using namespace std;

int n,q , S[maxn*4] , cnt[maxn];

void build(int node, int b, int e)
{
      if(b==e){
            S[node] = cnt[b];
            return;
      }

      int mid = (b+e)/2;
      build(node*2,b,mid);
      build(node*2+1,mid+1,e);

      S[node] = S[node*2]+S[node*2+1];
      return;
}

void update(int node, int b, int e, int id)
{
      if (b>id || e<id)return;
      if (b==e){
            S[node]++;
            cnt[b]++;
            return;
      }

      int mid = (b+e)/2;
      update(node*2,b,mid,id);
      update(node*2+1,mid+1,e,id);

      S[node] = S[node*2]+S[node*2+1];
      return;
}

void query(int node, int b, int e, int val)
{
      if (b==e){
            S[node]--;
            cnt[b]--;
            return;
      }

      int mid = (b+e)/2;

      if (S[node*2] < val) query(node*2+1,mid+1,e,val-S[node*2]);
      else query(node*2,b,mid,val);

      S[node] = S[node*2]+S[node*2+1];
}

int main()
{
      scanf("%d %d",&n,&q);

      for (int i=0 ; i<n ; i++){
            int a;
            scanf("%d",&a);
            cnt[a]++;
      }
      build(1,1,maxn-2);

      while(q--){
            int a;
            scanf("%I64d",&a);

            if (a>0) update(1,1,maxn-2,a);
            else query(1,1,maxn-2,a*-1);
      }

      for (int i=1;i<=n ; i++){
            if (cnt[i]){
                  printf("%d\n",i);
                  return 0;
            }
      }
      cout << 0 << endl;


      return 0;
}
