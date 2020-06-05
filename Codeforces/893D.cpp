#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000005

using namespace std;

ll n,d , A[maxn] , hi = 0 , lo = 0 , cnt = 0;
bool solution = true;

int main()
{
      cin >> n >> d;

      for (int i=1 ;  i<=n; i++)cin >> A[i];

      for (int i=1 ; i<=n ; i++){
            if (A[i]==0){
                  if (lo<0 && hi<0){
                        hi = d;
                        lo = 0;
                        cnt++;
                  }
                  if (hi>=0)lo = max(lo,0LL);
            }
            else {
                  lo += A[i];
                  hi += A[i];
            }

            if (lo<=d && hi>d)hi = d;

            if (lo>d && hi>d)solution = false;

//            show(lo);
//            show(hi);
//            cout << endl;
      }

      if (!solution)cout << -1 << endl;
      else cout << cnt << endl;


      return 0;
}
