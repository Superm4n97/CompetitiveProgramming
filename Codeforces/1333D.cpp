#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            3003

using namespace std;

ll n,k;
string s;

vector < ll > G[maxn];

int main()
{
      cin >> n >> k;
      cin >> s;

      ll mv = 0 , sum = 0;

      while(1){
            for (int i=0;i<n-1;i++){
                  if (s[i] == 'R' && s[i+1]=='L'){
                        G[mv].pb(i+1);
                        swap(s[i],s[i+1]);
                        i++;
                  }
            }
            if (G[mv].empty())break;
            mv++;

            sum += G[mv-1].size();
      }

//      show(mv);
//      show(k);
//      show(sum);

      if(k<mv || k>sum){
            cout << -1 << endl;
      }
      else {
            for (int i=0;i<mv;i++){
                  if (k>mv-i){
                        for (int j=0 ; j<G[i].size();j++){
                              if (mv-i == k){
                                    //cout << G[i].size() - j << " ";
                                    printf("%I64d ",(ll)G[i].size() - j);
                                    for (;j<G[i].size();j++)printf("%I64d ",G[i][j]);
                                    printf("\n");
                                    k--;

                                    break;
                              }
                              //    cout << 1 << " " << G[i][j] << endl;
                              printf("1 %I64d\n",G[i][j]);
                              k--;
                        }
                  }
                  else {
                        //cout << G[i].size() << " ";
                        printf("%I64d ",(ll)G[i].size());
                        for (int j=0;j<G[i].size();j++)printf("%I64d ",G[i][j]);
                        //cout << endl;
                        printf("\n");

                        k--;
                  }
            }
      }





      return 0;
}
