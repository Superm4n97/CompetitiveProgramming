#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll A[maxn] , S[30][maxn], n;

void build(ll depth , ll b , ll e)
{
      if (b==e){
            S[depth][b] = A[b];

            return;
      }

      ll mid = (b+e)/2;

      build(depth+1 , b, mid);
      build(depth+1 , mid+1 , e);



      /// Marge

      ll _x = b , _y = mid+1 , _id = b;

      while(true){
            if (_x >= mid+1 && _y >= e+1)break;
            if (_x >= mid+1){
                  S[depth][_id] = S[depth+1][_y];
                  _id++ , _y++;
            }
            else if (_y >= e+1){
                  S[depth][_id] = S[depth+1][_x];
                  _id++ , _x++;
            }
            else {
                  if (S[depth+1][_x] < S[depth+1][_y]){
                        S[depth][_id] = S[depth+1][_x];
                        _id++ , _x++;
                  }
                  else {
                        S[depth][_id] = S[depth+1][_y];
                        _id++ , _y++;
                  }
            }
      }

      return;
}

int main()
{
      scanf("%I64d",&n);

      for (ll i= 1 ; i<= n ; i++)scanf("%I64d",&A[i]);

      build(1,1,n);


      return 0;
}

