#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;

            ll A[n+5];
            memset(A,0,sizeof A);

            ///                     D         x  y
            priority_queue <pair < ll , pair<ll,ll> > > pq;

            pq.push({n,{-1,-n}});
            ll id = 1;

            while(!pq.empty()){
                  ll d = pq.top().first , x = pq.top().second.first*-1 , y = pq.top().second.second * -1;
                  pq.pop();

                  if (d==1){
                        A[x] = id;
                        id++;
                  }
                  else {
                        ll mid = (x+y)/2;
                        A[mid] = id;
                        id++;

                        if (mid == x)pq.push({d-1 , {(x+1)*-1, y*-1}});
                        else {
                              pq.push({mid-x ,{x*-1,(mid-1)*-1}});
                              pq.push({y-mid,{(mid+1)*-1,y*-1}});
                        }
                  }
            }
            for (int i=1 ; i<=n;i++)cout << A[i] << " ";
            cout << endl;
      }




      return 0;
}
