#include<bits/stdc++.h>
#define ll long long int
#define maxn 50004
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,q;
vector < ll > START , END;

ll StartBS(ll a)
{
      ll b = 0 , e = n-1 , ans = -1;

      while(b<=e){
            ll mid = (b+e)/2;

            if (START[mid]<=a){
                  ans = max(ans,mid);
                  b = mid+1;
            }
            else {
                  e = mid-1;
            }
      }

      return ans;
}

ll EndBS(ll a)
{
      ll b = 0 , e = n-1 , ans = -1;

      while(b<=e){
            ll mid = (b+e)/2;

            if (END[mid]<a){
                  ans = max(ans,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }

      return ans;
}

int main()
{
      ll tc;
      scanf("%lld",&tc);

      for(int _t=1 ;_t<=tc ; _t++){
            scanf("%lld %lld",&n,&q);

            START.clear();
            END.clear();

            for (int i=0;i<n;i++){
                  ll a, b;
                  scanf("%lld %lld",&a,&b);

                  START.push_back(a);
                  END.push_back(b);
            }

            sort(START.begin(),START.end());
            sort(END.begin(),END.end());

            printf("Case %d:\n",_t);
            while(q--){
                  ll a;
                  scanf("%lld",&a);

                  printf("%lld\n",StartBS(a)-EndBS(a));
            }
      }



      return 0;
}
