#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

string text , pattern;
ll failure[maxn], n , m;

void buildFailure()
{
      failure[0] = failure[1] = 0;

      for (int i=2 ; i<=m ; i++){
            int j = failure[i-1];

            while(true){
                  if (pattern[j] == pattern[i-1]){
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

      int i = 0 , j = 0 , cnt = 0;

      while(true){
            if (i == n)return cnt;
            if (text[i] == pattern[j]){
                  i++ , j++;

                  if (j == m){
                        cnt++;
                        j = failure[j];
                  }
            }
            else {
                  if (j == 0)i++;
                  else j = failure[j];
            }
      }

      return cnt;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            cin >> text >> pattern;

            n = text.size();
            m = pattern.size();

            ll temp = KMP();

            printf("Case %d: %lld\n",_t,temp);
      }


      return 0;
}
