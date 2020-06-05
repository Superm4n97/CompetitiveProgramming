#include<bits/stdc++.h>
#define ll long long int
#define maxN 1000006
#define mod 1000000007

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

int main()
{
      CAT[0] = 1;
      CAT[1] = 1;

      for (int i=2 ; i<maxN-3 ; i++){
            CAT[i] = Multiplication(Normal(2*(2*i -1)),CAT[i-1]);
            CAT[i] = Multiplication(CAT[i] , modInverse(Normal(i+1)));
      }

      return 0;
}
