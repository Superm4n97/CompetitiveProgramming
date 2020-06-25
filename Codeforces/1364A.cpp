#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            int n,x;
            cin >> n >> x;
            int sum = 0 , mn = n+1;
            for (int i=1;i<=n;i++){
                  int a;
                  cin >> a;

                  sum+=a;

                  if (a%x != 0){
                        mn = min(mn , min(i,n-i+1));
                  }
            }
            if (sum%x)cout << n << endl;
            else {
                  if (mn==n+1)cout << -1 << endl;
                  else cout << n - mn << endl;
            }
      }

      return 0;
}
