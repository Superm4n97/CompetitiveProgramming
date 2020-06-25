#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

ll n,p;

ll normal(ll a)
{
      ll temp = a/mod;
      return a - temp*mod;
}

ll bigmod(ll a, ll pw)
{
      if (pw==0)return 1;
      if (pw==1)return normal(a);

      ll temp = bigmod(a,pw/2);
      temp = normal(temp*temp);

      if (pw%2)temp = normal(temp*a);

      return temp;
}

bool check(ll s, ll k)
{
      ll temp = bigmod(p,k);
      ll inverse = bigmod(temp,mod-2);

      temp = normal(s*inverse);

      return temp;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            scanf("%I64d %I64d",&n,&p);
            vector < ll > v;

            for (int i=0 ; i<n;i++){

                  ll a;
                  scanf("%I64d",&a);
                  v.push_back(a);
            }

            if (p==1){

                  if (n%2)printf("1\n");
                  else printf("0\n");

                  continue;
            }

            sort(v.rbegin(),v.rend());

            ll s = 0 , u = 0 , x = 0;

            for (int i=0 ; i<n;i++){

                  if (s==0)s = bigmod(p,v[i]);
                  else {
                        if (x)s-=bigmod(p,v[i]);
                        else {
                              s-=bigmod(p,v[i]);
                              if (check(s,v[i])>n)x = 1;
                        }

                        if (s<0)s+=mod;
                  }
            }
            printf("%I64d\n",s);
      }


      return 0;
}
