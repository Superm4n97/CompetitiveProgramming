#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[35][35] , D[3][35][35] , dis[100] , totalPath[100] , n,m;
ll dx[] = {0,0,1,-1} , dy[] = {1,-1,0,0};

bool check(ll x, ll y ,ll id)
{
      if (x>0 && x<=n && y>0 && y<=m && D[id][x][y]==-1)return true;
      return false;
}

void bfs(ll id)
{
      queue < pair < ll, ll > > q;

      if (id==1){
            D[1][1][1] = 0;
            q.push({1,1});
            //dis[0]+=A[1][1];
      }
      else {
            D[2][n][m] = 0;
            q.push({n,m});
            //dis[0]+=A[n][m];
      }
      //totalPath[0]++;

      while(!q.empty()){
            ll x = q.front().first , y = q.front().second;
            q.pop();

            for (int i=0;i<4;i++){
                  ll u = x+dx[i] , v = y+dy[i];

                  if (check(u,v,id)){
                        D[id][u][v] = D[id][x][y]+1;
                        q.push({u,v});
                  }
            }
      }
}

int main()
{
      int tc;

      cin >> tc;

      while(tc--){
            memset(D,-1,sizeof D);
            memset(dis,0,sizeof dis);
            memset(totalPath,0,sizeof totalPath);

            cin >> n >> m;

            for (int i=1 ; i<=n; i++){
                  for (int j=1 ; j<=m;j++){
                        cin >> A[i][j];
                  }
            }

            bfs(1);
            bfs(2);

            for (int i=1 ; i<=n;i++){
                  for (int j=1 ; j<=m;j++){
                        if (D[1][i][j] ==D[2][i][j])continue;
                        else{
                              dis[min(D[1][i][j],D[2][i][j])] += A[i][j];
                              totalPath[min(D[1][i][j],D[2][i][j])]++;
                        }
                  }
            }
            ll ans = 0;
            for (int i=0; i<12;i++){
                  ans+=min(dis[i],totalPath[i]-dis[i]);
                 // show(i);
                  //show(dis[i]);
                  //show(totalPath[i]);
            }
            cout << ans << endl;
      }

      return 0;
}
