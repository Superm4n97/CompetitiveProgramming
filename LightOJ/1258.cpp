#include<bits/stdc++.h>
#define ll long long int
#define maxn 1000006
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s;
int n , failure[maxn];

void buildFailure()
{
      failure[0] = failure[1] = 0;

      for (int i = 2 ; i<=n ; i++){
            int j = failure[i-1];

            while(true){
                  if (s[j] == s[i-1]){
                        failure[i] = j+1;
                        break;
                  }
                  if (j == 0){
                        failure[i] = 0;
                        break;
                  }

                  j = failure[j];
            }
      }
}

ll KMP()
{
      buildFailure();

      int i = 0 , j = n-1;

      while(true){
            if (s[i] == s[j]){
                  if (i > j)return i*2;
                  if (i == j)return i*2+1;
                  i++ , j--;
            }
            else {
                  if (i == 0){
                        j--;
                        //if (i==j)return 1;
                  }
                  else i = failure[i];
            }
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            cin >> s;
            n = s.size();

            reverse(s.begin(), s.end());

            ll temp = KMP();

            printf("Case %d: %d\n",_t, s.size()+(s.size()-temp));
      }

      return 0;
}
