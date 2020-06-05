#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector < ll > G[205];

int BinarySearch(int val, int u)
{
      if (G[u].empty())return 0;

      int b = 0 , e = G[u].size()-1 , res = -1;
      while(b<=e){
            int mid = (b+e)/2;

            if (G[u][mid] <= val){
                 b = mid+1;
                 res = max(res , mid);
            }
            else e = mid-1;
      }

      return res+1;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            for (int i=1;i<204; i++)G[i].clear();

            int n;
            scanf("%d",&n);

            for (int i=1 ; i<=n; i++){
                  int a;
                  scanf("%d",&a);
                  G[a].push_back(i);
            }

            int ans = 1;

            for (int i=1 ; i<= 200 ; i++){
                  if (G[i].empty())continue;

                  int x = 0 , y = G[i].size()-1;

                  while(x<y){
                        int id1 = G[i][x] , id2 = G[i][y];

                        for (int j=1 ; j<=200 ; j++){
                              int t1 = BinarySearch(id1,j) , t2 = BinarySearch(id2-1 , j);

                              int temp = ans;
                              ans = max(ans , 2*(x+1) + t2-t1);

                              /*if (ans!=temp){
                                    show(ans);
                                    show(i);
                                    show(id1);
                                    show(id2);
                                    show(j);
                                    show(t2);
                                    show(t1);
                              }*/
                        }

                        x++;
                        y--;
                  }
            }
            printf("%d\n",ans);
      }


      return 0;
}
