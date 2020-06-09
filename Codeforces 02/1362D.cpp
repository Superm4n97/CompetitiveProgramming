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

ll n,m , cnt[maxn];
vector < ll > G[maxn] , ans;
bool solution = true;

int main()
{
      cin >> n >> m;
      for (int i=0 ; i<m;i++){
            ll a,b;
            scll(a,b);
            G[a].pb(b);
            G[b].pb(a);
      }
      vector < pair < ll , ll > > vp;
      for (int i=1 ; i<=n;i++){
            ll a;
            scl(a);

            vp.pb({a,i});
      }
      srt(vp);

      for (int i=0;i<vp.size() ; i++){
            ll a = vp[i].first , u = vp[i].second;
            set < ll > st;
            ll mx = 0;
            for (int j = 0 ; j<G[u].size();j++){
                  ll v = G[u][j];

                  if (cnt[v]!=0){
                        mx = max(cnt[v],mx);
                        st.insert(cnt[v]);
                  }
            }

            if (a==1){
                  if (st.empty()){
                        cnt[u] = 1;
                        ans.pb(u);
                  }
                  else solution = false;
            }
            else {
                  if (st.size()==a-1 && mx == a-1){
                        cnt[u] = a;
                        ans.pb(u);
                  }
                  else solution = false;
            }
      }
      if (!solution)cout << -1 << endl;
      else {
            for (int i=0 ; i<n;i++){
                  cout << ans[i] << " ";
            }
            cout << endl;
      }



      return 0;
}
