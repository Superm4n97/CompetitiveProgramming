#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005

using namespace std;

vector < ll > Tree[maxn];
ll SP[maxn][30] , L[maxn] , P[maxn] , vis[maxn];
ll N;///number of nodes in Tree 1 based

void makeLCA(ll source)
{
      queue < ll > q;

      L[source] = 0;
      q.push(source);
      vis[source] = 1;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (int i=0; i<Tree[u].size() ; i++){
                  ll v = Tree[u][i];

                  if (!vis[v]){
                        L[v] = L[u]+1;
                        vis[v] = 1;
                        P[v] = u;
                        q.push(v);
                  }
            }
      }

      for (int i=1;i<=N;i++)///Nodes are 1 to N
            SP[i][0] = P[i];


      for (int j = 1 ; j<29 ; j++){
            for (int i = 1 ; i<= N ;i++){
                  SP[i][j] = SP[SP[i][j-1]][j-1];/// sparse table has additional data, here must be implemented
            }
      }

      return;
}

ll LCA(ll a, ll b)
{
      if (L[a]>L[b])swap(a,b);


      for (int i=28 ; i>=0 ; i--){
            if (L[b] - (1<<i) >= L[a]){
                  b = SP[b][i];
            }
      }


      if (b==a)return a;


      for (int i=28 ; i>= 0 ; i--){
            if (SP[a][i] != SP[b][i]){
                  a = SP[a][i];
                  b = SP[b][i];
            }
      }

      return P[a];
}

void Clean()
{
      for (int i=0;i<maxn-1;i++){
            Tree[i].clear() ;
            P[i] = i;
      }
      memset(SP,-1,sizeof SP);
      memset(L,0,sizeof L);
      memset(vis,0,sizeof vis);

      return;
}

int main()
{
      Clean();
      cin >> N;

      for (int i=1 ; i<N ; i++){
            ll a, b;
            cin >> a >> b;

            Tree[a].push_back(b);
            Tree[b].push_back(a);
      }

      makeLCA(1);

      while(1){
            ll a, b;
            cin >> a >> b;
            cout << LCA(a,b) << endl;
      }



      return 0;
}
