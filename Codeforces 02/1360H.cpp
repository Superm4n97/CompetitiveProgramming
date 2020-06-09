#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;
vector < ll > v;
ll P[65];

/*
3 3
010
001
111

a = 1 2 7
0 3 4 5 6

1
4 3
000
111
100
011

a = 0 3 4 7
1 2 5 6
*/

ll convert(string s)
{
      ll res = 0;

      for (int i=s.size()-1 , j = 0 ; i>=0 ; i-- , j++){
            if (s[i]=='1')res+=P[j];
      }
      return res;
}

ll BS(ll val)
{
      ll b = 0 , e = v.size()-1 , ret = 0;

      while(b<=e){
            ll mid = (b+e)/2;

            if (v[mid] <= val){
                  b = mid+1;
                  ret = max(ret,mid+1);
            }
            else e = mid-1;
      }
      return ret;
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<62 ; i++)P[i] = P[i-1]*2;

      int tc;
      scanf("%d",&tc);

      while(tc--){
            v.clear();
            map < ll , ll > mp;
            ll n,m;
            cin >> n >> m;

            for (int i=0 ; i<n;i++){
                  string s;
                  cin >> s;

                  ll temp = convert(s);
                  mp[temp] = 1;
                  v.push_back(temp);
            }

            sort(v.begin(),v.end());

            ll k = P[m] - n;
            ll median = (k-1)/2+1;

            ll b = 0 , e = P[m] - 1 , ans;

            while(b<=e){
                  ll mid = (b+e)/2;

                  ll res = mid+1 - BS(mid);

                  if (res<median)b = mid+1;
                  else if (res>median)e = mid-1;
                  else {
                        if (mp[mid])e = mid-1;
                        else {
                              ans = mid;
                              break;
                        }
                  }
            }
            while(m--){
                  ll res = P[m];
                  if (ans>=res){
                        cout << 1;
                        ans-=res;
                  }
                  else cout << 0;
            }
            cout << endl;
      }
}
