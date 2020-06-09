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
#define inf8            100000008
#define printCaseAnsInt(t,ans)  printf("Case %d: %d",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld",t,ans)
#define mod             1000000007
#define maxn            2000005;
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,k;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            string s ;
            cin >> s;

            int a[n+3], b[n+4];

            bool boro = false;

            for (int i=0;i<n;i++){
                  if (s[i]=='2'){
                        if (boro)a[i] = 0 , b[i] = 2;
                        else a[i] = 1 , b[i] = 1;
                  }
                  else if (s[i]=='0'){
                        a[i] = 0 , b[i] = 0;
                  }
                  else {
                        if (!boro){
                              a[i] = 1 , b[i] = 0;
                              boro = true;
                        }
                        else {
                              a[i] = 0 , b[i] = 1;
                        }
                  }
            }
            for (int i=0;i<n;i++)cout << a[i];
            cout << endl;
            for (int i=0;i<n;i++) cout << b[i];
            cout << endl;
      }





      return 0;
}
