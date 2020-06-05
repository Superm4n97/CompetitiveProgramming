#include<bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            10000000000000016
#define maxn            1000006
#define show(x) cout << #x << " : " << x << endl


using namespace std;


int main()
{
      ll tc;
      cin >> tc;
      for (int _t = 1 ; _t<=tc ;_t++){
            ll A[6][6];
            ll C[6][6];
            memset(A,0,sizeof A);
            memset(C,0,sizeof C);
            map < ll , ll > mp;

            for (int i=1;i<=4;i++){
                  for (int j=1;j<=4;j++){
                        cin >> A[i][j];
                        if (A[i][j] != -1)C[i][j] = 1;
                        mp[A[i][j]]++;
                  }
            }

            for (int i=1;i<=n;i++){
                  bool ok = false;

                  for (int j = 1 ; j<=16 ; j++){
                        if (C[i][1]){

                        }
                        else if (mp[j])continue;
                        else {
                              A[i][1] = j;
                              mp[j] = 1;
                        }

                        for (int k=1;k<=16 ; k++){
                              if (C[i][2]){

                              }
                              else if (mp[k])continue;
                              else {
                                    A[i][2] = k;
                                    mp[k] = 1;
                              }

                              for (int l  =1 ; l<=16 ; l++){
                                    if (C[i][3]){

                                    }
                                    else if (mp[l])continue;
                                    else {
                                          A[i][3] = l;
                                          mp[l] = 1;
                                    }

                                    for (int m = 1 ; m<=16 ; m++){
                                          if (C[i][4]){

                                          }
                                          else if (mp[m])continue;
                                          else {
                                                A[i][1] = m;
                                                mp[m] = 1;
                                          }
                                          ///*************************

                                          if (A[i][1]+A[i][2]+A[i][3]+A[i][4]==34){
                                                ok = true;
                                          }
                                          else mp[m] = 0
                                    }

                                    if (ok)break;
                                    else {

                                    }
                              }
                        }
                  }
            }
      }



      return 0;
}
