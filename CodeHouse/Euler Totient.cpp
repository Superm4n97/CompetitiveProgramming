#include<bits/stdc++.h>
#define ll long long int
#define maxn 1000006

using namespace std;

ll phi[maxn], mark[maxn];

void sievephi(ll N)
{
      int i,j;

      for(i = 1; i <= N; i++) phi[i] = i;

      phi[1] = 1;
      mark[1] = 1;


      for(i = 2;i <= N;i += 2){
            if(i != 2) mark[i] = 1;
            phi[i] = phi[i] / 2;
      }

      for(i = 3; i <= N; i += 2){

            if(!mark[i]){
                  phi[i] = phi[i] - 1;

                  for(j = 2 * i; j <= N;j += i){
                        mark[j] = 1;
                        phi[j] = phi[j] / i * (i - 1);
                  }
            }
      }
}

int main()
{
      sievephi(maxn-2);

      for (int i=1;i<=10;i++)cout << phi[i] << endl;

      return 0;
}
