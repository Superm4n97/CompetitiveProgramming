#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll A[maxn] , n, k;
stack < pair < ll , ll > > st;
vector < ll > ans;

int main()
{
      cin >> n >> k;

      for (int i=1 ;i<=k ; i++)cin >> A[i];

      st.push({1,n});

      for (int i=1 ; i<=k ; i++){
            ll l = st.top().first , r = st.top().second;
            st.pop();

            if (A[i]<l || A[i]>r){
                  cout << -1 << endl;
                  return 0;
            }

            if (l==A[i] && l==r)continue;
            else if (l==A[i])st.push({l+1,r});
            else if (r==A[i])st.push({l,r-1});
            else  st.push({A[i]+1 , r}) , st.push({l,A[i]-1});
      }

      for (int i=1 ; i<= k ;i++)cout << A[i] << " ";
      while(!st.empty()){
            for (int i = st.top().second ; i>=st.top().first ; i--)cout << i << " ";
            st.pop();
      }
      cout << endl;

      return 0;
}
/*
2 3 4 5 2
*/
