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

#define maxn            1000006

using namespace std;

char change(char ch)
{
      if (ch=='9')return '1';
      return ch+1;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            string s[12];
            for (int i=0;i<9;i++){
                  cin >> s[i];
            }


            s[0][0] = change(s[0][0]);
            s[1][3] = change(s[1][3]);
            s[2][6] = change(s[2][6]);

            s[3][1] = change(s[3][1]);
            s[4][4] = change(s[4][4]);
            s[5][7] = change(s[5][7]);

            s[6][2] = change(s[6][2]);
            s[7][5] = change(s[7][5]);
            s[8][8] = change(s[8][8]);

            for (int i=0 ; i<9 ;i++)cout << s[i] << endl;

      }




      return 0;
}
