#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll x[maxn],  y[maxn] , c[maxn] , cnt[maxn];

int main()
{
      ll n;
      cin >> n;

      memset(c,-1,sizeof c);

      for (int i=1;i<n;i++){
            cin >> x[i] >> y[i];
            cnt[x[i]]++;
            cnt[y[i]]++;
      }

      ll counter = 0;

      for (int i=1;i<n;i++){
            if (cnt[x[i]]==1 || cnt[y[i]]==1){
                  c[i] = counter;
                  counter++;
            }
      }
      for (int i=1;i<n;i++){
            if (c[i]==-1){
                  c[i] = counter;
                  counter++;
            }
      }
      for (int i=1;i<n;i++)cout << c[i] << endl;

      return 0;
}
