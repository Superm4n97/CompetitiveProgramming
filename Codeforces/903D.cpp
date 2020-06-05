#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll A[maxn] , S[30][maxn] , C[30][maxn];
ll n;
vector < ll > ans;
bool parity = true;

void addition(vector <ll> v)
{
      for (int i=0 ; i<v.size(); i++){
            ll temp = ans[i]+v[i];

            if (temp >= 10){
                  ans[i] = temp-10;
                  ans[i+1]++;
            }
            else {
                  ans[i] = temp;
            }
      }
}

/*
 123

-321 - ans
 123 - v
-----
*802
-198 - ans
*/

void subtration(vector <ll> v)
{
      for (int i=0 ; i<30 ; i++){
            ll temp = ans[i] - v[i];

            if (temp<0){
                  temp+=10;
                  ans[i] = temp;

                  v[i+1]++;
            }
            else ans[i] = temp;
      }
}

bool greaterThan(vector <ll> v1 , vector <ll> v2)
{
      for (int i=29 ; i>=0 ; i--){
            if (v1[i]>v2[i])return true;
            if (v1[i]<v2[i])return false;
      }
      return true;
}

void bigAns(ll a)
{
      if (a==0)return;

      vector < ll > v;
      bool posi = true;

      for (int i=0 ; i <30 ; i++)v.push_back(0LL);

      if (a<0){
            posi = false;
            a *= -1;
      }

      ll id = 0;
      while(a){
            ll tut = a%10;
            a/=10;

            v[id] = tut;
            id++;
      }

      if (!greaterThan(ans,v)){
            vector < ll > tempV;
            tempV = ans;
            ans = v;
            v = tempV;

            swap(parity , posi);
      }

      if (parity != posi){
            subtration(v);
      }
      else {
            addition(v);
      }
}

void build(ll depth , ll b , ll e)
{
      if (b==e){
            S[depth][b] = A[b];
            C[depth][b] = A[b];

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

      C[depth][b] = S[depth][b];
      for (ll i = b+1 ; i<=e ; i++){
            C[depth][i] = C[depth][i-1] + S[depth][i];
      }

      return;
}

ll query(ll depth , ll b, ll e , ll x, ll y, ll val)
{
      if (b>y || e<x)return 0;

      if (b>=x && e<=y){
            ll _bg = b , _ed = e , id = e+1 , ret = 0;

            while(_bg <= _ed){
                  ll mid = (_bg+_ed) / 2;

                  if (S[depth][mid] >= val+2){
                        id = min(id, mid);
                        _ed = mid-1;
                  }
                  else _bg = mid+1;
            }

            if (id<e+1){
                  ll temp = 0;

                  if (id==b)temp = C[depth][e];
                  else temp = C[depth][e] - C[depth][id-1];

                  ret += temp - val*(e-id+1);
            }

            ///lower bound

            _bg = b , _ed = e , id = b-1;

            while(_bg <= _ed){
                  ll mid = (_bg+_ed) / 2;

                  if (S[depth][mid] <= val-2){
                        id = max(id,mid);
                        _bg = mid+1;
                  }
                  else _ed = mid-1;
            }

            if (id != b-1){
                  ll temp = C[depth][id];

                  ret += temp - val*(id-b+1);
            }

            return ret;
      }

      ll mid = (b+e)/2;

      return query(depth+1,b,mid,x,y,val) + query(depth+1,mid+1,e,x,y,val);
}

int main()
{
      scanf("%I64d",&n);

      for (ll i= 1 ; i<= n ; i++)scanf("%I64d",&A[i]);

      build(1,1,n);

      for (int i=0 ; i<30 ;i++)ans.push_back(0LL);

      for (ll i=1 ; i<n ; i++){
            bigAns(query(1,1,n,i+1,n,A[i]));
      }

      bool x = false , isZero = true;

      for (int i=0 ; i<30 ; i++)if (ans[i]!=0)isZero = false;

      if (isZero){
            cout << 0 << endl;
            return 0;
      }

      if (!parity)cout << "-";

      for (int i = 29 ; i>=0 ; i--){
            if (ans[i]!=0)x = true;

            if (x){
                  cout << ans[i];
            }
      }
      cout << endl;

      return 0;
}
