#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m , P[maxn] , C[maxn] , A[maxn];

ll findParent(ll a)
{
      if (P[a]==a)return a;

      return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);

      if (a==b)return;

      P[a] = b;
      C[a] = min(C[a],C[b]);
      C[b] = 0;

      return;
}

int main()
{
      cin >> n >> m;
      for (int i=1;i<=n;i++){
            cin >> C[i];
            P[i] = i;
      }

      for (int i=0;i<m;i++){
            ll a, b;

            cin >> a >> b;
            makeParent(a,b);
      }

      ll sum = 0;

      for (int i=1;i<=n;i++)sum+=C[i];

      cout << sum << endl;


      return 0;
}
