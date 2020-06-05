#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll C[15] , a , b;
vector < ll > A,B , ans;

bool rec(ll pos, bool choto)
{
      if (pos==B.size())return true;
      for (int i = 9 ; i>=0 ; i--){
            if (C[i]){
                  if (choto){
                        C[i]--;
                        ll tut = rec(pos+1,choto);
                        ans.push_back(i);

                        return true;
                  }
                  else if (i<=B[pos]){
                        bool temp = false;

                        if (i<B[pos])temp = true;

                        C[i]--;

                        if (rec(pos+1 , temp)){
                              ans.push_back(i);
                              return true;
                        }
                        C[i]++;
                  }
            }
      }
      return false;
}

int main()
{
      cin >> a >> b;

      while(a){
            C[a%10]++;
            A.push_back(a%10);
            a /= 10;
      }
      while(b){
            B.push_back(b%10);
            b/=10;
      }
      reverse(B.begin() , B.end());

      if (A.size()<B.size()){
            for (int i=9 ; i>=0 ; i--){
                  for (int j = 1 ; j<=C[i] ; j++)cout << i;
            }
            cout << endl;
            return 0;
      }

      for (int i=9 ; i>=0 ; i--){
            if (C[i]>0 && i<=B[0]){
                  bool temp = false;

                  if (i<B[0])temp = true;

                  C[i]--;

                  if (rec(1,temp)){
                        ans.push_back(i);
                        break;
                  }
                  C[i]++;
            }
      }
      for (int i=ans.size()-1 ; i>=0 ; i--)cout << ans[i];
      cout << endl;
}
