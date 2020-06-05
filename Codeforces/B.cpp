#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2000006

using namespace std;

int child[maxn] , n;

int main()
{
      cin >> n;

      for (int i=1 ; i<n; i++){
            ll a ,b;
            cin >> a >> b;

            child[a]++;
            child[b]++;
      }
      int cnt = 0;

      for (int i=1 ; i<=n;i++){
            if (child[i]==1)cnt++;
      }
      cout << (cnt+1)/2 << endl;

      return 0;
}
