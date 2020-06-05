#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector < ll > A,C , ans;
ll mark[30];

bool rec(ll pos , bool choto)
{
      //show(pos);
      if (pos == C.size())return true;

      for (int i=A.size()-1 ; i>=0 ;i--){
            if (choto && mark[i]==0){
                  mark[i] = 1;
                  bool temp = rec(pos+1,choto);

                  ans.push_back(A[i]);
                  return true;
            }
            if (A[i]<=C[pos] && mark[i] == 0){
                  mark[i] = 1;
                  bool x = false;

                  if (A[i]< C[pos])x = true;

                  if (rec(pos+1 , x)){
                        ans.push_back(A[i]);
                        return true;
                  }
                  else {
                        mark[i] = 0;

                        ll j = i;
                        while(A[j+1] == A[i])j++;
                        i = j;
                  }
            }
      }

      return false;
}

int main()
{
      ll a,b;
      cin >> a >> b;

      while(a){
            A.push_back(a%10);
            a/=10;
      }
      while(b){
            C.push_back(b%10);
            b/=10;
      }

      sort(A.begin() , A.end());
      reverse(C.begin() , C.end());

      if (A.size()<C.size()){
            for (int i = A.size()-1 ; i>=0 ; i--)cout << A[i];
            cout << endl;
            return 0;
      }

      show(A.size());
      for (int i=0 ; i<A.size();i++)cout << A[i];
      cout << endl;
      for (int i=0 ; i<C.size();i++)cout << C[i];
      cout << endl;

      for (int i=A.size()-1 ; i>=0 ; i--){
            if (A[i]<=C[0]){
                  mark[i] = 1;
                  bool x = false;
                  if (A[i]<C[0])x = true;

                  if (rec(1,x)){
                        ans.push_back(A[i]);
                        break;
                  }
                  else {
                        mark[i] = 0;

                        ll j = i;
                        while(A[j+1] == A[i])j++;
                        i = j;
                  }
            }
      }

      for (int i = ans.size()-1 ; i>=0 ; i--)cout << ans[i];
      cout << endl;

      return 0;
}
