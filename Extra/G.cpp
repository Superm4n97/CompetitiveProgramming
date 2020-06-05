#include<bits/stdc++.h>
#define ll long long int
#define maxN 1000006
#define mod  100000007
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll CAT[maxN];

ll Normal(ll a)
{
      ll temp = a/mod;
      temp*=mod;

      a-=temp;

      if (a<0)a+=mod;

      return a;
}

ll Summation(ll a, ll b)
{
      a+=b;
      if (a >= mod)a-=mod;
      return a;
}

ll Substraction(ll a, ll b)
{
      a-=b;
      if(a<0)a+=mod;
      return a;
}

ll Multiplication(ll a, ll b)
{
      a*=b;
      ll temp = a/mod;
      temp*=mod;

      return a-temp;
}

ll bigMod(ll a, ll p)
{
      if (p==0)return 1;
      if (p==1)return a % mod;

      ll temp = bigMod(a,p/2);

      temp = Multiplication(temp,temp);

      if (p%2)temp = Multiplication(temp,a);

      return temp;
}

ll modInverse(ll a)
{
      return bigMod(a,mod-2);
}

map < ll , ll > mp;
vector < ll > v;

ll BS(ll a)
{
      ll b = 0 , e = v.size()-1 , ans = -1;

      while(b<=e){
            ll mid = (b+e)/2;

            if (v[mid] <= a){
                  ans = max(ans,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }

      return ans;
}

int main()
{
      CAT[0] = 0;
      CAT[1] = 1;

      for (int i=2 ; i<maxN-3 ; i++){
            CAT[i] = Multiplication(Normal(2*(2*i -1)),CAT[i-1]);
            CAT[i] = Multiplication(CAT[i] , modInverse(Normal(i+1)));
      }

      for (ll i=2 ; i<100005 ; i++){
            if (!mp[i]){
                  ll j = i*i;
                  while(j<10000000010){
                        if(!mp[j]){
                              v.push_back(j);
                              mp[j] = 1;
                        }
                        j*=i;
                  }
            }
      }
      sort(v.begin(),v.end());

      int tc;
      scanf("%d",&tc);

      for (int _t =1 ;_t<=tc ; _t++){
            ll a, b;
            scanf("%lld %lld",&a,&b);

            ll temp = BS(b) - BS(a-1);

            printf("Case %d: %lld\n",_t,CAT[temp]);
      }


      return 0;
}

