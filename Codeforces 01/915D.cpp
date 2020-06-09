#include<bits/stdc++.h>
#define ll long long int
#define maxn 505

using namespace std;

vector < ll > G[maxn];
ll n, m , inDegree[maxn], vis[maxn] , totalREM = 0 , IN[maxn];

ll backEdge(ll source)
{
      ll res = 0;

      queue < ll > q;
      q.push(source);

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            res++;

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];
                  if (v != source){
                        IN[v]--;

                        if (IN[v] == 0)q.push(v);
                  }
            }
      }
      return res;
}

int main()
{
      cin >> n >> m;
      for (int i=0 ; i<m; i++){
            ll a, b;
            cin >> a >> b;

            G[a].push_back(b);
            inDegree[b]++;
      }
      queue <ll> q;

      for (int i = 1 ; i<= n ; i++){
            if (inDegree[i]==0)q.push(i) , vis[i] = 1;
      }

      ll cnt = 0;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            cnt++;

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];

                  inDegree[v]--;
                  if (inDegree[v]==0)q.push(v) , vis[v] = 1;
            }
      }

      totalREM = n - cnt;

      if (totalREM == 0){
            cout << "YES" << endl;
            return 0;
      }

      bool solution = false;

      for (int i=1 ; i<= n ;i++){

            if (inDegree[i] == 1){
                  for (int i = 1 ; i<= n ;i++)IN[i] = inDegree[i];

                  if (backEdge(i) == totalREM){
                        solution = true;
                        //cout << "i : " << i << endl;
                        //break;
                  }
            }
      }

      cout << (solution?"YES":"NO") << endl;



      return 0;
}
