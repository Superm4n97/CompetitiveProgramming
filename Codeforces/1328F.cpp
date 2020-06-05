#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define inf 10000000000000000

using namespace std;

ll n,k;
vector < ll > v;
map < ll , ll > A,B,mp;
ll cost[maxn] , cost2[maxn] , ans = inf;

int main()
{
      cin >> n >> k;

      for (int i=0;i<n;i++){
            ll a;
            scanf("%I64d",&a);

            A[a]++;
            B[a]++;
            mp[a]++;

            if (A[a]==1)v.push_back(a);
      }

      sort(v.begin(),v.end());

      for (int i=0;i<v.size();i++){
            if (A[v[i]]>=k){
                  cout << 0 << endl;
                  return 0;
            }
      }

      for (int i=1;i<v.size();i++){
            cost[i] = cost[i-1] + A[v[i-1]] * (v[i]-v[i-1]);
            A[v[i]] += A[v[i-1]];

            /*if (k - A[v[i]] <= A[v[i-1]]){
                  ll temp = A[v[i-1]] * (v[i]-1 - v[i-1]);

                  show(temp);


                  temp += cost[i-1];
                  temp += (k - A[v[i]]);
                  ans = min(ans,temp);
                  break;
            }
            else {
                  cost[i] = cost[i-1] + A[v[i-1]] * (v[i]-v[i-1]);
                  A[v[i]] += A[v[i-1]];
            }*/
      }

      for (int i=v.size() - 2 ; i>=0 ; i--){
            cost2[i] = cost2[i+1] + B[v[i+1]] * (v[i+1] - v[i]);
            B[v[i]] += B[v[i+1]];

            /*if(k - B[v[i]] <= B[v[i+1]]){
                  ll temp = B[v[i+1]] * (v[i+1] - v[i]-1);
                  temp += cost2[i+1];
                  temp += (k-B[v[i]]);
                  ans = min(ans,temp);

                  break;
            }
            else {
                  cost2[i] = cost2[i+1] + B[v[i+1]] * (v[i+1] - v[i]);
                  B[v[i]] += B[v[i+1]];
            }*/
      }

      for (int i = 0 ; i<v.size() ; i++){
            ll t1 = 0 , t2 = 0;

            ///calculate t1
                  if (i==0){
                        t1 = inf;
                  }
                  else if (k - mp[v[i]] <= A[v[i-1]]){
                        t1 = cost[i-1];
                        t1 += (A[v[i-1]] * (v[i]-1 - v[i-1]));
                        t1 += (k - mp[v[i]]);
                  }
                  else {
                        t1 = cost[i-1];
                        t1 += (A[v[i-1]] * (v[i] - v[i-1]));

                        ll need = k - mp[v[i]]-A[v[i-1]];

                        t1+=cost2[i+1];

                        t1 += (B[v[i+1]] * (v[i+1] - v[i]-1));
                        t1+=need;
                  }
            ///
            ///calculate t2
                  if (i==v.size()-1){
                        t2 = inf;
                  }
                  else if (k - mp[v[i]] <= B[v[i+1]]){
                        t2=cost2[i+1];
                        t2 += (B[v[i+1]] * (v[i+1] - v[i]-1));
                        t2 += (k-mp[v[i]]);
                  }
                  else {
                        t2=cost2[i+1];
                        t2 += (B[v[i+1]] * (v[i+1] - v[i]));

                        ll need = (k - mp[v[i]] - B[v[i+1]]);

                        t2+=cost[i-1];

                        t2+=A[v[i-1]] * (v[i]-1 - v[i-1]);
                        t2+=need;
                  }

            ans = min(ans,min(t2,t1));
      }

      cout << ans << endl;

      return 0;
}
