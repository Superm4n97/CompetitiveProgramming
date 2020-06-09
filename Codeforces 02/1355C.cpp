#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll A,B,C,D , ans = 0;

int main()
{
      cin >> A >> B >> C >> D;
      for (int i=B ; i<=C ; i++){
            ll x = C+1 - i , y = D+1 - i;

            if (x>B)continue;
            else if (y<=A){
                  ans += (B-A+1)*(D-C+1);
            }
            else {
                  if (x<=A && y>=B){
                        ll t1 = (A-x)*(B-A+1) , t2 = (B-A+1)*(B-A+2)/2;
                        ans+=t1+t2;
                  }
                  else if (x>=A && y<=B){
                        ans+=(y-x+1)*(y-x+2)/2;
                  }
                  else {

                  }
            }
      }


      return 0;
}
