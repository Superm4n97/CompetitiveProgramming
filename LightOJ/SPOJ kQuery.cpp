#include<bits/stdc++.h>
#define ll long long int
#define maxn 30004
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll n, A[maxn], S[4*maxn] , ANS[200005];
priority_queue < pair < ll , ll >  > pq;
vector < pair < pair < ll , ll > , pair < ll , ll > > > v;

void Build(ll node, ll b , ll e)
{
      if (b==e){
            S[node] = 1;
            return;
      }

      ll mid = (b+e)/2;

      Build(node*2 , b, mid);
      Build(node*2+1 , mid+1, e);

      S[node] = S[node*2] + S[node*2+1];

      return;
}

void Update(ll node, ll b ,ll e, ll id)
{
      if (b>id || e<id)return;

      if (b==id && b==e){
            S[node] = 0;
            return;
      }

      ll mid = (b+e)/2;

      Update(node*2,b, mid,id);
      Update(node*2+1,mid+1, e,id);

      S[node] = S[node*2] + S[node*2+1];

      return;
}

ll Query(ll node , ll b, ll e, ll x, ll y)
{
      if (b>y || e<x)return 0;

      if (b>=x && e<=y)return S[node];

      ll mid = (b+e)/2;

      return Query(node*2,b,mid,x,y)+Query(node*2+1,mid+1,e,x,y);
}

int main()
{
     scanf("%lld",&n);
     for (int i=1;i<=n; i++){
            ll a;
            scanf("%lld",&a);

            pq.push({a*-1,i});
     }

     Build(1,1,n);

     ll qry;
     scanf("%lld",&qry);

     for (ll i=1 ; i<= qry ; i++){
            ll x,y,a;
            scanf("%lld %lld %lld",&x,&y,&a);
            v.push_back({{a,i},{x,y}});
     }

     sort(v.begin(),v.end());

     for (int i=0;i<qry ; i++){
            ll a = v[i].first.first ,ansIndex = v[i].first.second;
            ll x = v[i].second.first , y = v[i].second.second;

            if (pq.empty())ANS[ansIndex] = 0;
            else {
                  while(!pq.empty() && (pq.top().first *-1 <= a)){
                        ll updateId = pq.top().second;
                        Update(1,1,n,updateId);
                        pq.pop();
                  }
                  ANS[ansIndex] = Query(1,1,n,x,y);
            }
     }
     for (int i=1;i<=qry ; i++){
            printf("%lld\n",ANS[i]);
     }



      return 0;
}
