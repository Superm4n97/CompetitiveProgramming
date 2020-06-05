#include<bits/stdc++.h>
#define ll long long int
#define maxn 30004
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll n,A[maxn];

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1; _t<=tc ; _t++){
            scanf("%lld",&n);

            for (int i=1; i <=n; i++)scanf("%lld",&A[i]);

            stack < pair < ll , ll > > st;
            ll ans = 0;

            for (int i=1 ; i<=n ; i++){
                  ll width = 1;

                  while(!st.empty() && st.top().first>A[i]){
                        width += st.top().second;
                        ans = max(ans,(width-1)*st.top().first);
                        st.pop();
                  }

                  st.push({A[i],width});
            }

            ll width = 0;

            while(!st.empty()){
                  width+=st.top().second;
                  ans = max(ans,(width*st.top().first));
                  st.pop();
            }

            printf("Case %d: %lld\n",_t,ans);
      }


      return 0;
}
