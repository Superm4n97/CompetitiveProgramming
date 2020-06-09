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

#define maxn            200006

using namespace std;

ll n,k , cnt[maxn] , P[maxn] , A[maxn] , head = -1 , tail = -1;
vll ans;
map < ll , ll > mp,rmp;

void rec(ll a)
{
      ans.pb(a);

      if (P[a]==a)return;
      rec(P[a]);
}

int main()
{
      cin >> n >> k;

      for (int i = 0 ; i<= n ; i++)P[i] = i;

      for (int i=1 ; i<=n;  i++){
            cin >> A[i];
            if (mp[A[i]]==0){
                  mp[A[i]] = i;
                  rmp[i] = A[i];
            }
      }

      for (int i=1 ; i<=n; i++){
            ll a = mp[A[i]];

            if (cnt[a]==0){
                  cnt[a] = 1;

                  if (head == -1){
                        k--;
                        head = a;
                        tail = a;
                  }
                  else {
                        if (k!=0){

                              k--;
                              P[head] = a;
                              head = a;

                        }
                        else {
                              P[head] = a;
                              head = a;

                              ll temp = tail;

                              tail = P[tail];

                              P[temp] = temp;
                              cnt[temp] = 0;
                        }
                  }
            }
      }

      rec(tail);

      cout << ans.size() << endl;
      for (int i = ans.size()-1 ; i>=0 ; i--)cout << rmp[ans[i]] << " ";
      cout << endl;



      return 0;
}
