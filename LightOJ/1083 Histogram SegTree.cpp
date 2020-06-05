#include<bits/stdc++.h>
#define ll long long int
#define maxn 30004
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

struct data
{
      ll suff  ,preff , mxValue;
};

ll A[maxn] , n, q;
data S[maxn*4];

data makeData(ll a)
{
      data dt;
      dt.suff = dt.preff = dt.mxValue = 1;

      return dt;
}

data CombineData(data l, ll Lsize, data r, ll Rsize)
{
      data dt;

      dt.preff = l.preff;
      if (l.preff==Lsize)dt.preff += r.preff;

      dt.suff = r.suff;
      if(r.suff == Rsize)dt.suff += l.suff;

      dt.mxValue = max(l.suff+r.preff,max(l.mxValue,r.mxValue));

      return dt;
}

data ClearData(data dt)
{
      dt.mxValue = dt.preff = dt.suff = 0;

      return dt;
}

void Build(ll node, ll b, ll e)
{
      if (b==e){
            S[node] = makeData(A[b]);
            return;
      }

      ll mid = (b+e)/2;

      Build(node*2,b,mid);
      Build(node*2+1,mid+1,e);

      S[node] = CombineData(S[node*2],mid-b+1,S[node*2+1],e-mid);
}

data Update(ll node, ll b, ll e, ll idx)
{
      if (b>idx || e<idx)return S[node];

      if (b==e)return S[node] = ClearData(S[node]);

      ll mid = (b+e)/2;

      return S[node] = CombineData(Update(node*2,b,mid,idx), mid-b+1 ,Update(node*2+1,mid+1,e,idx),e-mid);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            scanf("%lld",&n);

            for (int i=1;i<=n ; i++)scanf("%lld",&A[i]);

            Build(1,1,n);

            vector < pair < ll , ll > > v;

            for (int i=1 ; i<=n; i++)v.push_back({A[i],i});

            sort(v.begin(),v.end());

            ll currentSize = n , ans = 0;

            for (int i=0;i<n;i++){
                  ans = max(ans,currentSize*v[i].first);
                  currentSize = Update(1,1,n,v[i].second).mxValue;
            }

            printf("Case %d: %lld\n",_t,ans);
      }


      return 0;
}
