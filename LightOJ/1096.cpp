#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod  10007

using namespace std;

struct Mat
{
      ll row , col , M[10][10];
      Mat(){
           row = col = 0;
           memset(M,0,sizeof M);
      }
      Mat(ll a, ll b){
            row = a , col = b;
            memset(M,0,sizeof M);
      }
};

Mat matricsMultiplication(Mat A, Mat B)
{
      Mat RES = Mat(A.row , B.col);
      for (int i=0 ; i<RES.row ; i++){
            for (int j = 0 ; j <RES.col ; j++){

                  ll sum = 0;
                  for (int k  = 0 ; k<A.col ; k++){
                        ll temp = A.M[i][k]*B.M[k][j];
                        temp %= mod;

                        sum+=temp;
                        sum%=mod;
                  }
                  RES.M[i][j] = sum;

            }
      }

      return RES;
}

Mat bigMod(Mat A , ll p)
{
      if (p==1)return A;

      Mat B = bigMod(A,p/2);

      B = matricsMultiplication(B,B);

      if (p%2)B = matricsMultiplication(B,A);

      return B;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t =1 ;_t<=tc ; _t++){
            ll n,a,b,c;
            scanf("%lld %lld %lld %lld",&n,&a,&b,&c);

            a%=mod;
            b%=mod;
            c%=mod;

            Mat base = Mat(4,1);
            base.M[3][0] = c;

            ll ans;

            if (n<3){
                  printf("Case %d: 0\n",_t);
                  continue;
            }

            Mat con = Mat(4,4);
            con.M[0][3] = con.M[3][3] = 1;
            con.M[0][1] = con.M[3][0] = con.M[3][1] = con.M[3][2] = 0;
            con.M[0][0] = con.M[1][1] = b;
            con.M[0][2] = a;
            con.M[1][0] = con.M[2][1] = (a*b)%mod;
            con.M[1][2] = (a*a)%mod;
            con.M[1][3] = (a+1)%mod;
            con.M[2][0] = (a*a*b)%mod;
            con.M[2][2] = (a*a*a+b)%mod;
            con.M[2][3] = (a*a + a + 1)%mod;

            con = bigMod(con,n/3);
            base = matricsMultiplication(con,base);

            ans = base.M[n%3][0];

            printf("Case %d: %lld\n",_t,ans);
      }


      return 0;
}
