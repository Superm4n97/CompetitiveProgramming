#include<bits/stdc++.h>
#define ll unsigned long long
#define maxn 5000006

using namespace std;

ll phi[maxn];
bool mark[maxn];

void sievephi(ll N)
{
      ll i,j;

      for(i = 1; i <= N; i++) phi[i] = i;

      phi[1] = 1;
      mark[1] = true;


      for(i = 2;i <= N;i += 2){
            if(i != 2) mark[i] = true;
            phi[i] = phi[i] / 2;
      }

      for(i = 3; i <= N; i += 2){

            if(!mark[i]){
                  phi[i] = phi[i] - 1;

                  for(j = 2 * i; j <= N;j += i){
                        mark[j] = true;
                        phi[j] = phi[j] / i * (i - 1);
                  }
            }
      }
}

int main()
{
      memset(mark,false,sizeof mark);

      sievephi(maxn-2);

      for (int i=1;i<maxn-1;i++){
            phi[i]*=phi[i];
            phi[i]+=phi[i-1];
      }
      //cout << phi[5000000] << endl;

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll a,b;
            scanf("%llu %llu",&a,&b);

            printf("Case %d: %llu\n",_t,phi[b]-phi[a-1]);
      }

      return 0;
}
