#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll mod;

struct MAT
{
      ll ar[5][5];
};

ll arithmaticMultiplication(ll a, ll b)
{
      a*=b;

      //return a%mod;

      ll temp = a/mod;

      a -= (temp*mod);

      return a;
}

ll arithmaticAddition(ll a, ll b)
{
      a+=b;

      //return a%mod;

      ll temp = a/mod;

      a -= (temp*mod);

      return a;
}

MAT matricsMultiplication(MAT X, MAT Y)
{
      MAT A;
      A.ar[0][0] = arithmaticAddition( arithmaticMultiplication( X.ar[0][0],Y.ar[0][0]) , arithmaticMultiplication( X.ar[0][1],Y.ar[1][0]));
      A.ar[0][1] = arithmaticAddition( arithmaticMultiplication( X.ar[0][0],Y.ar[0][1]) , arithmaticMultiplication( X.ar[0][1],Y.ar[1][1]));

      A.ar[1][0] = arithmaticAddition( arithmaticMultiplication( X.ar[1][0],Y.ar[0][0]) , arithmaticMultiplication( X.ar[1][1],Y.ar[1][0]));
      A.ar[1][1] = arithmaticAddition( arithmaticMultiplication( X.ar[1][0],Y.ar[0][1]) , arithmaticMultiplication( X.ar[1][1],Y.ar[1][1]));

      return A;
}

MAT matricsExpo(MAT M , ll p)
{
      if (p==1)return M;

      MAT X = matricsExpo(M,p/2);
      X = matricsMultiplication(X,X);

      if (p%2){
            X = matricsMultiplication(X,M);
      }

      return X;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll a,b,n,m;
            scanf("%lld %lld %lld %lld",&a,&b,&n,&m);

            mod = 1;

            for (int i=1; i<=m ; i++)mod*=10;

            MAT A;
            A.ar[0][0] = a;
            A.ar[1][0] = b;
            A.ar[0][1] = A.ar[1][1] = 0;

            MAT B;
            B.ar[0][0] = 1;
            B.ar[1][0] = 1;
            B.ar[0][1] = 1;
            B.ar[1][1] = 2;

            MAT RES = matricsExpo(B,n/2);
            RES = matricsMultiplication(RES,A);

            ll ans;

            if (n%2)ans = RES.ar[1][0];
            else ans = RES.ar[0][0];

            printf("Case %d: %lld\n",_t,ans);


      }


      return 0;
}
