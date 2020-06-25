#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 60

using namespace std;

string s , t;
vector < ll > G[maxn] , level[maxn];
ll A[maxn] , m , mp[30];

void clean()
{
      for (int i=0 ; i<60 ; i++){
            G[i].clear();
            level[i].clear();
      }
      memset(A,0,sizeof A);
      memset(mp,0,sizeof mp);
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            clean();

            cin >> s;
            cin >> m;
            for (int i=0;i<m;i++)cin >> A[i];

            for (int i=0;i<s.size();i++){
                  mp[s[i]-'a']++;
            }

            t = s;

            ll lv = 1;


            for (int i=0;i<m;i++){
                  vector < ll > v;
                  //v.clear();
                  for (ll j=0 ; j<m;j++){
                        //show(A[j]);
                        if (A[j] == 0){
                              level[lv].push_back(j);
                              v.push_back(j);
                        }
                  }
                  lv++;

                  for (int j=0 ; j<v.size();j++){
                        ll id = v[j] ,  temp = 1;
                        //show(id);
                        A[id] = -1;
                        for (int k = id-1 ; k>=0 ; k--){
                              A[k]-=temp;
                              temp++;
                        }

                        temp = 1;

                        for (int k=id+1 ; k<m; k++){
                              A[k]-=temp;
                              temp++;
                        }
                  }
            }
            //show(lv);
            ll c = 25;

            for (int l = 1 ; l<lv ; l++){
                  while(mp[c]<level[l].size()){
                        c--;
                  }
                  for (int i=0 ; i<level[l].size() ; i++){
                        s[level[l][i]] = 'a'+c;
                  }
                  c--;
            }
            for (int i=0;i<m;i++)cout << s[i];
            cout << endl;
      }

      return 0;
}
