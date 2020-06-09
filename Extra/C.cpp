#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2000006

using namespace std;



int main()
{
      ll A[6] , sum = 0;

      for (int i=1 ; i<=4;i++){
            cin >> A[i];
            sum+=A[i];
      }
      bool solution =false;
      for (int i=1 ; i<=4 ; i++){
            for (int j = i+1 ; j<=4 ; j++){
                  if ((A[i]+A[j])*2 == sum)solution = true;
            }
      }
      cout << (solution?"YES":"NO") << endl;



      return 0;
}
