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
            ll n,k;
            cin >> n >> k;
            string s;
            cin >> s;

            //vector < char > G[k+5];
            sort(s.begin() , s.end());
            vector < char > ans;

            for (int i=k-1 ; i<n ; i+=k){
                  if (s[i] != s[i-k+1]){
                        ans.pb(s[i]);
                        break;
                  }
                  else {
                        ans.pb(s[i]);
                  }

                  if (i+k>=n && i!=n-1){
                        set < char > st;
                        for (int j = i+1 ; j<n; j++){
                              st.insert(s[j]);
                              //ans.pb(s[j]);
                        }
                        if (st.size()==1){
                              ans.pb(s[i+1]);
                        }
                        if (st.size()>1){
                              for (int j = i+1 ; j<n ; j++)ans.push_back(s[j]);
                        }
                  }
            }
            for (int i=0 ; i<ans.size() ; i++)cout << ans[i];
            cout << endl;
      }




      return 0;
}
