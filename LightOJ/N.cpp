#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define maxn 1000006
#define inf 10000000000000016

using namespace std;

map < string , ll > mpId ;
map < ll , string > mpSt;

string s;

ll n,m,A[105] , B[105] , cnt=0;
ll dp[105][105];

void clean()
{
      cnt = 0;
      mpId.clear();
      mpSt.clear();
}

int main()
{
      ll i = 0 , temp = 0;
      while(cin >> s){
            if (s=="#"){
                  temp++;
                  if (temp==1){
                        n = i;
                  }
                  if (temp==2){
                        m = i;

                        memset(dp,-1,sizeof dp);

                        for (int i=1;i<=n;i++)cout << A[i] << " ";
                        cout << endl;

                        for (int i=1;i<m;i++)cout << B[i]  << " ";
                        cout << endl;

                        temp = 0;
                        clean();
                  }
                  i = 0;
            }
            else {
                  i++;
                  if (mpId[s]==0){
                        cnt++;
                        mpId[s] = cnt;
                        mpSt[cnt] = s;
                  }

                  if (temp==0)A[i] = mpId[s];
                  else B[i] = mpId[s];
            }
      }


      return 0;
}
