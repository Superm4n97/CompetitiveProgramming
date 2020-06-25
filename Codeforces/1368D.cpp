#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[25] , P[25];

int main()
{
      P[0] = 1;
      for (int i=1 ; i<24 ; i++)P[i] = P[i-1]*2;

      ll n , large = 0 , ans = 0;
      cin >> n;

      for (int i=0 ;i<n;i++){
            ll a;
            cin >> a;

            for (int j=0;j<23 ; j++){
                  if (a%2==1){
                       A[j]++;
                  }
                  a/=2;
            }
      }

      while(true){
            ll temp = 0;

            for (int i=0;i<22 ; i++){
                  if (A[i]){
                        A[i]--;
                        temp+=P[i];
                  }
            }
            if (temp==0)break;

            ans+=temp*temp;
      }

      cout << ans << endl;
}
