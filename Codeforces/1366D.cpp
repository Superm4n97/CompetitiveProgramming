#include<bits/stdc++.h>
#define ll long long int
#define inf 10000000

using namespace std;

int marked[inf+3];

int main()
{
      for (int i=2;i*i<=inf ; i++){
            if (marked[i]==0){
                  for (int j=i*i ; j<=inf ; j +=i){
                        if (marked[j] == 0)marked[j] = i;
                  }
            }
      }
      int n;
      cin >> n;

      ll A[n+5] , B[n+5];

      for (int i=1 ; i<=n;i++){
            ll a;
            cin >> a;

            if (marked[a]==0){
                  A[i] = B[i] =  -1;
            }
            else {
                  ll temp = a;
                  while(temp%marked[a]==0){
                        temp/=marked[a];
                  }
                  if (temp==1){
                        A[i] = B[i] = -1;
                  }
                  else {
                        A[i] = temp;
                        B[i] = a/temp;
                  }
            }
      }
      for (int i=1 ; i<=n;i++){
            cout << A[i] << " ";
      }
      cout << endl;

      for (int i=1 ; i<=n;i++)cout << B[i] << " ";
      cout << endl;


      return 0;
}
