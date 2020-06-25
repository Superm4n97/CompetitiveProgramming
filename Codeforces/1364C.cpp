#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;

ll n , A[maxn] , D[maxn] , mp[maxn];

int main()
{
      memset(D,-1,sizeof D);

      cin >> n;
      for (int i=1 ; i<=n;  i++){
            cin >> A[i];
      }
      for (int i=1; i <=n;i++){
            if (A[i] != A[i-1]){
                  D[i] = A[i-1];
                  mp[A[i-1]] = 1;
            }
      }
      mp[A[n]] = 1;

      ll temp;
      for (int i=0 ; i<=n ; i++){
            if (mp[i]==0){
                  temp = i;
                  break;
            }
      }

      for (int i=1; i <=n;i++){
            if (D[i]==-1){
                  D[i] = temp;

                  while(true){
                        temp++;
                        if (mp[temp]==0)break;
                  }
            }
      }

      for (int i=1 ; i<=n ; i++)
            cout << D[i] << " ";
      cout << endl;

      return 0;
}
