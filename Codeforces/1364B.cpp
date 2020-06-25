#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            ll A[n+5] , mark[n+5];
            memset(mark,0,sizeof mark);

            ll cnt = 0;

            for (int i=1 ; i<=n;i++)cin >> A[i];
            for (int i=2 ; i<n ; i++){
                  if (A[i-1] < A[i] && A[i]<A[i+1])mark[i] = 1 , cnt++;
                  if (A[i-1]>A[i] && A[i]>A[i+1])mark[i] = 1 , cnt++;
            }
            cout << n-cnt << endl;
            for (int i=1 ;i<=n;i++)
                  if (mark[i]==0)
                        cout << A[i] << " ";
            cout << endl;
      }

      return 0;
}
